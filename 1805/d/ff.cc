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


const int N = 1000;
vector<int> e[N];
int c[N][N];
int u[N], K, n;

void dfs(int rt, int x, int d) {
    c[rt][x] = d;
    for (auto y : e[x])
        if (c[rt][y] == 0 && y != rt)
            dfs(rt, y, d + 1);
}
void dfs(int x) {
    u[x] = K;
    for (int i = 1; i <= n; ++i)
        if (u[i] != K && c[x][i] >= K) dfs(i);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    cin >> n;
    for (int i = 0, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u] .push_back (v);
        e[v] .push_back (u);
    }

    cout << 1;
    for (int i = 1; i <= n; ++i) dfs(i, i, 0);
    for (K = 2; K <= n; ++K) {
        int cn = 0;
        for (int i = 1; i <= n; ++i)
            if (u[i] != K) {
                dfs(i);
                ++cn;
            }
        cout << ' ' << cn;
    }
    cout << " \n";
    return 0;
}

