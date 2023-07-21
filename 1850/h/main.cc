#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...)                                                             \
  do {                                                                         \
    __VA_ARGS__;                                                               \
  } while (0)
#else
#define TRACE(...) (void)0
#endif
#define TLN(...) TRACE(__VA_ARGS__; cerr << endl)
#define TA(VEC, ITEM, ...)                                                     \
  TRACE(cerr << #VEC << "= ";                                                  \
        for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR))
using namespace std;
#define self_todo_placeholder

const int N = 201001;
vector<pair<int, int>> e[N];
int64_t a[N];
int u[N];

void dfs(int r) {
  u[r] = 1;
  for (auto [y, d] : e[r]) {
    a[y] = a[r] + d;
    if (0 == u[y])
      dfs(y);
  }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    fill(u, u + n + 1, 0);
    for_each(e, e + n + 1, [](auto &e) { e.clear(); });
    for (int i = 0; i < m; ++i) {
      int u, v, d;
      cin >> u >> v >> d;
      e[u].emplace_back(v, d);
      e[v].emplace_back(u, -d);
    }
    fill(a, a + n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      if (0 == u[i])
        dfs(i);
    }
    bool ok = true;
    for (int i = 1; i <= n && ok; ++i) {
      for (auto [y, d] : e[i])
        if (a[y] - a[i] != int64_t(d)) {
          ok = false;
          break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}

// vim: ts=2 sw=2
