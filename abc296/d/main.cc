#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
#define TRACELN(...) TRACE(__VA_ARGS__; cout << endl)
#define TRACE_VEC(VEC, ITEM, ...) TRACE(cout << #VEC << "= "; for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
using namespace std;
#define self_todo_placeholder


int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int64_t n, m; cin >> n >> m;
    if (n < (m - 1) / n + 1) {
        cout << "-1\n";
        return 0;
    }
    int64_t n1 = n;
    for (int64_t d = (n >> 1); d > 0; d >>= 1)
    {
        n1 -= d;
        if (n1 < (m - 1) / n1 + 1) n1 += d;
    }
    int64_t ans = n * ((m - 1) / n + 1);
    for (; n1 > 0; --n1) {
        int64_t t = (m - 1) / n1 + 1;
        if (t > n) break;
        t *= n1;
        if (ans > t) ans = t;
    }
    cout << ans << endl;
    return 0;
}

