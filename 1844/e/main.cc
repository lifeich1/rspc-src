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

vector<int> e[4040];
int u[4040];
int n,m,K;
bool ans;

void dfs(int x) {
    for (int t : e[x]) {
        int p = u[x], y = t;
        if (y < 0) {
            y = -y; p ^= 1;
        }
        if (u[y] < 0) {
            u[y] = p;
            dfs(y);
            if (!ans) break;
        } else if (u[y] != p) {
            ans = false;
            return;
        }
    }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        ; cin >>n>>m>>K;
        for_each(e,e+n+m+1, [](auto &v) {v.clear();});
        for (int i = 0; i < K; ++i) {
            int x[4]; copy_n(std::istream_iterator<int>(std::cin),4,x);
            if (x[3] > x[1]) { // \: -1,1
                e[x[0]] .emplace_back(-(x[1]+n));
                e[x[1]+n] .emplace_back(-x[0]);
            } else { // /: 1,1
                e[x[0]].emplace_back(x[3]+n);
                e[x[3]+n].emplace_back(x[0]);
            }
        }
        fill(u,u+n+m+1,-1);
        ans = true;
        for (int i = 1; i <= n+m && ans; ++i)
            if (u[i] < 0) {
                u[i] = 0;
                dfs(i);
            }
        cout<<(ans?"YES\n":"NO\n");
    }
    return 0;
}

