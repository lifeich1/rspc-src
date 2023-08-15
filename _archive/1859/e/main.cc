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
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR) << ' ')
using namespace std;
#define self_todo_placeholder

const int N = 3013;
int64_t a[N], b[N];
int64_t g[4][N], f[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int64_t tmp[5];
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    copy_n(std::istream_iterator<int64_t>(std::cin), n, a);
    copy_n(std::istream_iterator<int64_t>(std::cin), n, b);
    fill(f, f + m + 1, 0);
    for (int i = 0; i < 4; ++i)
      fill(g[i], g[i] + n + 1, 0);
    for (int i = 0; i < n; ++i) {
      g[0][i] = -a[i] - b[i];
      g[1][i] = -a[i] + b[i];
      g[2][i] = a[i] - b[i];
      g[3][i] = a[i] + b[i];
      for (int j = 1; j - 1 <= i && j <= m; ++j) {
        int k = i - j + 1;
        tmp[4] = f[j];
        tmp[0] = a[i] + b[i] + g[0][k];
        tmp[1] = -a[i] + b[i] + g[1][k];
        tmp[2] = a[i] - b[i] + g[2][k];
        tmp[3] = -a[i] - b[i] + g[3][k];
        f[j] = *max_element(tmp, tmp + 5);
        g[0][k] = max(g[0][k], f[j] - a[i + 1] - b[i + 1]);
        g[1][k] = max(g[1][k], f[j] - a[i + 1] + b[i + 1]);
        g[2][k] = max(g[2][k], f[j] + a[i + 1] - b[i + 1]);
        g[3][k] = max(g[3][k], f[j] + a[i + 1] + b[i + 1]);
      }
    }
    cout << f[m] << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
