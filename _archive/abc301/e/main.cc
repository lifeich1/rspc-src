#include <bits/stdc++.h>

#define CONSTEXPR14 constexpr
// Placeholder for upcoming un-std algorithm, by rspc
namespace A {
template <class T>
struct Point2d {
    typedef Point2d Pn;
    T x, y;
    Point2d() {}
    Point2d(T x, T y): x(x), y(y) {}
    inline T mdis(const Point2d& other) {
        return std::abs(x - other.x) + std::abs(y - other.y);
    }
    inline bool near(const Point2d& other, T th = 1) {
        return this->mdis(other) <= th;
    }
    Pn operator+ (const Pn & rhs) const { return {x + rhs.x, y + rhs.y}; }
    CONSTEXPR14 bool operator< (Point2d const & rhs) const {
        return this->x < rhs.x || (this->x == rhs.x && this->y < rhs.y);
    }
    CONSTEXPR14 bool operator== (Point2d const & rhs) const {
        return this->x == rhs.x && this->y == rhs.y;
    }
    struct YXLess {
        CONSTEXPR14 bool operator()(Point2d const & lhs, Point2d const & rhs) {
            return lhs.y < rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x);
        }
    };
};
template <class CharT, class T>
std::basic_istream<CharT> & operator>>(std::basic_istream<CharT> &s, Point2d<T> & value) {
    return s >> value.x >> value.y;
}
template <class CharT, class T>
std::basic_ostream<CharT> & operator<<(std::basic_ostream<CharT> &s, Point2d<T> const & value) {
    return s << value.x << ' ' << value.y;
}
}
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: 4 point2d

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
#define TRACELN(...) TRACE(__VA_ARGS__; cout << endl)
#define TRACE_VEC(VEC, ITEM, ...) TRACE(cout << #VEC << "= "; for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
using namespace std;
#define self_todo_placeholder

typedef A::Point2d<int> Pn;

const int H = 303;
Pn lis[H*H];
int bv[H][H];

int f[20][1<<18];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int h, w, T; cin >> h >> w>>T;
    vector<string> mp;mp.reserve(h);
    copy_n(std::istream_iterator<std::string>(cin), h, std::back_inserter (mp) );
    vector<Pn> can; Pn S, G;
    for (int i = 0; i < h; ++i)  {
        for (int j = 0; j < w; ++j)  {
            if (mp[i][j] == 'o') {
                can .emplace_back (i, j);
            } else if(mp[i][j] == 'S') {
                S = Pn{i,j};
            } else if (mp[i][j] == 'G') {
                G = Pn{i,j};
            }
        }
    }
    auto bfs = [&]( int sx, int sy) {
        for (int i = 0; i < h; ++i) fill(bv[i],bv[i]+w,-1);
        bv[sx][sy] = 0;
        int tt = 1;
        lis[0] = Pn{sx, sy};
        auto ta = [&]( int x, int y, int v) {
            if (x<0||x>=h||y<0||y>=w) return;
            if (mp[x][y] != '#' && bv[x][y] <0) {
                bv[x][y]=v;
                lis[tt++] = Pn{x, y};
            }
        };
        for (int i = 0; i < tt; ++i) {
            const auto &p = lis[i];
            auto [x, y] = p;
            auto v = bv[x][y]+1;
            ta(x-1, y, v);
            ta(x+1, y, v);
            ta(x, y-1, v);
            ta(x, y+1, v);
        }
    };
    vector<int> vs, vg; vs.resize(can.size()+1);
vg.resize(can.size()+1);
    bfs(S.x, S.y);
    for (int i = 0; i < can.size(); ++i) vs[i] = bv[can[i].x][can[i].y];
    vs.back() = bv[G.x][G.y];
    if (vs.back() > T || vs.back() < 0) {
        cout <<"-1\n";
        return 0;
    }
    bfs(G.x, G.y);
    for (int i = 0; i < can.size(); ++i) vg[i] = bv[can[i].x][can[i].y];
    vector<vector<int>> co;
    co.resize(can.size());
    for (int i = 0; i < can.size();++i) {
        auto [x, y] = can[i];
        bfs(x, y);
        for (int j = 0; j < can.size(); ++j) {
        auto [x, y] = can[j];
            co[i] .emplace_back (bv[x][y]);
        }
    }
    for (int i = 0; i < can.size();++i) f[i][1<<i] = vs[i];
    int M = (1<<can.size());
    int ans = 0;
    for (int mask = 1; mask < M; ++mask) {
        for (int i = 0; i < can.size(); ++i) {
            int v = f[i][mask];
            if (v <= 0||v>T) continue;
            if (v+vg[i]<=T) {
                ans = max(ans, __builtin_popcount(mask));
            }
            for (int j = 0; j < can.size();++j) {
                if (co[i][j] < 0) continue;
                int b = 1<<j;
                if(b&mask) continue;
                auto &vv = f[j][b|mask];
                auto t = v+co[i][j];
                if (vv==0 || vv > t) vv = t;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

