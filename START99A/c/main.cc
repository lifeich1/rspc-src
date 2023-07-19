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

    vector<int> u;
    vector<pair<int,int>> h;
    int tt; cin >> tt; while (tt--) {
        int n; cin >>n;
        u.clear();
        u.resize(n+1,0);
        h.clear();
        h.reserve(n*2);
        int ans = -1;
        auto upd = [&](int x) {
            x = abs(x);
            if (ans < 0 || ans > x) ans = x;
        };
        for (int i = 1; i <= n; ++i) {
            int u,v; cin >>u>>v;
            h.emplace_back(u, -i);
            h.emplace_back(v, i);
        }
        sort(h.begin(),h.end());
        for (int i = n+n-1; i >= 2; --i) {
            int t = h[i-1].first;
            if (h[i].second == -h[i-1].second) {
                t = h[i-2].first;
            }
            upd(h[i].first - t);
            int p = abs(h[i].second);
            if (u[p]) break;
            u[p] = 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}

