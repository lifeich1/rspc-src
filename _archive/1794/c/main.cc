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

int a[101234];

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
        int n;
        cin >> n;
        for (int i = 0, j = 0; i < n; ++i) {
            cin >> a[i];
            while (j < i && a[j] < (i - j + 1)) ++ j;
            cout << (i - j + 1) << ' ';
        }
        cout << endl;
    }
    return 0;
}

