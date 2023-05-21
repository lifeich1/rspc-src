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
int d[N];
set<int> e[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,q;cin>>n>>q;
    int ans = n;
    while(q--) {
        int op,u,v;cin>>op>>u;
        if (op==1) {
            cin>>v;
            if (0==d[u]++) --ans;
            if (0==d[v]++) --ans;
            e[u] .emplace(v);
            e[v] .emplace(u);
        } else {
            if (d[u]) ++ans;d[u] = 0;
            for (auto v:e[u]) {
                if (0==--d[v]) ++ans;
                e[v].erase(e[v].find(u));
            }
            e[u].clear();
        }
        cout<<ans<<endl;
    }
    return 0;
}

