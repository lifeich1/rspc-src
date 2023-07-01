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
vector<int> e[N], ew[N];
int f[N],ans[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m; cin >>n>>m;
    fill(ans,ans+n+1, -1);
    fill(f,f+n+1, -1);
    for (int i = 0; i < m; ++i) {
        int u,v,w; cin >> u>>v>>w;
        e[u] .emplace_back(v);
        e[v] .emplace_back(u);
        ew[u] .emplace_back(w);
        ew[v] .emplace_back(w);
    }
    set<pair<int,int>> fni;
    int K; cin >> K;
    auto upd = [&](int x, int v) {
        if (f[x] < 0 || f[x] > v) {
            f[x] = v;
            fni.emplace(v, x);
        }
    };
    while(K--) {
        int i; cin >> i;
        ans[i] = 0;
        for(int p = 0; p < e[i].size(); ++p) {
            upd(e[i][p], ew[i][p]);
        }
    }
    int D; cin >> D;
    for (int dd = 1; dd <= D; ++dd) {
        int lim; cin >> lim;
        vector<int> ns;
        while (fni.size()) {
            auto [v, x] = *fni.begin();
            if (v > lim) break;
            fni.erase(fni.begin());
            if (ans[x] != -1) continue;
            if (f[x] != v) continue;
            ans[x] = dd;
            ns.emplace_back(x);
            for (int p = 0; p < e[x].size(); ++p) {
                upd(e[x][p], v+ew[x][p]);
            }
        }
        for (int x : ns) {
            for (int p = 0; p < e[x].size(); ++p) {
                upd(e[x][p], ew[x][p]);
            }
        }
    }
    copy_n(ans+1,n, std::ostream_iterator<int>(std::cout, "\n"));
    return 0;
}

