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

const int N = 1010;
int D[N][N];
int64_t f[N], g[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, A, B, C;
  cin >> n >> A >> B >> C;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> D[i][j];
  set<pair<int64_t, int>> ls;
  for (int i = 2; i <= n; ++i) {
    f[i] = int64_t(D[1][i]) * A;
    ls.emplace(f[i], i);
  }
  while (ls.size() > 0) {
    auto [v, x] = *ls.begin();
    ls.erase(ls.begin());
    if (v != f[x])
      continue;
    for (int i = 2; i <= n; ++i) {
      auto t = v + int64_t(D[x][i]) * A;
      if (f[i] > t) {
        f[i] = t;
        ls.emplace(t, i);
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    g[i] = int64_t(D[i][n]) * B + C;
    ls.emplace(g[i], i);
  }
  while (ls.size() > 0) {
    auto [v, x] = *ls.begin();
    ls.erase(ls.begin());
    if (v != g[x])
      continue;
    for (int i = 1; i < n; ++i) {
      auto t = v + int64_t(D[i][x]) * B + C;
      if (g[i] > t) {
        g[i] = t;
        ls.emplace(t, i);
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    f[i] += g[i];
  cout << *min_element(f + 1, f + n + 1) << endl;
  return 0;
}

// vim: ts=2 sw=2
