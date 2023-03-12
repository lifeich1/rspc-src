#include <istream>
#include <tuple>
template <class CharT, class Traits, class... Ts, size_t... Is>
void _read_tuple( std::basic_istream<CharT, Traits>& is, std::tuple<Ts...> & t, std::index_sequence<Is...>) {
    ((is >> std::get<Is>(t)), ...);
}

template <class CharT, class Traits, class... Ts>
std::basic_istream<CharT, Traits>& operator>>( std::basic_istream<CharT, Traits>& is, std::tuple<Ts...> & t) {
    return _read_tuple(is, t, std::index_sequence_for<Ts...>{}), is;
}
#include <array>
#include <cstring>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>

#define DENSE_NET__MULTI_EDGE 1

// Placeholder for upcoming un-std algorithm, by rspc

// Net describe facility
//  - edges(): get slist-like one node edges travel facility
//  - *edges()::Iter = std::pair(dst_node_index, &edge_desc)
//  - link(p0, p1[, v]): add bidirectional edge
//  - arrow(src, dst[, v]): add directional edge

namespace A {
template <std::size_t N, class Trait>
class DenseNet {
public:
    typedef typename Trait::edge_type edge_type;

    DenseNet() { clear(); }

    void clear() {
        std::fill(a.begin(), a.end(), Trait::EDGE_DEFAULT);
    }

    template <class Index>
    inline void arrow(Index src, Index dst, edge_type const & v) {
#ifdef DENSE_NET__MULTI_EDGE
        auto p = ei(src, dst);
        if (Trait::EDGE_DEFAULT == a[p] || Trait::edge_update(a[p], v))
#endif
        a[ei(src, dst)] = v;
    }
    template <class Index>
    inline void arrow(Index src, Index dst) {
        this->arrow(src, dst, Trait::EDGE_SET_VALUE);
    }

    template <class Index>
    inline void link(Index p0, Index p1, edge_type const & v) {
        this->arrow(p0, p1, v);
        this->arrow(p1, p0, v);
    }
    template <class Index>
    inline void link(Index p0, Index p1) {
        this->link(p0, p1, Trait::EDGE_SET_VALUE);
    }

    template <class Edge> class EdgeListImpl;

    template <class Edge>
    class EdgeIterImpl {
    public:
        typedef EdgeIterImpl type;

        typedef std::pair<std::size_t, Edge *> value_type;
        typedef std::forward_iterator_tag iterator_category;
        typedef value_type & reference;
        typedef int difference_type;
        typedef type pointer;

        value_type const & operator*() const { return p; }
        const value_type * operator->() const { return &p; }

        type & operator++() { nx(); return *this; }
        type operator++(int) { type t = *this; nx(); return t; }

        bool operator==(type const & other) const { return p.second == other.p.second; }
        bool operator!=(type const & other) const { return p.second != other.p.second; }
    private:
        friend class EdgeListImpl<Edge>;

        EdgeIterImpl(Edge * p, Edge * ed)
            : p{p - (ed - N), p}, ed{ed}
        {
            if (*p == Trait::EDGE_DEFAULT) nx();
        }

        void nx() {
            if (p.second != ed) {
                do {
                    ++p.second, ++p.first;
                } while (p.second != ed && *p.second == Trait::EDGE_DEFAULT);
            }
        }

        value_type p;
        Edge * const ed;
    };

    template <class Edge>
    class EdgeListImpl {
    public:
        typedef EdgeIterImpl<Edge> Iter;
        Iter begin() const { return bg; }
        Iter end() const { return ed; }
    private:
        friend class DenseNet;

        explicit EdgeListImpl(Edge * bg)
            : bg(bg, bg + N), ed(bg + N, bg + N) {}

         const Iter bg, ed;
    };

    typedef EdgeListImpl<edge_type> edge_slist;
    typedef EdgeListImpl<const edge_type> const_edge_slist;
    typedef typename edge_slist::Iter::value_type iter_output;
    typedef typename const_edge_slist::Iter::value_type const_iter_output;

    template <class Index>
    edge_slist edges(Index i) {
        return edge_slist(&a[ei(i, static_cast<Index>(0))]);
    }

    template <class Index>
    const_edge_slist edges(Index i) const {
        return const_edge_slist(&a[ei(i, static_cast<Index>(0))]);
    }

private:
    template <class Index>
    inline static std::size_t ei(Index src, Index dst) {
        return src * N + dst;
    }

    std::array<edge_type, N * N> a;
};

} // namespace A


namespace A {
/// Edge value: Trait::edge_value(edge_type *)
template <std::size_t N, class Net, class Trait>
struct Floyd {
    typedef typename Trait::edge_value_t edge_value_t;

