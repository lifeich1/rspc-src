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
        int n; cin >> n;
        int ans = n;
        int64_t gd = 0, lm = 1;
        for (int i = 0, x, y; i < n; ++i) {
            cin >> x >> y;
            int64_t t = x;
            t *= y;
            int64_t td;
            if (gd == 0 || ((td = __gcd(gd, t)) % y != 0) || (td % lm != 0)) {
                gd = x;
                gd *= y;
                lm = y;
            } else {
                gd = td;
                td = __gcd(lm, int64_t(y));
                lm *= y / td;
                --ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

