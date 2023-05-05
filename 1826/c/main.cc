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
int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    vector<int> ps;
    for (int i = 2; i < N; ++i)
        if (!a[i]) {
            ps .push_back (i);
            for (int j = i+i; j<N;j+=i)
                a[j]=1;
        }

    int tt; cin >> tt; while (tt--) {
        int n, m; cin >> n>> m;
        bool ans = (n > m) || (1 == n);
        if (ans)
        for (auto p : ps) {
            if (p > m) break;
            if (n % p == 0) {
                ans = false;break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}

