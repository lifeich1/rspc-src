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

int c[22][22], g[22][22];
int n,T,m, gs = 0; 
int u[22];

int dfs(int r) {
    if (r > n) return gs == T ? 1 : 0;
    int *d = g[r];
    fill(g[r],g[r]+r,0);
    for (int i = 1; i < r; ++i) d[u[i]] = 1;
    for (int i = 1; i < r; ++i)
        if (c[i][r]) d[u[i]] = 0;
    int ans = 0;
    for (int i = 1; i < r; ++i)
        if (d[i]) {
            u[r] = i;
            ans += dfs(r+1);
        }
    u[r] = r;
    if (gs >= T) return ans;
    ++gs;
    ans += dfs(r+1);
    --gs;
    return ans;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    cin >> n>>T>>m;
    for (int i = 0; i < m; ++i) {
        int u,v;cin>>u>>v;
        c[u][v] = c[v][u] = 1;
    }
    cout<<dfs(1) <<endl;
    return 0;
}

