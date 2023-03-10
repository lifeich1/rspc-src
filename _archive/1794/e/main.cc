#include <iostream>
#include <utility>
#include <functional>
#include <type_traits>
#include <tuple>
#include <vector>
#include <cstdint>
#include <array>
#include <algorithm>
#include <bits/stdc++.h>

#define POSTORDER_TRAVEL__S_TREEM
#define POSTORDER_TRAVEL__S_PAPA
// Placeholder for upcoming un-std algorithm, by rspc


namespace A {

template <class T>
inline constexpr T qpow_in_mod(T base, T ind, T m) {
    T res = 1;
    for (T bi = base; ind > 0; ind >>= 1, bi = (bi * bi) % m)
        if (ind & 1) res = (res * bi) % m;
    return res;
}

template <int64_t M, class T = int64_t>
class CalcInMod {
public:
    typedef T data_t;

    T v;

    CalcInMod() {}
    CalcInMod(int v): v{static_cast<T>(v)} {}
    CalcInMod(T v): v{v} {}

    int as_i() { return static_cast<int>(v); }

    using type = CalcInMod<M, T>;

    inline static T add(T a, T b) { return (a + b) % M; }
    inline static T sub(T a, T b) { return (a - b + M) % M; }
    inline static T mul(T a, T b) { return (a * b) % M; }
    inline static T qpow(T base, T ind) {
        T res = 1;
        for (T bi = base; ind > 0; ind >>= 1, bi = mul(bi, bi))
            if (ind & 1) res = mul(res, bi);
        return res;
    }

    inline type operator+ (type const & a) const { return {(a.v + v) % M}; }
    inline type operator- (type const & a) const { return {(v - a.v + M) % M}; }
    inline type operator* (type const & a) const { return {(a.v * v) % M}; }
    inline type & operator+= (type const & a) { *this = *this + a; return *this; }
    inline type & operator-= (type const & a) { *this = *this - a; return *this; }
    inline type & operator*= (type const & a) { *this = *this * a; return *this; }
    inline type mul_inv() const { return {qpow(M - 2)}; }
    inline type qpow(T ind) const { return {qpow(v, ind)}; }

    inline bool operator== (type const & a) const { return v == a.v; }
    inline bool operator< (type const & a) const { return v < a.v; }
};
}


namespace A {
template <class T = int64_t>
struct MillerRabinPrimeTest {
    std::vector<T> test = {2,3,5,7,11,13,17,19,23,29};

    bool operator() (T const p) const {
        for (auto y : test)
            if (1 != qpow_in_mod(y, p - 1, p)) return false;
        return true;
    }
};
}

namespace A {
struct Network01Trait {
    typedef int edge_type;

    static const edge_type EDGE_DEFAULT;
    static const edge_type EDGE_SET_VALUE;
};
const Network01Trait::edge_type Network01Trait::EDGE_DEFAULT = 0;
const Network01Trait::edge_type Network01Trait::EDGE_SET_VALUE = 1;
} // namespace A

