#include <type_traits>
#include <tuple>
#include <array>
#include <functional>
#include <iterator>
#include <vector>
#include <cmath>
#include <iosfwd>
#include <iostream>
#include <algorithm>
#include <numeric>

// Placeholder for upcoming un-std algorithm, by rspc

namespace A {
template <std::size_t N, class Trait>
class Bfs {
public:
    typedef typename Trait::net_type net_type;
    typedef typename net_type::const_iter_output edge_iter_output;
    typedef typename Trait::visitor_type visitor_type; // new_visitor = visitor{}.visit(cur_node, edge_v), start: visitor(src)
    typedef std::array<visitor_type, N> visitor_array;
    typedef std::array<bool, N> used_array;

    Bfs() {}

    visitor_array const & get_vis() { return vis; }
    used_array const & get_used() { return used; }

    template <class InputIt, class Size = std::size_t>
    void start(InputIt first, InputIt last, net_type const & nw, Size node_limit = N) {
        p = 0; q = last - first;
        std::copy(first, last, ns.begin());
        std::fill(used.begin(), used.begin() + std::min(node_limit, N), false);
        std::for_each(ns.begin(), ns.begin() + q, [&](std::size_t i) { used[i] = true; vis[i] = visitor_type(i); });

        auto fvis = [&](std::size_t pre, edge_iter_output e) {
            auto d = e.first;
            if (!used[d]) {
                used[d] = true;
                ns[q++] = d;
                vis[d] = vis[pre].visit(d, *e.second);
            }
        };
        for (; p < q; ++p) {
            auto x = ns[p];
            auto es = nw.edges(x);
            std::for_each(es.begin(), es.end(), std::bind(fvis, x, std::placeholders::_1));
        }
    }

private:
    visitor_array vis;
    used_array used;
    std::array<std::size_t, N> ns;
    std::size_t p, q;
};
} // namespace A
#if __cplusplus >= 201402L
# define CONSTEXPR14 constexpr
#else
# define CONSTEXPR14
#endif

namespace A {
struct Network01Trait {
    typedef int edge_type;

    static const edge_type EDGE_DEFAULT;
    static const edge_type EDGE_SET_VALUE;
};
const Network01Trait::edge_type Network01Trait::EDGE_DEFAULT = 0;
const Network01Trait::edge_type Network01Trait::EDGE_SET_VALUE = 1;
} // namespace A

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

namespace A {
template <std::size_t N, std::size_t M, class Trait>
class SparseNet {
    struct sto_type;
public:
    typedef typename Trait::edge_type edge_type;

    explicit SparseNet(): a_used{0} {
        std::fill(g.begin(), g.end(), -1);
    }

    template <class Index>
    void arrow(Index src, Index dst, edge_type const & v) {
        a[a_used].st(dst, v, g[src]);
        g[src] = a_used++;
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
    std::size_t a_used;
};
} // namespace A

namespace A {
template <class T>
using get_cv_iterator_t =
std::conditional_t<std::is_const_v<T>,
    typename T::const_iterator, typename T::iterator>;

template <std::size_t N, class Tuple, class FirstType, class... Types>
struct _tuple_deref_impl {
    typedef typename FirstType::reference FirstRef;
    std::tuple<FirstRef, typename Types::reference...>
        operator() (Tuple const & t) {
        return std::tuple_cat(
                std::make_tuple(std::ref(*std::get<std::tuple_size_v<Tuple> - N>(t))),
                _tuple_deref_impl<N - 1, Tuple, Types...>{}(t)
                );
    }
};
template <class Tuple, class Type>
struct _tuple_deref_impl<1, Tuple, Type> {
    std::tuple<typename Type::reference> operator() (Tuple const & t) {
        return {*std::get<std::tuple_size_v<Tuple> - 1>(t)};
    }
};
template <std::size_t N, class... Types>
using tuple_deref = _tuple_deref_impl<N, std::tuple<Types...>, Types...>;

template <std::size_t N, class Tuple>
struct tuple_inc {
    void operator() (Tuple & t) {
        ++std::get<N - 1>(t);
        tuple_inc<N - 1, Tuple>{}(t);
    }
};
template <class Tuple>
struct tuple_inc<1, Tuple> {
    void operator() (Tuple & t) {
        ++std::get<0>(t);
    }
};

template <std::size_t N, class Tuple>
struct tuple_any_eq {
    bool operator() (Tuple const & lhs, Tuple const & rhs) {
        return std::get<N - 1>(lhs) == std::get<N - 1>(rhs)
            ? true
            : tuple_any_eq<N - 1, Tuple>{}(lhs, rhs);
    }
};
template <class Tuple>
struct tuple_any_eq<1, Tuple> {
    bool operator() (Tuple const & lhs, Tuple const & rhs) {
        return std::get<0>(lhs) == std::get<0>(rhs);
    }
};

template <class... Iters>
class ZipSList {
public:
    ZipSList(std::tuple<Iters...> first, std::tuple<Iters...> last)
        : _first{first}, _last{last}
    {}

