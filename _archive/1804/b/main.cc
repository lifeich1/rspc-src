#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
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
        int n, k, d, d1, lt, c = 0;
        cin >> n >> k >> d >> d1;
        d += d1;
        cin >> lt; ++c;
        int ans = 1;
        for (int i = 1,t; i < n; ++i) {
            cin >> t;
            if (k == c || t - lt > d) {
                ++ ans;
                lt = t;
                c = 1;
            } else ++c;
        }
        cout << ans << endl;
    }
    return 0;
}

