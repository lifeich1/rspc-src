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
int c[N],u[N],pa[N],sz[N];
vector<int> e[N];

bool dfs(int r) {
    u[r] = 1;
    for (int y : e[r]) {
        if (c[y] != c[r]) {
            if (u[y] == 0 && dfs(y)) return true;
        } else {
            if (u[y] == 1) return true;
        }
    }
    u[r] = 2;
    return false;
}

int & fa(int x) {
    if (x == pa[x]) return pa[x];
    int &r = fa(pa[x]);
    pa[x] = r ;
    return r;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m;cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int u,v; cin >>u>>v;
        e[u] .emplace_back(v);
        e[v] .emplace_back(u);
    }
    copy_n(std::istream_iterator<int>(std::cin),n,c+1);
    for (int i = 1; i <= n; ++i) {
        sz[i] = 1;
        pa[i] = i;
    }
    for (int i = 1; i <= n; ++i)
        for (int y : e[i]) {
            if (c[i] != c[y]) {
                ++u[i];
                int l = fa(i);
                int r = fa(y);
                if (l != r) {
                    if (sz[l] < sz[r]) swap(l, r);
                    fa(r) = l;
                    sz[l] += sz[r];
                }
            }
        }
    bool ok = false;
    for (int i = 1; i <= n && !ok; ++i)
        for (int y : e[i]) {
            if (c[i] == c[y] && fa(i) == fa(y)) {
                ok = true;
                break;
            }
        }
    if (ok) {
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }
    return 0;
}

