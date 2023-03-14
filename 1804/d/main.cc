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

const int N = 501010;
int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m;
    cin >> n >> m;
    int64_t ans1 = 0, ans2 = 0;
    a[m] = 0;
    const int qm = m >> 2;
    for (int i = 0; i < n; ++i) {
        char ch;
        for (int k = 0; k < m; ++k) cin >> ch, a[k] = (ch - '0');
        const int oc = count(a, a + m, 1);
        int c = 0;
        TRACE(cout << "oc=" << oc << endl);
        ans1 += oc - min(qm, accumulate(a, a + m + 1, 0,
                    [&](int s, int x) {
                    TRACE(cout << c << ',' << s << ' ');
                        return 0 == x ? (s += c >> 1, c = 0, s) : (++c, s);
                    }));
        TRACE(cout << endl);
        transform(a, a + m - 1, a + 1, a, plus{});
        a[m - 1] = 2; c = 0;
        ans2 += oc - qm + min(qm, accumulate(a, a + m, 0,
                    [&](int s, int x) {
                    TRACE(cout << c);
                        return 2 == x ? (s += (c + 1) >> 1, c = 0, s) : (++c, s);
                    }));
        TRACE(cout << endl);
        TRACE(cout << ',' << ans1 << ' ' << ans2 << endl);
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}

