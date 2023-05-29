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

const int N = 201001;
vector<pair<int,int>> e[N];
int u[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        for(int i = 0; i <=n;++i) e[i].clear();
        set<pair<int,int>> pe, qe;
        for (int i = 1; i < n;++i) {
            int x,y ;cin>>x>>y;
            e[x] .emplace_back (y, i);
            e[y] .emplace_back (x, i);
            if (x == 1 || y == 1) pe.emplace(i, max(x, y));
        }
        fill(u, u + n+1, 0);
        u[1] = 1;
        int ans = 0;
        while(pe.size()) {
            qe.clear();
            while(pe.size()) {
                auto [i, y] = *pe.begin();
                pe.erase(pe.begin());
                if (!u[y]) {
                    TRACELN(cout<<' '<<i<<' '<<y);
                    u[y] = 1;
                    for (auto [ty, ti] : e[y]) {
                        if (!u[ty]) {
                            if (ti <= i) qe.emplace(ti, ty);
                            else pe.emplace(ti, ty);
                        }
                    }
                }
            }
            qe.swap(pe);
            ++ans;
            TRACELN(cout<<':'<<ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}

