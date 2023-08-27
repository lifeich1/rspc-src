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
#define TA(VEC, ...)                                                           \
  TRACE(cerr << #VEC << "= ";                                                  \
        for_each((VEC).begin(), (VEC).end(), [&](auto _) { __VA_ARGS__; }))
#define TI(HEAD, TAIL, ...)                                                    \
  TRACE(cerr << "[" #HEAD "," #TAIL ") = ";                                    \
        for_each((HEAD), (TAIL), [&](auto _) { __VA_ARGS__; }))
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR) << ' ')
using namespace std;
#define self_todo_placeholder

int f[2222][13];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  vector<pair<int, int>> e[12];
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y, v;
    cin >> x >> y >> v;
    --x, --y;
    e[x].emplace_back(y, v);
    e[y].emplace_back(x, v);
  }
  int M = 1 << n;
  int ans = 0;
  for (int i = 1; i < M; ++i) {
    for (int x = 0; x < n; ++x)
      if ((1 << x) & i) {
        for (auto [y, v] : e[x])
          if (((1 << y) & i) == 0) {
            auto t = i | (1 << y);
            int tv = v + f[i][x];
            f[t][y] = max(f[t][y], tv);
            ans = max(tv, ans);
          }
      }
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
