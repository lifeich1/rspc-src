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
        int u, v; cin >>u>>v;
        if (u % 10 == 0) {
            cout<<int64_t(u) * v<<endl;
            continue;
        }
        if (u % 10 == 5) {
            int64_t t = u;
            t *= v;
            t = max(t, int64_t(u+5) * (v-1));
            cout<<t<<endl;
            continue;
        }
        int64_t ans = 0;
        while (u % 10 != 2 && v > 0) {
            ans = max(ans, int64_t(u) * v);
            u += u % 10;
            --v;
        }
        auto ca = [&](int x) {
            int64_t t = u;
            t += (x / 4) * 20;
            for (int j = x % 4; j > 0; --j) t += t % 10;
            t *= v - x;
            return t;
        };
        auto vl = ca(0), vr = ca(v-1);
        int l,r;
        for ( l = 0, r = v-1; l < r-10; ) {
            //TRACELN(cout<<' '<<l<<' '<<r);
            int t1 = l + max(1, (r-l) / 3);
            int t2 = r - max(1, (r-l) / 3);
            auto v1 = ca(t1), v2 = ca(t2);
            ans = max(v1, ans);
            ans = max(v2, ans);
            auto m = max(vl, max(vr, max(v1, v2)));
            if (vr == m || (v2 == m && vl != m)) {
                l = t1;
                vl = v1;
            }  else {
                r = t2;
                vr = v2;
            }
        }
        while (l <= r) ans = max(ans, ca(l++));
        cout<<ans<<endl;
    }
    return 0;
}

