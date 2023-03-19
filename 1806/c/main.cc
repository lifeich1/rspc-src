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

const int N = 401001;
int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        n <<= 1;
        copy_n(std::istream_iterator<int> (cin), n, a);
        sort(a, a + n);
        if (2 == n) {
            cout << abs(a[0] - a[1]) << endl;
            continue;
        }
        int64_t ans = accumulate(a, a + n, int64_t(0), [](int64_t s, int a) { return s + abs(a); });
        if (4 == n) {
            int64_t t = accumulate(a, a + n, int64_t(0), [](int64_t s, int a) { return s + abs(a - 2); });
            ans = min(ans, t);
        }
        if ((n & 3) == 0) {
            int64_t t = accumulate(a, a + n - 1, int64_t(0), [](int64_t s, int a) { return s + abs(a + 1); });
            t += abs(a[n - 1] - (n >> 1));
            ans = min(ans, t);
        }
        cout << ans << endl;
    }
    return 0;
}

