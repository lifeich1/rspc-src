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
int u[N],f[N],lis[N+N],l1[N];
set<int> e[N];
vector<int> s[N],ss[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,m, tt=0;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        for (int j = 0,x; j < a;++j) {
            cin>>x;
            s[x] .emplace_back(i);
            ss[i] .emplace_back (x);
            if (x == 1) lis[tt++] = i,f[i]=1;
            if (x == m) l1[i] = 1;
        }
    }
    int ans = -1;
    for (int pp = 0; pp < tt && ans < 0;++pp) {
        auto x = lis[pp];
        if (x >= 0) {
            if (l1[x]) {ans = f[x]-1; break;}
            for (int y : ss[x]) {
                if (0==u[y]) {
                    u[y] = f[x];
                    lis[tt++] = -y;
                }
            }
        } else {
            x=-x;
            for (int y:s[x]) {
                if (0==f[y]) {
                    f[y] = u[x]+1;
                    lis[tt++] = y;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

