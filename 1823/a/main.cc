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


int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    auto C = [](int x) { return x * (x - 1) / 2; };
    int tt; cin >> tt; while (tt--) {
        int n, k; cin >> n >> k;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int t = C(i) + C(n - i);
            if (t == k) {
                ans = i; break;
            }
        }
        if (ans != -1) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) cout << (i < ans ? 1 : -1) << ' ';
            cout << endl;
        } else cout << "NO\n";
    }
    return 0;
}

