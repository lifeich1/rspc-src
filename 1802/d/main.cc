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

const int N = 501001;
pair<int,int> ai[N], bi[N];
int ci[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> ai[i].first >> bi[i].first;
            ai[i].second = bi[i].second = i;
        } 
        fill(ci, ci + n, 0);
        sort(ai, ai + n);
        sort(bi, bi + n);
        int ans = max(ai[n - 1].first, bi[n - 1].first) - min(ai[0].first, bi[0].first);
        for (int ia = n - 1, ib = n - 1; ia >= 0 && ib >= 0; ) {
            const auto [av, ax] = ai[ia];
            const auto [bv, bx] = bi[ib];
            TRACE(cout << av << ' ' << ax << "  " << bv << ' ' << bx << endl);
            if (ax != bx && ci[ax] != 2 && ci[bx] != 1) {
                int t = abs(av - bv);
                if (t < ans) ans = t;
            }
            int t0 = -1, t1 = -1;
            if (ia > 0 && ci[ax] != 1) { // ok false choose ia
                t0 = abs(ai[ia - 1].first - bv);
            }
            if (ib > 0 && ci[bx] != 2) {
                t1 = abs(bi[ib - 1].first - av);
            }
            if (t0 == -1 && t1 == -1) break;
            TRACE(cout << ' ' << t0 << ' ' << t1 << endl);
            if (t0 != -1 && (t0 < t1 || t1 == -1)) {
                ci[ax] = 2;
                --ia;
            } else {
                ci[bx] = 1;
                --ib;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

