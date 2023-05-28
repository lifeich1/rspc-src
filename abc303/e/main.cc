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
vector<int> e[N],ans;
void dfs(int x, int ph, int fa = 0) {
    if (ph ==1) {
        ans .emplace_back (e[x].size());
    }
    for (int y : e[x]) if (y != fa) {
        dfs(y, (ph + 1) % 3, x);
    }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin >> n;
    for (int i = 1,u,v; i < n;++i) {
        cin>>u>>v;
        e[u] .emplace_back(v);
        e[v] .emplace_back(u);
    }
    int st = 1;
    for (int i = 1; i <=n;++i)
        if(e[i].size()==1) {
            st = i; break;
        }
    dfs(st, 0);
    sort(ans.begin(), ans .end());
    copy(ans.begin(),ans.end(), std::ostream_iterator<int>(std::cout, " "));
    cout<<endl;
    return 0;
}

