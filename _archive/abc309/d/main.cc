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
vector<int> e[N];
int f[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n1,n2,m; cin >> n1>>n2>>m;
    for (int i = 0; i < m; ++i) {
        int u,v;cin>>u>>v;
        e[u] .emplace_back(v);
        e[v] .emplace_back(u);
    }
    vector<int> lis = {1, n1+n2};
    lis.reserve(n1+n2);
    f[1] = f[n1+n2] = 1;
    for(int i = 0; i < lis.size(); ++i) {
        int x = lis[i];
        for (auto y :e[x]) {
            if (0 == f[y]) {
                f[y] = f[x]+1;
                lis.emplace_back(y);
            }
        }
    }
    cout<<(*max_element(f+1,f+1+n1) + *max_element(f+n1+1,f+n1+n2+1) - 1)<<endl;
    return 0;
}

