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

typedef long long LL;

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        LL u, v; cin >>u>>v;
        LL ans = 0;
        while (u % 10 != 2 && v > 0) {
            ans = max(ans, LL(u) * v);
            if (u % 10 == 0) break;
            u += u % 10;
            --v;
        }
        if (u % 10 == 0) {
            cout<<ans<<endl; continue;
        }
        auto ca = [&](LL t) { return (t >= 0 && t <= v) ?(u + t *5)*(v-t) : 0;};
        for (int _i = 0; _i < 4; ++_i) {
            // (u + 5x)(v - x)
            // 1/5*(u+5x)(5v-5x)
            LL t = u;
            t += v * 5;
            t >>= 1;
            t -= u;
            t /= 5;
            t = min(max(LL(0), t), v);
            t -= t & 3;

            ans = max(ans, ca(t));
                TRACELN(cout<<t<<' '<<u<<' '<<v<<' '<<ca(t));
            while ((u+t*5)<(5*v-5*t) && t < v) {
                t += 4;
                TRACELN(cout<<t<<' '<<u<<' '<<v<<' '<<ca(t));
                ans = max(ans, ca(t));
            }
            while ((u+t*5)>(5*v-5*t) && t > 0) {
                t -= 4;
                TRACELN(cout<<t<<' '<<u<<' '<<v<<' '<<ca(t));
                ans = max(ans, ca(t));
            }

            u += u % 10, --v; // iter
        }
        cout<<ans<<endl;
    }
    return 0;
}

