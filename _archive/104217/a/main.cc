#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>

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
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#endif

    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) {
            ans += (t[i] != 'I' && t[i] != 'B') ? 1 : 2;
        }
    }
    cout << ans << endl;
    return 0;
}
