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

int u[101001];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    const int64_t M = 998244353;
    int n; string s;
    cin >> n>>s;
    int n12 = n / 2;
    int64_t ans = 0;
    
    map<int,int64_t> aa;
    for (int i = 1; i <= n12; ++i) {
        if (n % i != 0) continue;
        fill(u,u+i, 0);
        for (int j = 0; j < n; ++j) {
            if (s[j] == '.' )u[j%i]|=1;
        }
        int64_t t = 1;
        for (int j = 0; j < i;++j)
            if (u[j] == 0) {
                t <<=1;
                if (t >= M) t -= M;
            }
        aa[i] = t;
    }
    for (auto [k,v] : aa) {
        ans = (ans +v)%M;
        for (auto & [kk, vv] : aa) {
            if (kk > k && kk % k == 0) {
                vv = (vv + M - v) % M;
            }
        }
    }
    cout<< ans<<endl;
    return 0;
}

