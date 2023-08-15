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

int a[555];

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
    for (int i = 0; i <= n; ++i)
      a[i] = i;
    auto sm = [&]() -> int64_t {
      int64_t s = 0;
      int d = 0;
      for (int i = 1; i <= n; ++i) {
        int t = i * a[i];
        d = max(d, t);
        s += t;
      }
      return s - d;
    };
    int64_t ans = 0;
#if 0
    while (next_permutation(a + 1, a + n + 1)) {
      auto t = sm();
      if (t > ans) {
        ans = t;
#if defined(RSPC_TRACE_HINT)
        copy_n(a + 1, n, std::ostream_iterator<int>(std::cerr, " "));
        cerr << endl;
        TV(ans);
#endif
      }
    }
#else
    ans = sm();
    for (int i = n - 1; i > 0; --i) {
      for (int j = i; j <= n; ++j)
        a[j] = n + i - j;
      ans = max(ans, sm());
    }
#endif
    cout << ans << endl;
#if 0
    int64_t s = 0;
    for (int i = 1; i < n - 1; ++i) {
      s += i * i;
    }
    s += (n - 1) * n;
    cout << s << endl;
#endif
  }
  return 0;
}

// vim: ts=2 sw=2
