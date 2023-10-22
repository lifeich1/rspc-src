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

const int N = 111;
int d[N], f[N][N * 10];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> d[i];
  int L1, C1, K1, L2, C2, K2;
  cin >> L1 >> C1 >> K1 >> L2 >> C2 >> K2;
  for (int i = 1; i <= n; ++i)
    fill(f[i], f[i] + K1 + 1, K2 + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= K1; ++j) {
      int t0 = max(0, d[i] - j * L1);
      if (t0 > 0)
        t0 = (t0 - 1) / L2 + 1;
      for (int nj = j; nj <= K1; ++nj) {
        int t = t0 + f[i - 1][nj - j];
        if (f[i][nj] > t)
          f[i][nj] = t;
      }
      if (0 == t0)
        break;
    }
  int64_t ans = -1;
  for (int i = 0; i <= K1; ++i)
    if (f[n][i] <= K2) {
      int64_t t = C1;
      t *= i;
      t += int64_t(C2) * f[n][i];
      if (-1 == ans || ans > t)
        ans = t;
    }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
