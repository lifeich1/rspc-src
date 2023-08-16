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
const int N = 101001;
int a[N];

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
    int D, n, m;
    cin >> n >> m >> D;
    copy_n(std::istream_iterator<int>(std::cin), m, a + 1);
    a[0] = 1 - D;
    a[m + 1] = n + 1;
    int s = m - 1;
    for (int i = 1; i <= m + 1; ++i) {
      int t = max(0, a[i] - a[i - 1] - 1);
      s += t / D;
    }
    int z = m + n / D;
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      int t0 = max(0, a[i] - a[i - 1] - 1);
      int t1 = max(0, a[i + 1] - a[i] - 1);
      int t = t0 / D + t1 / D;
      int t2 = max(0, a[i + 1] - a[i - 1] - 1);
      t2 /= D;
      t2 -= t;
      if (t2 < z) {
        z = t2;
        ans = 1;
      } else if (t2 == z)
        ans++;
    }
    s += z;
    cout << s << ' ' << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
