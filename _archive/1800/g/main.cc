#include <map>
#include <vector>
#include <unordered_map>
#include <array>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

// Placeholder for upcoming un-std algorithm, by rspc

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
template <std::size_t N, class Net>
class PostorderTravel {
public:
    typedef std::size_t vertex_t;

    explicit PostorderTravel(Net * net): net{net}, tree{nullptr}, cur{0} {
        std::fill(flag.begin(), flag.end(), cur);
    }

    void tree_memory(Net * net) { tree = net; }

    template <class Index, class OutputIt>
    void operator() (Index src, OutputIt d_first) {
        stk[0] = src;
        int p = 0;
        flag[src] = ++cur;
        while (p >= 0) {
            const auto lp = p;
            auto x = stk[p];
            for (auto const & [v, e] : net->edges(x)) {
                if (cur != flag[v]) {
                    flag[v] = cur;
                    stk[++p] = v;
                    if (tree) tree->arrow(x, v);
                }
            }
            if (lp == p) {
                --p;
                *(d_first++) = x;
            }
        }
    }
private:
    Net * net;
    Net * tree;
    std::array<int, N> flag;
    std::array<vertex_t, N> stk;
    int cur;
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
template <class Net>
class TreeRootHash {
public:
    typedef std::size_t hash_t;
    typedef std::size_t vertex_t;

    TreeRootHash(Net * net): net{net} {}

    void clear() {
        h_of_v.clear();
        vs_of_qh.clear();
        v_of_h.clear();
    }

    template <class Index>
    hash_t operator() (Index v) {
        auto it = h_of_v.find(v);
        if (it != h_of_v.end()) return it->second;
        std::vector<hash_t> child;
        children_hash(v, child);
        auto qh = qhash(child);
        auto col = vs_of_qh.find(qh);
        hash_t h = v_of_h.size();
        if (col != vs_of_qh.end()) { // check collision
            std::vector<hash_t> ch2;
            for (auto v2 : col->second) {
                children_hash(v2, ch2);
                if (ch2.size() != child.size()) continue;
                if (std::equal(ch2.begin(), ch2.end(), child.begin())) {
                    h = h_of_v[v2];
                    break;
                }
            }
        }
        if (h == v_of_h.size()) { // new hash
            v_of_h.emplace_back(v);
            vs_of_qh[qh].emplace_back(v);
        }
        return h_of_v[v] = h;
    }

private:
    void children_hash(vertex_t v, std::vector<hash_t> & hs) {
        hs.resize(0);
        std::transform(net->edges(v).begin(),
                net->edges(v).end(),
                std::back_inserter(hs),
                [&](auto const & e) { return (*this)(e.first); });
        sort(hs.begin(), hs.end());
    }

    hash_t qhash(std::vector<hash_t> const & hs) {
        return std::accumulate(
                hs.begin(),
                hs.end(),
                0,
                [](hash_t a, hash_t b) { return a * 197 + b; });
    }

    Net * net;
    std::unordered_map<vertex_t, hash_t> h_of_v;
    std::vector<vertex_t> v_of_h;
    std::map<hash_t, std::vector<vertex_t>> vs_of_qh;
};
}
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: network01trait postorder_travel sparse_net tree_root_hash

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
using namespace std;
#define self_todo_placeholder

const int N = 201010;
typedef A::SparseNet<N, N + N, A::Network01Trait> Net;
typedef A::TreeRootHash<Net> Hash;
typedef A::PostorderTravel<N, Net> PT;
typedef Hash::hash_t hash_t;

Net net;
Net tree;
PT pt{&net};
Hash thash{&tree};

int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    pt.tree_memory(&tree);

    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        net.clear(); tree.clear(); thash.clear();
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            net.link(u, v);
        }
        pt(1, a);
        for (int i = 0; i < n; ++i) thash(a[i]);
        TRACE(copy(a, a + n, ostream_iterator<int>(cout, " ")); cout << endl;
                transform(a, a + n, ostream_iterator<hash_t>(cout, " "),
                    [&](int x) { return thash(x); }); cout << endl);

        map<hash_t, int> cnt;
        map<hash_t, int> samp;
        int odd = 0, rt = 1;
        do {
            odd = 0; cnt.clear(); samp.clear();
            TRACE(cout << rt << endl);
            for (auto const & [v, e] : tree.edges(rt)) {
                TRACE(cout << v << ' ' << thash(v) << endl);
                auto h = thash(v);
                cnt[h] ++;
                samp[h] = v;
            }
            for (auto const & [h, c] : cnt)
                if ((c & 1) && (rt = samp[h], odd++) > 0) break;
            TRACE(cout << ' ' << odd << ' ' << rt << endl);
        } while (odd == 1);

        cout << (odd < 2 ? "YES" : "NO") << endl;
    }
    return 0;
}