    template <class Container>
    ZipSList<Iters..., get_cv_iterator_t<Container>> operator+ (Container & container) {
        return {
            std::tuple_cat(_first, std::forward_as_tuple(container.begin())),
            std::tuple_cat(_last, std::forward_as_tuple(container.end())),
        };
    }

    template <class InputIt>
    ZipSList<Iters..., std::decay_t<InputIt>> c(InputIt first, InputIt last) {
        return {
            std::tuple_cat(_first, std::forward_as_tuple(first)),
            std::tuple_cat(_last, std::forward_as_tuple(last)),
        };
    }

    class ZIter {
        typedef std::tuple<Iters...> Tuple;
        static constexpr std::size_t tuple_siz = std::tuple_size_v<Tuple>;
    public:
        typedef std::tuple<typename Iters::value_type...> value_type;
        typedef std::tuple<typename Iters::reference...> reference;

        reference operator* () const { return tuple_deref<tuple_siz, Iters...>{}(_it); }

        ZIter & operator++ () { tuple_inc<tuple_siz, Tuple>{}(_it); return *this; }
        ZIter operator++ (int) { auto t = *this; tuple_inc<tuple_siz, Tuple>{}(_it); return t; }

        bool operator==(ZIter const & other) const { return tuple_any_eq<tuple_siz, Tuple>{}(_it, other._it); }
        bool operator!=(ZIter const & other) const { return !tuple_any_eq<tuple_siz, Tuple>{}(_it, other._it); }
    private:
        friend class ZipSList;

        ZIter(Tuple const & it): _it{it} {}

        Tuple _it;
    };

    ZIter begin() const { return {_first}; }
    ZIter end() const { return {_last}; }

private:
    std::tuple<Iters...> _first;
    std::tuple<Iters...> _last;
};
template <class Container>
ZipSList<get_cv_iterator_t<Container>> zip_slist(Container & container) {
    return {std::forward_as_tuple(container.begin()),
        std::forward_as_tuple(container.end())};
}

template <class InputIt>
ZipSList<std::decay_t<InputIt>> zip_slist(InputIt first, InputIt last) {
    return {std::forward_as_tuple(first),
        std::forward_as_tuple(last)};
}
} // namespace A

namespace A {
template <class T>
class Discrete2dCoord {
public:
    typedef Point2d<T> Pn;
    typedef std::vector<Pn> Vec;
    typedef typename Vec::size_type size_type;

    explicit Discrete2dCoord(Vec * v): v{v}, discre{v->size()} {
        auto ds = make_discrete(&Pn::x);
        std::transform(ds.begin(), ds.end(), discre.begin(),
                discre.begin(), [](T x, Pn const & p) { return Pn{x, p.y}; });

        ds = make_discrete(&Pn::y);
        std::transform(ds.begin(), ds.end(), discre.begin(),
                discre.begin(), [](T y, Pn const & p) { return Pn{p.x, y}; });

        sort_v(std::less<Pn>{}, xh, xi).swap(sorted_xy);
        sort_v(typename Pn::YXLess{}, yh, yi).swap(sorted_yx);
    }

    Vec const & discreted() { return discre; }
    Vec const & sorted_x() { return sorted_xy; }
    Vec const & sorted_y() { return sorted_yx; }

    std::vector<size_type> const & x_order() { return xh; }
    std::vector<size_type> const & y_order() { return yh; }

    std::vector<size_type> const & x_index() { return xi; }
    std::vector<size_type> const & y_index() { return yi; }

private:
    template <class Cmp>
    Vec sort_v(Cmp cmp, std::vector<size_type> & ord, std::vector<size_type> & ind) {
        Vec s;
        auto n = v->size();
        s.reserve(n);
        std::copy(v->begin(), v->end(), std::back_inserter(s));
        std::sort(s.begin(), s.end(), cmp);

        auto f = [&](Pn const & p) {
            return std::lower_bound(s.begin(), s.end(), p, cmp) - s.begin();
        };
        ord.clear();
        ord.reserve(n);
        std::transform(v->begin(), v->end(), std::back_inserter(ord), f);

        std::vector<size_type>(n).swap(ind);
        size_type i = 0;
        std::for_each(ord.begin(), ord.end(), [&](size_type o) { ind[o] = i++; });
        return s;
    }

