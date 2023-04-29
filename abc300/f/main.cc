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

const int N = 301001;
char s[N];
int h[N*3];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m;
    int64_t k;
    cin >> n >> m >> k >> s;
    int n0 = n;
    for (int i = 1; i <= n; ++i)
        h[i+n+n]=h[i] = h[i+n] = (s[i-1]=='x'?1:0);
    if (m==2) n*=2, m-=2;
    else if (m>2) n *= 3,m-=3;
    for (int i = 1; i <= n; ++i)
        h[i]+= h[i-1];
    int64_t a0 = n0;
    auto t = max(int64_t(0), k / h[n0] -1);
    a0 *= t;
    k -= h[n0]*t;
    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j<n&&h[j+1]-h[i]<=k)++j;
        ans = max(ans, j-i);
    }
    TRACELN(cout<< a0<<' '<<ans<<' '<<t);
    cout << a0+ans <<endl;
    return 0;
}

