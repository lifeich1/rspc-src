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

const int N = 201010;
char a[N], b[N];

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
        copy_n(istream_iterator<char>(cin), n, a);
        copy_n(istream_iterator<char>(cin), n, b);
        int l = max(n - k, 0), r = min(n, k);
        bool ok = true;
        if (l < r) {
            ok = equal(a + l, a + r, b + l);
        }
        if (ok) {
            sort(a, a + n);
            sort(b, b + n);
            ok = equal(a, a + n, b);
            TRACE(cout << a << '\n' << b << endl);
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}

