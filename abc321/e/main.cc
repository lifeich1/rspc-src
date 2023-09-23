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

int64_t cson(int64_t x, int64_t n, int64_t k) {
  int t = __builtin_clzll(x) - __builtin_clzll(n);
  if (k > t)
    return 0;
  int64_t l, r;
  l = r = x;
  for (int i = 0; i < k; ++i) {
    l = l + l, r = r + r + 1;
  }
  if (l > n)
    return 0;
  r = min(r, n);
  return r - l + 1;
}

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
    int64_t n, x, K;
    cin >> n >> x >> K;
    int64_t ans = cson(x, n, K);
    for (int rv = 1; (x >> rv) > 0 && K >= rv; ++rv) {
      int64_t b = ((x >> (rv - 1)) & 1) ^ 1;
      if (rv < K)
        ans += cson((x >> rv) * 2 + b, n, K - rv - 1);
      else
        ans += 1;
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