    Net *net;
    int flag[N][N], flag_cur;
    edge_value_t f[N][N];

    explicit Floyd(Net *net): net{net}, flag_cur{1}
    {
        std::memset(flag, 0, sizeof(int) * N * N);
    }

    inline bool reach(int i, int j) const { return flag[i][j] == flag_cur; }

    void operator() (int n) {
        ++ flag_cur;
        for (int i = 0; i < n; flag[i][i] = flag_cur, f[i][i] = 0, ++i)
            for (auto const & [v, e] : net->edges(i)) {
                flag[i][v] = flag_cur;
                f[i][v] = Trait::edge_value(e);
            }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (flag[i][k] != flag_cur) continue;
                for (int j = 0; j < n; ++j) {
                    if (flag[k][j] != flag_cur) continue;
                    auto t = f[i][k] + f[k][j];
                    if ((flag[i][j] != flag_cur && (flag[i][j] = flag_cur, true))
                            || f[i][j] > t) f[i][j] = t;
                }
            }
        }
    }
};
}

#ifndef NETWORK_V_TRAIT__UPD_LESS
#define NETWORK_V_TRAIT__UPD_LESS 1
#endif

namespace A {
template <class T, std::size_t DEF_V = 0, std::size_t SET_V = 1>
struct NetworkVTrait {
    typedef T edge_type;
    typedef T edge_value_t;

    inline static edge_value_t const & 
    edge_value(edge_type const * e) { return *e; }

    inline static bool edge_update(edge_type const & a, edge_type const & b) {
#if NETWORK_V_TRAIT__UPD_LESS
        return b < a;
#else
        return b > a;
#endif
    }

    static const edge_type EDGE_DEFAULT;
    static const edge_type EDGE_SET_VALUE;
};

template <class T, std::size_t DEF_V, std::size_t SET_V>
const typename NetworkVTrait<T, DEF_V, SET_V>::edge_type
NetworkVTrait<T, DEF_V, SET_V>::EDGE_DEFAULT = T(DEF_V);

template <class T, std::size_t DEF_V, std::size_t SET_V>
const typename NetworkVTrait<T, DEF_V, SET_V>::edge_type
NetworkVTrait<T, DEF_V, SET_V>::EDGE_SET_VALUE = T(SET_V);
}
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: dense_net floyd network_v_trait

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
using namespace std;
#define self_todo_placeholder

const int N = 808;
typedef A::NetworkVTrait<int64_t> Trait;
typedef A::DenseNet<N, Trait> Nw;
typedef A::Floyd<N, Nw, Trait> Floyd;

array<int, N> w;
array<pair<int,int>, N> sw;
Nw nw;
Floyd floyd{&nw};
int64_t f[N], fr[N];

using namespace std::placeholders;
int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt;
    while (tt--) {
        int n, m, P; cin >> n >> m >> P;
        nw.clear();
        copy_n(std::istream_iterator<int>(cin), n, w.begin() + 1);
        for (int i = 0, x, y, v; i < m; ++i) {
            cin >> x >> y >> v;
            nw.arrow(x, y, v);
        }
        floyd(n + 1);
        if (!floyd.reach(1, n)) {
            cout << "-1\n";
            continue;
        }
        auto const & df = floyd.f;
        TRACE(cout << ' ' << df[1][n] << endl);
        {
            int i = 0;
            transform(w.begin() + 1, w.begin() + n + 1,
                    sw.begin(), [&i](int x) -> pair<int,int> { return { x, ++i }; });
            sort(sw.begin(), sw.begin() + n);
        }
        auto cal = [&](int s, int d, int64_t p) -> pair<int64_t, int64_t> {
            auto c = df[s][d];
            if (c <= p) return { 0, p - c };
            auto i = (c - p - 1) / w[s] + 1;
            return { i, p - c + i * w[s] };
        };
        int64_t ans = -1;
        for (int i = 0; i < n; ++i) {
            auto y = sw[i].second;
            if (!floyd.reach(1, y)) continue;
            tie(f[i], fr[i]) = cal(1, y, P);
            for (int j = 0; j < i; ++j) {
                auto x = sw[j].second;
                if (!floyd.reach(1, x) || !floyd.reach(x, y)) continue;
                auto [c, r] = cal(x, y, fr[j]);
                c += f[j];
                if (c < f[i]) f[i] = c, fr[i] = r;
            }
            if (floyd.reach(y, n)) {
                auto [c, r] = cal(y, n, fr[i]);
                c += f[i];
                if (-1 == ans || c < ans) ans = c;
            }
            TRACE(cout << ',' << y << ' ' << f[i] << ' ' << fr[i] << endl);
        }
        cout << ans << endl;
    }
    return 0;
}

