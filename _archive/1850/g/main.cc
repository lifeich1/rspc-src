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
#define TA(VEC, ITEM, ...)                                                     \
  TRACE(cerr << #VEC << "= ";                                                  \
        for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR))
using namespace std;
#define self_todo_placeholder

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  map<int, int> c[4];
  function<int(int, int)> hh[4] = {
      [](int x, int) { return x; },
      [](int, int x) { return x; },
      [](int x, int y) { return x + y; },
      [](int x, int y) { return x - y; },
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for_each(c, c + 4, [](auto &m) { m.clear(); });
    for (int i = 0; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      for (int k = 0; k < 4; ++k) {
        c[k][hh[k](u, v)]++;
      }
    }
    int64_t ans = 0;
    for (int k = 0; k < 4; ++k) {
      for (auto [kk, v] : c[k]) {
        int64_t t = v - 1;
        t *= v;
        ans += t;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
