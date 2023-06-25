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

int64_t c[111][111];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        fill(c[i],c[i]+n+1,-1);
        c[i][i] = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int u,v,y;cin>>u>>v>>y;
        c[u][v] = c[v][u] = y;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i) if (c[i][k] >= 0)
            for (int j = 1; j <= n; ++j) if (c[k][j] >= 0)
            {
                auto t = c[i][k]+c[k][j];
                if (c[i][j] <0||c[i][j] > t) c[i][j]=t;
            }
    if (c[1][n] < 0) {
        cout<< "inf\n";return 0;
    }
    vector<int64_t> d = {c[1][n]};
    for (int i = 2; i < n; ++i)
        if (c[1][i] > 0 && c[1][i] < c[1][n]) d.emplace_back(c[1][i]);
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(),d.end()),d.end());
    cout<< c[1][n] << ' '<<d.size()<<endl;
    int64_t la = 0;
    for (auto l : d) {
        for (int i = 1; i <= n; ++i)
            cout<< (c[1][i] < l&&c[1][i]>=0?1:0); 
        cout <<" " << l - la<<endl;
        la = l;
    }
    return 0;
}

