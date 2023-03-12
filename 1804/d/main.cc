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
int a[N], f[N], g1[N], g2[N];

int fmx(const int m) {
    auto mg1 = m / 2, mg2 = mg1 / 2;
    f[0] = g1[0] = g2[0] = 0;
    for (int i = 1; i <= m; ++i) {
        auto ch = a[i - 1];
        if ((ch && (i > 1 && a[i - 2]) && g1[i - 1] < mg1) || (1 == i || g2[i - 2] == mg2))  {
            f[i] = f[i - 1] + ch, g1[i] = g1[i - 1] + 1, g2[i] = g2[i - 1];
            TRACE(cout << 1);
        } else {
            f[i] = f[i - 2] + (ch | a[i - 2]), g1[i] = g1[i - 2], g2[i] = g2[i - 2] + 1;
            TRACE(cout << 2);
        }
    }
    TRACE(cout << endl; copy_n(f, m + 1, std::ostream_iterator<int> (cout, " ")); cout << endl);
    return f[m];
}
int fmi(const int m) {
    auto mg1 = m / 2, mg2 = mg1 / 2;
    f[0] = g1[0] = g2[0] = 0;
    for (int i = 1; i <= m; ++i) {
        auto ch = a[i - 1];
        if ((i > 1 && ch && a[i - 2] && g2[i - 2] < mg2) || (g1[i - 2] == mg1 && g2[i - 1] != mg2))  {
            f[i] = f[i - 2] + (ch | a[i - 2]), g1[i] = g1[i - 2], g2[i] = g2[i - 2] + 1;
            TRACE(cout << 2);
        } else {
            f[i] = f[i - 1] + ch, g1[i] = g1[i - 1] + 1, g2[i] = g2[i - 1];
            TRACE(cout << 1);
        }
    }
    TRACE(cout << endl; copy_n(f, m + 1, std::ostream_iterator<int> (cout, " ")); cout << endl);
    return f[m];
}

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
    for (int i = 0; i < n; ++i) {
        char ch;
        for (int k = 0; k < m; ++k) cin >> ch, a[k] = (ch - '0');
        ans2 += fmx(m);
        ans1 += fmi(m);
        TRACE(cout << ',' << ans1 << ' ' << ans2 << endl);
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}

