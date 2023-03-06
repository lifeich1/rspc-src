#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

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

int a[205050];

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
        copy_n(istream_iterator<int>(cin), n, a);
        int64_t ans = 0;
        for (int i = 0, p = 0; i < n; ++i) {
            if (a[i] > 0) {
                if (i != p) a[p] = a[i];
                push_heap(a, a + (++p));
            } else {
                if (p == 0) continue;
                ans += a[0];
                TRACE(cout << a[0] << ' ' << ans << endl);
                pop_heap(a, a + p--);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

