#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
#define TRACELN(...) TRACE(__VA_ARGS__; cout << endl)
#define TRACE_VEC(VEC, ITEM, ...) TRACE(cout << #VEC << "= "; for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
using namespace std;
#define self_todo_placeholder


int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    vector<int64_t> a;
    int tt; cin >> tt; while (tt--) {
        int n; cin >>n;
        a.clear();
        a.reserve(n);
        copy_n(std::istream_iterator<int64_t>(std::cin),n, std::back_inserter(a));
        sort(a.begin(),a.end());
        transform(a.rbegin()+1, a.rend(), a.rbegin(), a.rbegin()+1, plus<int64_t>{});
        copy(a.begin(),a.end(), std::ostream_iterator<int64_t>(std::cout, " "));
        cout<<endl;
    }
    return 0;
}

