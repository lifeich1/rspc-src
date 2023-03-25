#include <cmath>
#include <iosfwd>
#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
#if __cplusplus >= 201402L
# define CONSTEXPR14 constexpr
#else
# define CONSTEXPR14
#endif

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
// Scheme by rspc: constexpr14 point2d

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
char c[32][32];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> c[i];
    vector<pair<Pn,int>> b;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            if (c[i][j] >= '1' && c[i][j] <= '9') {
                b.emplace_back(Pn(i, j), c[i][j] - '0');
            }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ('#' == c[i][j]) {
                Pn p{i, j};
                bool cl = any_of(b.begin(), b.end(),
                        [&](pair<Pn, int> t) { return t.first.near(p, t.second); });
                if (cl) c[i][j] = '.';
            } else c[i][j] = '.';
        }
    }
    copy_n(c, n, std::ostream_iterator <char*>(cout, "\n"));
    return 0;
}

