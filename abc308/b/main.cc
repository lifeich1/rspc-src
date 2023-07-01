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

    int n,m; cin >>n>>m;
    vector<string> c, d;
    copy_n(std::istream_iterator<string>(cin),n, std::back_inserter(c));
    copy_n(std::istream_iterator<string>(cin),m, std::back_inserter(d));
    vector<int> p;
    copy_n(std::istream_iterator<int>(std::cin), m+1, std::back_inserter(p));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = find(d.begin(), d.end(), c[i])-d.begin();
        if (it == d.size()) {
            ans += p[0];
        } else ans += p[it+1];
    }
    cout<<ans<<endl;
    return 0;
}