#if 0
#define POSTORDER_TRAVEL__S_TREEM
#define POSTORDER_TRAVEL__S_PAPA
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
            for (auto const & [v, e] : net->edges(x)) {
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
template <std::size_t N, std::size_t M, class Trait>
class SparseNet {
    struct sto_type;
public:
    typedef typename Trait::edge_type edge_type;

    explicit SparseNet(): a_used{0}, g_used{0} {
        std::fill(g.begin(), g.end(), -1);
    }

    void clear() {
        a_used = 0;
        std::fill(g.begin(), g.begin() + g_used + 1, -1);
        g_used = 0;
    }

    template <class Index>
    void arrow(Index src, Index dst, edge_type const & v) {
        a[a_used].st(dst, v, g[src]);
        g[src] = a_used++;
        std::size_t _s = src;
        if (_s > g_used) g_used = _s;
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

    template <class IterTraits> class EdgeList;

    template <class IterTraits>
    class EdgeIter {
    public:
        typedef typename IterTraits::edge_type edge_type;
        typedef typename IterTraits::sto_type sto_type;
        typedef std::pair<std::size_t, edge_type *> value_type;
        typedef std::forward_iterator_tag iterator_category;
        typedef value_type & reference;
        typedef int difference_type;

        value_type const & operator*() const { return gp<edge_type>(); }
        const value_type * operator->() const { return &p->p; }

        EdgeIter & operator++() { nx(); return *this; }
        EdgeIter operator++(int) { EdgeIter t = *this; nx(); return t; }

        bool operator==(EdgeIter const & other) const { return i == other.i; }
        bool operator!=(EdgeIter const & other) const { return i != other.i; }
    private:
        friend class EdgeList<IterTraits>;

        EdgeIter(sto_type *a, int i): i{i}, p{i >= 0 ? a + i : a}, a{a} {}

        template <typename Edge, std::enable_if_t<!std::is_const_v<Edge>, int> = 0>
        value_type const & gp() const { return p->p; }

        template <typename Edge, std::enable_if_t<std::is_const_v<Edge>, int> = 0>
        value_type const & gp() const { return p->pc; }

        void nx() {
            if (i >= 0) {
                i = p->nx_sto;
                if (i >= 0) {
                    p = a + i;
                }
            }
        }

        int i;
        sto_type *p, * const a;
    };

    template <class IterTraits>
    class EdgeList {
    public:
        typedef typename IterTraits::sto_type sto_type;
        typedef EdgeIter<IterTraits> Iter;
        Iter begin() const { return Iter(a, g); }
        Iter end() const { return Iter(a, -1); }
    private:
        friend class SparseNet;

        EdgeList(sto_type *a, int g): g{g}, a{a} {}

        const int g;
        sto_type * const a;
    };

    struct iter_traits {
        typedef typename SparseNet::edge_type edge_type;
        typedef typename SparseNet::sto_type sto_type;
    };
    struct const_iter_traits {
        typedef typename SparseNet::edge_type const edge_type;
        typedef typename SparseNet::sto_type const sto_type;
    };

    typedef EdgeList<iter_traits> edge_slist;
    typedef EdgeList<const_iter_traits> const_edge_slist;
    typedef typename edge_slist::Iter::value_type iter_output;
    typedef typename const_edge_slist::Iter::value_type const_iter_output;

    template <class Index>
    edge_slist edges(Index i) {
        return edge_slist(a.data(), g[i]);
    }

    template <class Index>
    const_edge_slist edges(Index i) const {
        return const_edge_slist(a.data(), g[i]);
    }

private:
    struct sto_type{
        edge_type v;
        int nx_sto;
        iter_output p;
        const_iter_output pc;

        void st(std::size_t dst, edge_type const & v, int nx) {
            this->v = v;
            p.first = dst;
            p.second = &this->v;
            pc = p;
            nx_sto = nx;
        }
    };

    std::array<sto_type, M> a;
    std::array<int, N> g;
    std::size_t a_used, g_used;
};
} // namespace A

namespace A {

struct _vary_tuple_binop__plus_t {};
struct _vary_tuple_binop__minus_t {};
struct _vary_tuple_binop__mulitplies_t {};

template <class OP, typename... Ts, std::size_t... Is,
         std::enable_if_t<
             std::is_same_v<_vary_tuple_binop__plus_t, OP>, int> = 0>
std::tuple<Ts...> __binary_op_vary_tuple(OP op,
        std::tuple<Ts...> const & t1, std::tuple<Ts...> const & t2,
        std::index_sequence<Is...> const &)
{
    return { ((std::get<Is>(t1) + std::get<Is>(t2)))... };
}

template <class OP, typename... Ts, std::size_t... Is,
         std::enable_if_t<
             std::is_same_v<_vary_tuple_binop__minus_t, OP>, int> = 0>
std::tuple<Ts...> __binary_op_vary_tuple(OP op,
        std::tuple<Ts...> const & t1, std::tuple<Ts...> const & t2,
        std::index_sequence<Is...> const &)
{
    return { ((std::get<Is>(t1) - std::get<Is>(t2)))... };
}

template <class OP, typename... Ts, std::size_t... Is,
         std::enable_if_t<
             std::is_same_v<_vary_tuple_binop__mulitplies_t, OP>, int> = 0>
std::tuple<Ts...> __binary_op_vary_tuple(OP op,
        std::tuple<Ts...> const & t1, std::tuple<Ts...> const & t2,
        std::index_sequence<Is...> const &)
{
    return { ((std::get<Is>(t1) * std::get<Is>(t2)))... };
}

template <class OP, typename... Ts>
std::tuple<Ts...> _binop_vary_tuple(OP op,
        std::tuple<Ts...> const & t1,
        std::tuple<Ts...> const & t2
        )
{
    return  __binary_op_vary_tuple(op, t1, t2, std::index_sequence_for<Ts...>{});
}

template <typename... Ts>
struct VaryTuple {
    using type = VaryTuple<Ts...>;
    using tuple_t = std::tuple<Ts...>;

    std::tuple<Ts...> t;

    VaryTuple(std::tuple<Ts...> const & t): t{t} {}
    VaryTuple(std::tuple<Ts...> && t): t{std::move(t)} {}

    type operator+ (type const & a) const { return _binop_vary_tuple(_vary_tuple_binop__plus_t{}, this->t, a.t); }
    type operator- (type const & a) const { return _binop_vary_tuple(_vary_tuple_binop__minus_t{}, this->t, a.t); }
    type operator* (type const & a) const { return _binop_vary_tuple(_vary_tuple_binop__mulitplies_t{}, this->t, a.t); }

    type & operator+= (type const & a) { return (*this = *this + a); }
    type & operator-= (type const & a) { return (*this = *this - a); }
    type & operator*= (type const & a) { return (*this = *this * a); }

    inline bool operator== (type const & a) const { return this->t == a.t; }
    inline bool operator< (type const & a) const { return this->t < a.t; }
};


template <typename... Ts>
auto vary_tuple(std::tuple<Ts...> && t) -> VaryTuple<Ts...> { return { t }; }
template <typename... Ts>
auto vary_tuple(std::tuple<Ts...> const & t) -> VaryTuple<Ts...> { return { t }; }
}
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: calc_in_mod miller_rabin network01trait postorder_travel sparse_net vary_tuple

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
using namespace std;
#define self_todo_placeholder

const int N = 201010;

typedef A::SparseNet<N, N * 3, A::Network01Trait> Nw;
typedef A::PostorderTravel<N, Nw> Pt;

std::vector<std::size_t> papa, povs;
Nw nw, tree;
Pt pt{&nw, &tree, &papa};


int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin >> n;
    vector<int> labels;
    labels.reserve(n);
    copy_n(istream_iterator<int>(cin), n - 1, back_inserter(labels));

    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        nw.link(x, y);
    }

    povs.reserve(n + 1);
    papa.reserve(n + 1);
    pt(1, std::back_inserter(povs));

    typedef A::VaryTuple<
        A::CalcInMod<100000007>,
        A::CalcInMod<998244353>,
        A::CalcInMod<1073741789>
        > H;
    vector<H> hs, phs;
    hs.resize(n + 1, H::tuple_t{0, 0, 0});
    phs.resize(n + 1, H::tuple_t{0, 0, 0});
    const H::tuple_t P = {32749, 131071, 524287};

    H lab = H::tuple_t{1, 1, 1};
    vector<H> pp;
    pp.reserve(n);
    pp.emplace_back(H::tuple_t{1, 1, 1});
    generate_n(std::back_inserter(pp), n - 1, [&]() { return lab *= P; });
    TRACE(cout << "pp=";
            for (auto p : pp) {
                auto [v1, v2, v3] = p.t;
                cout << v1.v << ' ' << v2.v << ' ' << v3.v << "  ";} cout << endl);
    lab = H::tuple_t{0, 0, 0};
    for (auto c : labels) {
        lab += pp[c];
    }
    set<H> labset;
    for (int i = 0; i < n; ++i) {
        auto h = lab + pp[i];
        labset.emplace(std::move(h));
    }
    TRACE(cout << "labset=";
            for (auto const & h : labset) {
              auto [x, y, z] = h.t;
              cout << '(' << x.v << ',' << y.v << ',' << z.v << ") "; } cout << endl);

    std::vector<int> ans;
    for (int i = 0; i < n; ++i) {
        auto x = povs[i];
        auto pa = papa[x];
        auto & h = hs[x];
        h += H::tuple_t{1, 1, 1};
        if (pa != x) {
            hs[pa] += h * P;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        auto x = povs[i];
        auto pa = papa[x];
        auto & ph = phs[x];
        auto const & h = hs[x];
        if (pa != x) {
            ph = ((hs[pa] - (h * P)) + phs[pa]) * P;
        }
        TRACE(cout << "node " << x << " pa[" << pa
                << "  " << get<0>(h.t).v << ' ' << get<0>(ph.t).v << endl);
        if (labset.find(h + ph) != labset.end()) {
            ans.emplace_back(x);
        }
    }
    sort(ans .begin() , ans .end() );
    cout << ans.size() << endl;
    copy(ans .begin() , ans .end() , std::ostream_iterator<int> (cout, " "));
    cout << endl;

    return 0;
}

