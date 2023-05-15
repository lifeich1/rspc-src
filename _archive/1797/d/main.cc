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

const int N = 101001;
vector<int> ee[N];
int a[N], leaf[N], fa[N], cc[N];
int64_t sm[N];
set<pair<int,int>> ss[N];

int dfs(int x, int ff) {
    fa[x] = ff;
    int &c = cc[x];
    c = 1;
    sm[x] = a[x];
    for (auto e : ee[x]) {
        if (e != ff) {
            auto tc = dfs(e, x);
            ss[x].emplace(tc, -e);
            c += tc;
            sm[x] += sm[e];
        }
    }
    return c;
}

void rotat(int x) {
    if (!ss[x].size()) return;
    auto ff = fa[x];
    auto u = - ss[x].rbegin()->second;
    auto it = ss[x].end();
    ss[x].erase(--it);
    fa[u] = ff;
    auto tsm = sm[u];
    sm[u] = sm[x];
    auto tsmx = sm[x];
    sm[x] -= tsm;
    auto tc = cc[x];
    cc[x] -= cc[u];
    cc[u] = tc;
    ss[u].emplace(cc[x], -x);
    fa[x] = u;

    ss[ff].erase(ss[ff].find(make_pair(tc, -x)));
    ss[ff].emplace(tc, -u);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m; cin >> n >> m;
    copy_n(std::istream_iterator<int> (cin), n, a+1);
    for (int i = 1, u,v; i < n; ++i) {
        cin >> u >> v;
        ee[u] .push_back (v);
        ee[v] .push_back (u);
    }
    dfs(1, 1);
    while (m--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) cout << sm[x] << endl;
        else rotat(x);
    }
    return 0;
}