    template <class Extractor>
    std::vector<T> make_discrete(Extractor ext) {
        auto n = v->size();
        std::vector<T> dx;
        dx.reserve(n);
        auto f = std::bind(ext, std::placeholders::_1);
        std::transform(v->begin(), v->end(), std::back_inserter(dx), f);
        std::sort(dx.begin(), dx.end());
        dx.erase(std::unique(dx.begin(), dx.end()), dx.end());
        auto g = [&](Pn const & p) {
            auto x = f(p);
            return std::lower_bound(dx.begin(), dx.end(), x) - dx.begin();
        };
        std::vector<T> res;
        res.reserve(n);
        std::transform(v->begin(), v->end(), std::back_inserter(res), g);
        return res;
    }

    Vec * v;
    Vec discre, sorted_xy, sorted_yx;
    std::vector<size_type> xh, yh, xi, yi;
};
}



namespace A {
template <class T>
/// Input vector<Point2d> like `Input2dCoord<int>(cin, n) >> v`
class Input2dCoord {
public:
    typedef Point2d<T> Pn;
    typedef std::vector<Pn> Vec;

    template <class Stream, class Size>
    explicit Input2dCoord(Stream &&s, Size n) {
        v.reserve(n);
        std::copy_n(std::istream_iterator<Pn>(s), n, std::back_inserter(v));
    }

    Vec & operator>>(Vec & taker) {
        taker.swap(v);
        return taker;
    }

private:
    Vec v;
};
}
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: bfs constexpr14 network01trait point2d sparse_net zip_slist discrete2dcoord input2dcoord

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif

using namespace std;
#define self_todo_placeholder

const int N = 200000;
typedef A::Input2dCoord<int> I2C;
typedef I2C::Pn Pn;
typedef A::Discrete2dCoord<int> D2C;
typedef A::SparseNet<N, N * 4, A::Network01Trait> Nw;
typedef size_t luint;

array<Pn, N> ans;
struct V {
    luint s;

    V() {}
    V(luint s): s{s} {}
    V visit(size_t p, int) {
        ans[p] = ans[s];
        return s;
    }
};

struct BT {
    typedef Nw net_type;
    typedef V visitor_type;
};

A::Bfs<N, BT> bfs;
array<bool, N> inst;
Nw nw;

int main() {
    luint n;
    vector<Pn> vs;
    vector<size_t> st;

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#endif

    cin >> n;
    I2C(cin, n) >> vs;

    D2C d2c(&vs);
    auto & sx = d2c.sorted_x();
    auto & sy = d2c.sorted_y();
    auto & ix = d2c.x_index();
    auto & iy = d2c.y_index();
    fill(inst.begin(), inst.begin() + n, false);
    st.reserve(n);
    auto addst = [&](luint i, Pn a) {
        TRACE(cout << "eaf: " << i << " - " << a << endl);
        ans[i] = a;
        if (!inst[i]) {
            st.emplace_back(i);
            inst[i] = true;
        }
    };
    addst(ix[0], sx[0] + Pn(-1, 0));
    addst(ix[n - 1], sx[n - 1] + Pn(1, 0));
    addst(iy[0], sy[0] + Pn(0, -1));
    addst(iy[n - 1], sy[n - 1] + Pn(0, 1));

    auto lf = [&](
            tuple<size_t const &, size_t const &, Pn const &, Pn const &> const & tp,
            Pn const & dl, Pn const dr) {
        Pn pl, pr; size_t il, ir;
        tie(il, ir, pl, pr) = tp;
        TRACE(cout << il << ' ' << ir << " (" << pl << ") (" << pr << ")\n");
        if ((dl + pl) == pr) {
            TRACE(cout << "link: " << il << ' ' << ir << endl);
            nw.link(il, ir);
        } else {
            addst(il, pl + dl);
            addst(ir, pr + dr);
        }
    };

    auto l0 = (A::zip_slist(ix).c(ix.begin() + 1, ix.end())
        + sx).c(sx.begin() + 1, sx.end());
    for_each(l0.begin(), l0.end(), bind(lf, placeholders::_1, Pn(0, 1), Pn(0, -1)));

    auto l1 = (A::zip_slist(iy).c(iy.begin() + 1, iy.end())
        + sy).c(sy.begin() + 1, sy.end());
    for_each(l1.begin(), l1.end(), bind(lf, placeholders::_1, Pn(1, 0), Pn(-1, 0)));

    bfs.start(st.begin(), st.end(), nw, n);

    copy(ans.begin(), ans.begin() + n, ostream_iterator<Pn>(cout, "\n"));

    return 0;
}

