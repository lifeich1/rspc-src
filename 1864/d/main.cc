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

const int N = 3030;
int s[N][N], a[N], b[N];
char ss[N];

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
    int n;
    cin >> n;
    fill(a, a + n, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      fill(s[i], s[i] + n, 0);
      copy_n(a, n, b);
      fill(a, a + n, 0);
      cin >> ss;
      for (int j = 0; j < n; ++j) {
        int y = ss[j] - '0';
        int x = 0;
        if (i > 0) {
          x += b[j];
          if (j > 0)
            x += s[i - 1][j - 1];
          if (j + 1 < n)
            x += s[i - 1][j + 1];
          if (j > 0 && j + 1 < n && i > 1) {
            x -= s[i - 2][j];
          }
        }
        s[i][j] = x;
        if ((x & 1) != (y & 1))
          ++s[i][j], ++ans, a[j] = 1;
        else
          a[j] = 0;
      }
      TLN(TI(a, a + n, cerr << _));
    }
#if defined(RSPC_TRACE_HINT)
    for (int i = 0; i < n; ++i) {
      TLN(copy_n(s[i], n, std::ostream_iterator<int>(std::cerr, " ")));
    }
#endif
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
