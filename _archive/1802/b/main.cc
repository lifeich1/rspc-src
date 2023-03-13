#include <iostream>
#include <algorithm>
#include <numeric>

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

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int c0 = 0, c = 0, ans = 0, t;
        while (n--) {
            cin >> t;
            if (1 == t) {
                ++c0;
            } else {
                c += c0, c0 = 0;
            }
            t = (c > 0 ? ((c + 2) >> 1) : 0) + c0;
            if (t > ans) ans = t;
        }
        cout << ans << endl;
    }
    return 0;
}

