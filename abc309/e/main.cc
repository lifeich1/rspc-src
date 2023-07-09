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

const int N = 301001;
int pa[N],f[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,m; cin >>n>>m;
    for (int i = 2; i <= n; ++i) cin>>pa[i];
    for (int i = 0; i < m; ++i) {
        int u,v; cin >> u>>v;
        f[u] = max(f[u], v+1);
    }
    for (int i = 2; i <= n; ++i) {
        int t = f[pa[i]]-1;
        f[i] = max(f[i] ,t);
    }
    cout<<count_if(f+1,f+n+1, [](int u) { return u>0; })<<endl;
    return 0;
}

