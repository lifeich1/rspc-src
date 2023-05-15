#include <functional>
#include <type_traits>
#include <array>
#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc


namespace A {

template <class T, std::size_t N>
struct TreeShapeArray {
    std::array<int, N> flag;
    int flag_cur = 0;
    std::array<T, N> a;
    int n; // work at [1, n]

    std::function<bool(T &, bool, T const &)> update; // return true for update executed
    std::function<void(T &, T const &)> add;

    void reset(int n) { ++ flag_cur, this->n = n; }

    void put(int x, T const & v) {
        for (; x <= n; x += (x & -x))
            if (this->update(a[x], flag[x] != flag_cur, v)) flag[x] = flag_cur;
            else break;
    }
    void sum_r(int x, T & res) {
        for (; x > 0; x -= (x & -x))
            if (flag_cur == flag[x]) this->add(res, a[x]);
    }

    T sum(int x, T init) {
        this->sum_r(x, init); return init;
    }
};
}
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: tree_shape_array

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
#define TRACELN(...) TRACE(__VA_ARGS__; cout << endl)
#define TRACE_VEC(VEC, ITEM, ...) TRACE(cout << #VEC << "= "; for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
using namespace std;
#define self_todo_placeholder


const int N = 201001;
A::TreeShapeArray<int, N> ta;

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin >> n;
    vector<int> hs, a;
    vector<pair<int,int>> h;
    hs.reserve(n);
    a.reserve(n);
    h.reserve(n);
    copy_n(std::istream_iterator<int> (cin), n, back_inserter(hs));
    copy_n(std::istream_iterator<int> (cin), n, back_inserter(a));
    {
        vector<int> t1{a}, t2{hs};
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        transform(t1.begin(), t1.end(), t2.begin(), t2.begin(), minus{});
        if (any_of(t2.begin(), t2.end(), [](int x) { return x != 0; })) {
            cout << "No\n";
            return 0;
        }
        if (unique(t1.begin(), t1.end()) != t1.end()) {
            cout << "Yes\n";
            return 0;
        }
    }
    transform(hs.begin(), hs.end(), a.begin(), std::back_inserter (h), [](int x, int y)->pair<int,int> { return {x, y}; });
    sort(h.begin(), h.end());
    transform(h.begin(), h.end(), a.begin(), [](pair<int,int> p) { return p.second; });
    ta.reset(*max_element(a.begin(), a.end()));
    TRACELN(copy(a.begin(), a.end(), std::ostream_iterator<int> (cout , " ")));
    ta.update = [](int &v, bool fl, int const & d) { v = fl ? d : v + d; return true; };
    ta.add = [](int &v, int const &d) { v += d; };
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans ^= (i - ta.sum(a[i], 0));
        ta.put(a[i], 1);
    }
    cout << ((ans & 1) == 0 ? "Yes\n" : "No\n") ;

    return 0;
}

