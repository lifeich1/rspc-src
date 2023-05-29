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

const int N = 110;
int64_t _f[2][N][N];
int c[N];
int64_t w[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, K; cin >> n>>K;
    auto * f = _f[0]; auto *g = _f[1];
    copy_n(std::istream_iterator<int64_t>(std::cin),K,w+1);
    for (int i = 1; i <= n; ++i) {
        int t; cin >> t;
        c[t] = i;
    }
    auto cl = [&](auto * g) {
        for (int i = 1; i <= n; ++i)
            fill(g[i] + i, g[i] + n + 1, -1);
    };
    cl(f);
    for (int i = 1; i < n; ++i) {
        TRACE(cout<<c[i]<<' ');
        f[i][i] = 0;
        for (int j = i + 1; j <= n; ++j) 
            if (c[j-1] < c[j]) f[i][j] = 0;
            else break;
    }
    f[n][n] = 0;
    TRACELN(cout<<c[n]);
    for (int k = K; k > 0; --k) {
        swap(g, f);
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)  {
                auto & v = f[i][j];
                v = g[i][j];
                for (int p = i; p < j; ++p) {
                    auto lc = g[i][p], rc = g[p+1][j];
                    if (lc < 0 || rc < 0) continue;
                    auto t = lc + rc + w[k] * (j - p);
                    if (v < 0 || v > t) {
                        v = t;
                        TRACELN(cout<<"#"<<k<<' '<<i<<' '<<p<<' '<<j<<' '<<v);
                    }
                }
            }
    }
    cout << f[1][n] << endl;
    return 0;
}

