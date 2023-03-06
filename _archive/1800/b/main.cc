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

int a[2][26];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        fill(a[0], a[0] + 26, 0);
        fill(a[1], a[1] + 26, 0);
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            a[islower(c) ? 0 : 1][tolower(c) - 'a']++;
        }
        int d = 0, ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += min(a[0][i], a[1][i]);
            d += abs(a[0][i] - a[1][i]) >> 1;
        }
        cout << (ans + min(k, d)) << endl;
    }
    return 0;
}

