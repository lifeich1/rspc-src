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

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, s, m, l;
  cin >> n >> s >> m >> l;
  int t1 = (n - 1) / 12 + 1;
  int t2 = (n - 1) / 8 + 1;
  int ans = min(t1 * l, t2 * m);
  for (int i = 0; i < t1; ++i) {
    for (int j = 0; j < t2; ++j) {
      int t = n - i * 12 - j * 8;
      int k = 0;
      if (t > 0)
        k = (t - 1) / 6 + 1;
      ans = min(ans, i * l + j * m + k * s);
      if (t <= 0)
        break;
    }
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
