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

const int N = 101;
int a[N][N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, K; cin >> n >> K;
    for (int i = 0; i < n; ++i)
        copy_n(std::istream_iterator<int> (cin), n, a[i]);
    for (int p = 0; p < n; ++p)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (!a[i][p] || !a[p][j]) continue;
                int t = a[i][p] + a[p][j];
                if (a[i][j] == 0 || t < a[i][j]) {
                    a[i][j] = t;
                }
            }
    int q;
    cin >> q;
    while (q--) {
        int64_t x, y;
        cin >> x >> y;
        x--, y--;
        if (x == y) cout << "0\n";
        else {
            x %= n, y %= n;
            if (a[x][y]) cout << a[x][y] << endl;
            else cout << "-1\n";
        }
    }
    return 0;
}

