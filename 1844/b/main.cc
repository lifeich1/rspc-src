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

    int tt; cin >> tt; while (tt--) {
        int n; cin >>n;
        if (n < 3) {
            for (int i = 1 ; i <= n; ++i) cout<<i<<' ';
            cout<<endl;
        } else {
            cout<<2;
            int t = n / 2;
            int p = 3;
            for (int i = 1; i < t; ++i) cout<<' '<<++p;
            cout<<" 1";
            while (p < n) cout<<' '<<++p;
            cout<<" 3\n";
        }
    }
    return 0;
}

