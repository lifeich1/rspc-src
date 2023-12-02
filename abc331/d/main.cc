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
int a[N][N], n;
char st[N];

int64_t psum(int i, int j) {
  if (i < 0 || j < 0)
    return 0;
  int64_t ret = int64_t(a[n - 1][n - 1]) * (i / n) * (j / n);
  ret += int64_t(a[n - 1][j % n]) * (i / n);
  ret += int64_t(a[i % n][n - 1]) * (j / n);
  ret += a[i % n][j % n];
  return ret;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int Q;
  cin >> n >> Q;
  for (int i = 0; i < n; ++i) {
    cin >> st;
    for (int j = 0; j < n; ++j) {
      if (st[j] == 'B')
        a[i][j] = 1;
      if (i)
        a[i][j] += a[i - 1][j];
      if (j)
        a[i][j] += a[i][j - 1];
      if (i && j)
        a[i][j] -= a[i - 1][j - 1];
    }
  }
  while (Q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b;
    cout << (psum(c, d) - psum(a, d) - psum(c, b) + psum(a, b)) << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
