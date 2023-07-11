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
        int64_t f[2] = {0,0};
        if (1 == n) {
            int x; cin >> x;
            cout<<x<<endl;
            continue;
        }
        cin >> f[0]>>f[1];
        int64_t ans = max(f[0], f[1]);
        for (int i = 2; i < n; ++i) {
            int64_t x; cin >> x;
            f[i&1] = max(x + max(int64_t(0), f[i&1]), f[i&1]);
            ans = max(ans, f[i&1]);
            TRACELN(cout<<"|"<<f[0]<<' '<<f[1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

