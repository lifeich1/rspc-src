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

const int N = 505;
int f[N][N],a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--)
    {
        int n; cin >>n;
        copy_n(std::istream_iterator<int>(std::cin),n,a+1);
        for (int i = 0; i <= n; ++i) fill(f[i],f[i]+n+1,99999);
        f[1][0] = f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i][1] = i - 1;
            if (i > 1 && a[i] > a[i-1]) {
                for (int j = 0; j <= n; ++j) f[i][j] = min(f[i][j], f[i-1][j]);
            }
            for (int p = 1; p < i; ++p)
                if (a[p] < a[i]) {
                    for (int k = 0; k < n; ++k) {
                        f[i][k+1] = min(f[i][k+1], f[p][k] + i - p-1);
                    }
                }
        }
        for (int i = 1; i < n; ++i)
            for (int j = 0; j <= n; ++j)
            {
                int t = (n - i) + f[i][j];
                f[n][j+1] = min(f[n][j+1], t);
            }
        for (int i = 2; i <= n; ++i) f[n][i] = min(f[n][i], f[n][i-1]);
        copy_n(f[n]+1,n, std::ostream_iterator<int>(std::cout, " ") );
        cout<<endl;
    }
    return 0;
}

