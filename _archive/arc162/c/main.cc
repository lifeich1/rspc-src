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

const int N = 1010;
int pa[N],a[N],no[N],u[N];
set<int> s[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n,K; cin>>n>>K;
        for (int i = 2; i <= n; ++i) cin >> pa[i];
        for (int i = 1; i <= n; ++i) {
            s[i].clear();
            cin >>a[i];
            u[i] = no[i] = 0;
            if (a[i] == K) no[i] = 1;
            else if (a[i] < K && a[i] >= 0) s[i].emplace(a[i]);
            else if (a[i] < 0) u[i] = 1;
        }
        bool ans = false;
        for (int i = n; i > 0; --i) {
            if (no[i]) no[pa[i]] = 1;
            u[pa[i]] += u[i];
            if (u[i] <= 1 && 0 == no[i]) {
                if (s[i].size() >= K-u[i]) {
                    ans = true; break;
                }
            }
            if (i != 1)
                for (auto e : s[i]) s[pa[i]].emplace(e);
        }
        cout<<(ans?"Alice\n":"Bob\n");
    }
    return 0;
}

