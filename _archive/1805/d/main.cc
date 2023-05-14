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
int u0[N], u[N], d[N], f[N], sz[N], h[N];

void dfs(int x, int* u) {
    for (auto y : e[x]) {
        if (0 == u[y]) u[y] = u[x] + 1, dfs(y, u);
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
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v] .push_back (u);
    }
    u0[1] = 1;
    dfs(1, u0);
    auto ed = max_element(u0 + 1, u0 + 1 + n) - u0;
    TRACELN(cout << ed);
    u[ed] = 1;
    dfs(ed, u);
    auto L = *max_element(u + 1, u + 1 + n);
    fill(u0, u0 + n + 1, 0);
    auto ed2 = max_element(u + 1, u + 1 + n) - u;
    u0[ed2] = 1;
    dfs(ed2, u0);

    fill(f, f + n, -1);
#if 0
    auto fa = [&]( int x) -> int& {
        if (f[x] == -1) f[x] = x, sz[x] = 1;
        if (f[x] == x) return f[x];
        f[x] = fa(x);
        return fa(x);
    };
    auto uni = [&]( int x, int y) {
        x = fa(x), y = fa(y);
        if (sz[x] < sz[y]) swap(x, y);
        sz[x]+= sz[y];
        fa(y) = x;
    };
#endif

    transform(u0+1, u0 + n+1, u+1, d+1, [&]( int d1, int d2) {return max(d1, d2);});
    for (int i = 0; i < n; ++i) h[i] = i+1;
    sort(h, h + n, [&]( int x, int y) {
                return d[x] < d[y];
            });
    TRACELN(cout<<ed<<' '<<ed2);
    TRACELN(copy_n(d+1, n, std::ostream_iterator<int> (cout, " ")));

    vector<int> ans;
    ans.resize(n);
        int a = n;
    for (int i = n, t = n-1; i > 0; --i) {
        while (t>= 0&& d[h[t]]>i) {
            auto x = h[t];
            if (x != ed)
            {
                --a;
            }--t;
        }
        ans[i-1] = a;
    }
    copy(ans.begin(), ans.end(), std::ostream_iterator<int> (cout," "));
    cout<<endl;

    return 0;
}

