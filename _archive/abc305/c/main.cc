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

    map<int,int> rc,cc,r1,r2;
    int n,m; cin >> n>>m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            char ch; cin >> ch;
            if (ch == '#') {
                rc[i]++; cc[j]++;
            }
        }
    for (auto [k,v]:rc) r1[v] = k;
    for (auto [k,v]:cc) r2[v] = k;
    cout << r1.begin()->second<<' '<<r2.begin()->second<<endl;
    return 0;
}

