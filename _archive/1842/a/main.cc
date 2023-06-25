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
        int n, m; cin >>n>>m;
        int64_t a1, a2; a1=a2 =0;
        for (int i = 0; i < n; ++i) {
            int t;cin>>t;
            a1 += t;
        }
        for (int i = 0; i < m; ++i) {
            int t;cin>>t;
            a2 += t;
        }
        if (a1==a2) cout<<"Draw\n";
        else cout<<(a1<a2?"Tenzing\n":"Tsondu\n");
    }
    return 0;
}

