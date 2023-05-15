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

const int N = 2020;
vector<int> e[N];
vector<pair<int,int>> ans;
int u[N], uf;

int dfs(int x, int pa, int rt) {
    u[x] = uf;
    if (pa != rt) {
        for (auto y : e[x])
            if (y == rt) {
                ans.emplace_back(x, y);
                return x;
            }
    }
    for (auto y : e[x]) {
        if(u[y]==uf) continue;
        int t = dfs(y, x, rt);
        if (t) {
            ans.emplace_back(x, y);
            if (x == rt) {
                int c = 2;
                for (auto v : e[x]) {
                    if (v !=t&&v != y) {ans.emplace_back(x, v);
                    if (--c==0) break;
                    }
                }
            }
            return t;
        }
    }
    return 0;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m;
    int tt; cin >> tt; while (tt--) {
        cin >> n >> m;
        fill(u, u+n+1, 0);
        uf = 0;
        for (int i = 1; i <= n; ++i) e[i].clear();
        for (int i = 0, x, y; i < m; ++i) {
            cin >> x >> y;
            e[x]. push_back (y);
            e[y]. push_back (x);
        }
        bool no = true;
        for (int i = 1; i <= n;++i)
            if (e[i].size() >= 4) {
                ++uf;
                ans.clear();
                if (dfs(i, i, i)) {
                    TRACELN(cout<<':'<<i);
                    cout << "YES\n";
                    cout << ans.size()<<endl;;
                    for (auto [x, y] : ans)
                        cout << x << ' '<<y << endl;
                    no = false;
                    break;
                }
            }
        if (no) cout<<"NO\n";
    }
    return 0;
}

