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

const int N = 1001;
int L[N], R[N], f[N][N][2], u[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n, k;
        cin >> n >> k;
        copy_n(std::istream_iterator<int> (cin) , n, L);
        copy_n(std::istream_iterator<int> (cin) , n, R);
        fill(u, u + n + 1, 0);
        for (int i = 0; i < n; ++i) {
            fill(u + L[i], u + R[i] + 1, 1);
        }
        int m = R[n - 1];
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= k; ++j) {
                f[i][j][0] = f[i][j][1] = -1;
            }
        f[0][0][0] = 0;
        auto upd = [](int &x, int v, int d) {
            if (-1 == v) return;
            v += d;
            if (-1 == x) x = v;
            else x = min(x, v);
        };
        TRACELN(cout << m << ' ' << k);
        int ans = -1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= k; ++j) {
                upd(f[i][j][0], f[i - 1][j][0], 1);

                if (u[i] && j > 0) {
                    upd(f[i][j][1], f[i - 1][j - 1][0], 2);
                    upd(f[i][j][1], f[i - 1][j - 1][1], 1);
                }

                upd(f[i][j][0], f[i][j][1], 1);
                TRACE(cout << f[i][j][0] << ','<<f[i][j][1]<<' ');
            }
            TRACELN();
            upd(ans, f[i][k][0], 0);
        }
        cout << ans << endl;
    }
    return 0;
}

