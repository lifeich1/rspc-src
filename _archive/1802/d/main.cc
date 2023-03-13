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
int ci[N], va[N], vb[N];

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
            va[i] = ai[i].first;
            vb[i] = bi[i].first;
            ai[i].second = bi[i].second = i;
        } 
        fill(ci, ci + n, 0);
        sort(ai, ai + n);
        sort(bi, bi + n);
        int ans = max(ai[n - 1].first, bi[n - 1].first) - min(ai[0].first, bi[0].first);
        auto chk = [&](int ia, int ib) {
            if (1 == ci[bi[ib].second]) return;
            int t = abs(ai[ia].first - bi[ib].first);
            if (ans > t) ans = t;
            TRACE(cout << '!' << ans << ' ' << ia << ' ' << ib << endl);
        };
        for (int ia = n - 1, ib, ibl = 0; ia >= 0; --ia) {
            auto [av, ax] = ai[ia];
            ci[ax] = 1;
            ib = lower_bound(bi + ibl, bi + n - 1, make_pair(av, 0)) - bi;
            TRACE(cout << ' ' << ib << ' ' << ibl << endl);
            chk(ia, ib);
            if (ib + 1 < n) chk(ia, ib + 1);
            if (ib > 0 && ib > ibl) chk(ia, ib - 1);
            if (ib > 1 && ib - 1 > ibl) chk(ia, ib - 2);

            if (vb[ax] > bi[ibl].first) {
                while (bi[ibl].second != ax) ++ibl;
            }
            ci[ax] = 2;
        }
        cout << ans << endl;
    }
    return 0;
}

