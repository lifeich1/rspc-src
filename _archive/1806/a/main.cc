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
        int x, y, x1, y1;
        cin >> x1 >> y1 >> x >> y;
        x -= x1, y -= y1;
        int ans = 0;
        if (y < 0) {
            cout << "-1\n"; continue;
        }
        ans += y; x -= y;
        if (x > 0) {
            cout << "-1\n"; continue;
        }
        ans -= x;
        cout << ans << endl;
    }
    return 0;
}

