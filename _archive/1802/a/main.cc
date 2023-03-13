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

    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int neg = 0;
        for (int i = 0, j; i < n; ++i) {
            cin >> j;
            if (j < 0) ++ neg;
        }
        int i = 1, l;
        for (l = n - neg; i <= l; ++i) cout << i << ' ';
        for (i -= 2, l = n - neg * 2; i >= l; --i) cout << i << ' ';
        cout << endl;
        for (i = 0; i < neg; ++i) cout << "1 0 ";
        for (l = n - neg * 2, i = 1; i <= l; ++i) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

