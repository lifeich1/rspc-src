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

const int N = 2010;

int x[N],y[N],u[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,D;
    cin >>n>>D;
    D *= D;
    for (int i = 0; i < n;++i) cin >> x[i]>>y[i];
    u[0] = 1;
    vector<int> lis = {0};
    for (int i = 0; i < lis.size() ;++i) {
        int s = lis[i];
        for (int j = 0; j < n; ++j)
            if (!u[j]) {
                int d = 0;
                int t = (x[s]-x[j]);
                d += t * t;
                t = (y[s]-y[j]);
                d += t * t;
                if (d <= D) {
                    u[j] = 1;
                    lis.emplace_back(j);
                }
            }
    }
    for (int i = 0; i < n;++i) {
        cout<<(u[i] ? "Yes\n":"No\n");
    }
    return 0;
}

