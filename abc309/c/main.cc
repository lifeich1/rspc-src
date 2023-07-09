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

    int n,m; cin>>n>>m;
    vector<pair<int,int>> a;
    a .emplace_back(0,0);
    for (int i = 0; i < n; ++i) {
        int u,v;cin>>u>>v;
        a.emplace_back(u,v);
    }
    sort(a.begin(), a.end());
    for (int i = n; i >= 0; --i) {
        auto[u,v] = a[i];
        if (m >= v) {
            m -= v;
        } else {
            cout<< u+1<<endl;
            return 0;
        }
    }
    cout<<"1\n";
    return 0;
}

