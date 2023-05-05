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
int h[N];

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
    for (int i = 1; i <= n; ++i) h[i] = (s[i-1]=='x'?1:0);
    for (int i = 1; i <= n; ++i) h[i]+= h[i-1];
    auto cnt = [&](int64_t r) -> int64_t {
        return h[n] * (r / n) + h[r % n];
    };
    int64_t ans = 0, rr = m, j = 1;
    rr *= n;
    for (int i = 0; i < n; ++i) {
        int64_t target = h[i] + k, l, r, t;
        for (l = j, r = rr; l < r; ) {
            t = (l + r + 1) >> 1;
            if (cnt(t) <= target) l = t;
            else r = t - 1;
        }
        j = l;
        ans = max(ans, j - i);
    }
    cout << ans <<endl;
    return 0;
}

