#include <vector>
#include <array>
#include <bits/stdc++.h>

#define POSTORDER_TRAVEL__NOEDGEEXT

// Placeholder for upcoming un-std algorithm, by rspc

#if 0
#define POSTORDER_TRAVEL__S_TREEM
#define POSTORDER_TRAVEL__S_PAPA
#define POSTORDER_TRAVEL__NOEDGEEXT
#endif

namespace A {
template <std::size_t N, class Net>
class PostorderTravel {
public:
    typedef std::size_t vertex_t;

    explicit PostorderTravel(Net * net
#ifdef POSTORDER_TRAVEL__S_TREEM
            , Net * tree
#endif
#ifdef POSTORDER_TRAVEL__S_PAPA
            , std::vector<std::size_t> * papa
#endif
            ): net{net}
#ifdef POSTORDER_TRAVEL__S_TREEM
            , tree{tree}
#endif
#ifdef POSTORDER_TRAVEL__S_PAPA
            , papa{papa}
#endif
    {
        std::fill(flag.begin(), flag.end(), cur);
    }

#ifdef POSTORDER_TRAVEL__S_PAPA
# define SET_PA(A, B) set_pa(A, B)
#else
# define SET_PA(A, B)
#endif
#ifdef POSTORDER_TRAVEL__S_TREEM
# define TR_AR(A, B) tree->arrow(A, B)
#else
# define TR_AR(A, B)
#endif
    template <class Index, class OutputIt>
    void operator() (Index src, OutputIt d_first) {
        stk[0] = src;
        int p = 0;
        flag[src] = ++cur;
        SET_PA(src, src);
        while (p >= 0) {
            const auto lp = p;
            auto x = stk[p];
#ifdef POSTORDER_TRAVEL__NOEDGEEXT
            for (auto const & v : net->edges(x)) {
#else
            for (auto const & [v, e] : net->edges(x)) {
#endif
                if (cur != flag[v]) {
                    flag[v] = cur;
                    stk[++p] = v;
                    SET_PA(v, x);
                    TR_AR(x, v);
                }
            }
            if (lp == p) {
                --p;
                *(d_first++) = x;
            }
        }
    }
#undef SET_PA
#undef TR_AR
private:
#ifdef POSTORDER_TRAVEL__S_PAPA
    inline void set_pa(vertex_t v, vertex_t pa) {
        if (papa->size() <= v) papa->resize(v + 1);
        papa->at(v) = pa;
    }
#endif

    Net * net;
#ifdef POSTORDER_TRAVEL__S_TREEM
    Net * tree;
#endif
#ifdef POSTORDER_TRAVEL__S_PAPA
    std::vector<vertex_t> * papa;
#endif
    std::array<int, N> flag;
    std::array<vertex_t, N> stk;
    int cur = 0;
};
}


namespace A {
template <class T>
struct VecArrNet {
    typedef std::vector<T> vec;
    typedef vec * vec_arr;

    vec_arr arr;

    VecArrNet(vec_arr arr): arr{arr} {}
    template <class Ind> vec & edges(Ind i) { return arr[i]; }
    template <class Ind> vec const & edges(Ind i) const { return arr[i]; }
};

template <class T>
VecArrNet<T> net(std::vector<T> arr[]) { return {arr}; }
}
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: postorder_travel vec_arr_net

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
#define TRACELN(...) TRACE(__VA_ARGS__; cout << endl)
#define TRACE_VEC(VEC, ITEM, ...) TRACE(cout << #VEC << "= "; for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
using namespace std;
#define self_todo_placeholder

const int N = 101001;
const int NSQ = 400;
int a[N], pa[N], xs[N], ys[N], depth[N], laycnt[N], laypos[N], pota[N];
int64_t mm[N][NSQ];
vector<int> es[N];
auto nw = A::net(es);
A::PostorderTravel<N, decltype(nw)> pt{&nw};

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, Q; cin >> n >> Q;
    copy_n(std::istream_iterator<int> (cin), n, a);
    copy_n(std::istream_iterator<int> (cin), n - 1, pa + 1);
    pa[0] = -1;
    for_each(pa + 1, pa + n + 1, [](int & x) { x--; });
    for (int i = 1; i < n; ++i) es[pa[i]].push_back(i);
    pt(0, pota);
    for (int i = n - 2; i >= 0; --i) {
        const auto x = pota[i];
        depth[x] = depth[pa[x]] + 1;
        laypos[x] = laycnt[depth[x]]++;
    }
    TRACELN(cout << "traveled");

    auto vis = [&](int x, int y) -> int64_t {
        if (laycnt[depth[x]] >= NSQ) return -1;
        return mm[x][laypos[y]];
    };
    auto upd = [&](int x, int y, int64_t v) {
        if (laycnt[depth[x]] >= NSQ) return;
        mm[x][laypos[y]] = mm[y][laypos[x]] = v;
    };

    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int l = 0;
        int64_t ans = 0;
        for (; x != -1; x = pa[x], y = pa[y]) {
            auto v = vis(x, y);
            if (v > 0) {
                TRACELN(cout << "^" << x << ' ' << y);
                ans = v; break;
            }
            ys[l] = y, xs[l++] = x;
            TRACELN(cout << '.' << x << ' ' << y);
        }
        while (l-- > 0) {
            const auto x = xs[l], y = ys[l];
            ans += int64_t(a[x]) * a[y];
            upd(x, y, ans);
            TRACELN(cout << ':' << x << ' ' << y  << ' ' << ans);
        }
        cout << ans << endl;
    }

    return 0;
}

