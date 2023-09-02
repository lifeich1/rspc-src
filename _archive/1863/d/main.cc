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

const int N = 505;
char c[N][N], d[N][N], o[N];

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
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
      copy_n(c[i], m + 1, d[i]);
    }
    bool ok = true;

    for (int i = 0; i < n; ++i) {
      int l = 0;
      for (int j = 0; j < m; ++j) {
        if (c[i][j] == 'U') {
          if (l)
            d[i][j] = 'B', o[j] = 'W';
          else
            d[i][j] = 'W', o[j] = 'B';
          l ^= 1;
        } else if ('D' == c[i][j]) {
          d[i][j] = o[j];
        }
      }
      if (l) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    for (int j = 0; j < m; ++j) {
      int l = 0;
      for (int i = 0; i < n; ++i) {
        if ('L' == c[i][j]) {
          if (l)
            d[i][j] = 'B', o[i] = 'W';
          else
            d[i][j] = 'W', o[i] = 'B';
          l ^= 1;
        } else if ('R' == c[i][j]) {
          d[i][j] = o[i];
        }
      }
      if (l) {
        ok = false;
        break;
      }
    }
    if (ok) {
      for (int i = 0; i < n; ++i)
        cout << d[i] << endl;
    } else
      cout << "-1\n";
  }
  return 0;
}

// vim: ts=2 sw=2
