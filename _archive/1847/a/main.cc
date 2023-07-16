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

int f[105][105],a[105];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n,K; cin >>n>>K;
        copy_n(std::istream_iterator<int>(std::cin) ,n,a);
        for (int i = 1; i < n; ++i) {
            f[i][1] = f[i-1][1] + abs(a[i]-a[i-1]);
            for (int j = 2; j <= K && j <= i; ++j) {
                f[i][j] = min(f[i-1][j] + abs(a[i]-a[i-1]), f[i-1][j-1]);
            }
            if (i < K) f[i][i+1] = 0;
        }
        cout<<*min_element(f[n-1]+1,f[n-1]+K+1)<<endl;
    }
    return 0;
}

