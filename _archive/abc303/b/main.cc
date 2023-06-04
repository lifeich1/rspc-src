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

const int N = 55;
int c[N][N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,m; cin >>n>>m;
    while(m--) {
        int l;
        cin >>l;
        for (int i = 1,x; i < n; ++i) {
            cin>>x;
            c[l][x] = c[x][l] = 1;
            l= x;
        }
    }
    int ans = 0;
    for (int i = 1; i <=n;++i)
        for (int j = 1; j < i; ++j)
            if (0==c[i][j]){++ans;
                TRACELN(cout<<':'<<j<<' '<<i);
            }
    cout<<ans<<endl;
    return 0;
}

