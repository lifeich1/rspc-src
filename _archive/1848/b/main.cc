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

const int N = 201001;
vector<int> p[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
        vector<int > d;

    int tt; cin >> tt; while (tt--) {
        int n, m; cin >>n>>m;
        for_each(p,p+m+1, [](auto &v){v.clear();});
        for (int i = 0; i < n; ++i) {
            int x; cin>>x;
            p[x].emplace_back(i);
        }
        int ans = n;
        for (int i = 1; i <= m; ++i) {
            if (p[i].empty()) continue;
            d.clear();
            d.emplace_back(p[i].front());
            d.emplace_back(n-1-p[i].back());
            for (int j = 1; j < p[i].size(); ++j) {
                d.emplace_back(p[i][j] - p[i][j-1]-1);
            }
            sort(d.begin(),d.end());
            d.back() /= 2;
            ans = min(ans, *max_element(d.begin(), d.end()));
        }
        cout<<ans<<endl;
    }
    return 0;
}

