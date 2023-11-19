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

char c[2][20][20];

char rv(char ch) { return ch == 'R' ? 'B' : 'R'; }

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
    int n, m, K;
    cin >> n >> m >> K;
    int t = n + m - 2;
    if (K < t || (K - t) % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        c[0][i][j] = c[1][i][j] = 'R';
    c[0][1][0] = 'B';
    for (int i = 1; i < m - 1; i += 2)
      c[0][0][i] = 'B';
    c[1][0][m - 1] = rv(c[0][0][m - 2]);
    for (int i = 1; i < n - 1; ++i) {
      c[1][i][m - 1] = rv(c[1][i - 1][m - 1]);
      TLN(TV(c[1][i][m - 1]); TV(i); TV(m - 1));
    }
    c[0][n - 1][m - 2] = c[0][n - 2][m - 2] = rv(c[1][n - 2][m - 1]);
    c[1][n - 2][m - 2] = c[1][n - 2][m - 1];
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m - 1; ++j)
        cout << c[0][i][j] << ' ';
      cout << endl;
    }
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < m; ++j)
        cout << c[1][i][j] << ' ';
      cout << endl;
    }
  }
  return 0;
}

// vim: ts=2 sw=2
