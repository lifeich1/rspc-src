#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
using namespace std;
#define self_todo_placeholder

const int N = 22;
int c[N][N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) fill(c[i], c[i] + n + 1, 0);
    for (int i = 1; i <= n; ++i) c[i][i] = 1;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        c[x][y] = c[y][x] = 1;
    }
    bool flag = true;
    for (int i = 1; i <= n && flag; ++i) {
        for (int j = 1; j < i; ++j) {
            if (!c[i][j]) continue;
            bool bl = true;
            for (int k = 1; k <= n; ++k)
                if (!c[k][i] && !c[k][j]) {
                    bl = false;
                    break;
                }
            if (bl) {
                flag = false;
                cout << "YES\n";
                for (int k = 1; k <= n; ++k)
                    if (c[k][i] && k != i) cout << i << ' ';
                    else cout << j << ' ';
                cout << endl;
                break;
            }
        }
    }
    if (flag) cout << "NO\n";
    return 0;
}

