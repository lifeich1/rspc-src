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

    int tt; cin >> tt; while (tt--) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        int ans = a + b;
        auto cal = [&](int m) {
            return (m - 1) + ((a - 1) / m) + 2
                + (b - 1) / m;
        };
#if defined(FORCE)
        for (int i = 2; i <= b; ++i)
            ans = min(ans, cal(i));
#elif 1
        for (int i = 2; i <= b; ++i) {
            auto v = cal(i);
            if (v <= ans) ans = v;
            else if (v > ans + 10) break;
        }
#else
        int mt = 1;
//#error 1
        for (int l = 2, r = b; l <= r; ) {
            int t = (l + r) >> 1;
            int v1 = cal(t);
            if (ans > v1) {
                mt = t;
                ans = v1;
            }
            int64_t d = t - 1, d2 = a;
            d *= t; d *= t;
            d2 *= b;
            if (d < d2) l = t + 1;
            else r = t - 1;
        }
        TRACELN(cout << '.' <<mt<<' '<<ans);
        for (int i = mt; i < mt + 100; ++i) ans = min(ans, cal(i));
        for (int i = max(mt - 100, 2); i < mt; ++i) ans = min(ans, cal(i));
#endif
        cout << ans << endl;
    }
    return 0;
}

