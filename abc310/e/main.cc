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

    int n; string s; cin >>n>>s;
    int f[2] = {0,0};
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = s[i] -'0';
    int g[2] = {0,0};
        g[1-(x&0)] = f[0];
        g[1-(x&1)] += f[1];
        g[x]++;
        ans += g[1];
        f[0] = g[0];
        f[1] = g[1];
        TRACELN(cout<<' '<<i<<' '<<x<<' '<<f[0]<<' '<<f[1]);
    }
    cout<<ans<<endl;
    return 0;
}

