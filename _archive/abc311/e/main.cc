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

const int N = 3030;
int s[N][N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int h, w, n;
  cin >> h >> w >> n;
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    s[u][v]++;
  }
  auto sm = [&](int i, int j, int d) {
    return s[i][j] - s[i - d][j] - s[i][j - d] + s[i - d][j - d];
  };
  int64_t ans = 0;
  for (int i = 1; i <= h; ++i)
    for (int j = 1; j <= w; ++j) {
      int t = s[i][j];
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
      if (t)
        continue;

      int l = 1, r = min(i, j);
      while (l < r) {
        int md = (r + l + 1) >> 1;
        if (sm(i, j, md) > 0)
          r = md - 1;
        else
          l = md;
      }
      ans += l;
    }
  cout << ans << endl;

  return 0;
}

// vim: ts=2 sw=2
