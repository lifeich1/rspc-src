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

    int tt; cin >> tt; while (tt--) 
    {
        int n; cin >> n;
        int64_t ans = 1;
        const int64_t M = 1000000007;
        bool d1 = true;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if ((x & 1) == 0) {
                ans <<= 1;
                ans %= M;
            } else d1 = false;
        }
        if (d1) ans = (ans + M - 1) % M;
        cout<<ans<<endl;
    }
    return 0;
}

