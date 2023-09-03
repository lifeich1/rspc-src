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

int d[20][20];
int64_t f[1 << 17];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      cin >> d[i][j];
      d[j][i] = d[i][j];
    }
  int m = 1 << n;
  int64_t ans = 0;
  for (int i = 0; i < m; ++i) {
    if (__builtin_popcount(i) & 1)
      continue;
    for (int l = 0; l < n; ++l) {
      if ((1 << l) & i)
        continue;
      for (int r = l + 1; r < n; ++r) {
        if ((1 << r) & i)
          continue;
        int t = i | (1 << l) | (1 << r);
        f[t] = max(f[t], f[i] + d[l][r]);
      }
    }
    ans = max(ans, f[i]);
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
