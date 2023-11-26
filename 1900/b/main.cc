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

int f[311][311][311];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  for (int i = 1; i <= 300; ++i) {
    f[i][0][0] = 1;
    f[0][i][0] = 2;
    f[0][0][i] = 4;
  }
  for (int s = 1; s <= 300; ++s)
    for (int j = 0; j <= s; ++j)
      for (int k = 0; k <= s - j; ++k) {
        int i = s - k - j;
        if (i < 0)
          break;
        if (i > 0) {
          if (j > 0)
            f[i][j][k] |= f[i - 1][j - 1][k + 1];
          if (k > 0)
            f[i][j][k] |= f[i - 1][j + 1][k - 1];
        }
        if (j > 0 && k > 0)
          f[i][j][k] |= f[i + 1][j - 1][k - 1];
      }

  int tt;
  cin >> tt;
  while (tt--) {
    int i, j, k;
    cin >> i >> j >> k;
    auto v = f[i][j][k];
    for (int k = 0; k < 3; ++k, v >>= 1)
      cout << (v & 1) << ' ';
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
