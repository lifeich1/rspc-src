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

  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    map<pair<int, int>, int> c;
    int k = 1;
    auto tu = [&](int x, int y) {
      pair<int, int> t = {x, y};
      c[t] |= k;
    };
    auto ga = [&]() {
      int x, y;
      cin >> x >> y;
      tu(x + a, y + b);
      tu(x + a, y - b);
      tu(x - a, y + b);
      tu(x - a, y - b);
      tu(x + b, y + a);
      tu(x - b, y + a);
      tu(x + b, y - a);
      tu(x - b, y - a);
    };
    ga();
    k = 2;
    ga();
    int ans = 0;
    for (const auto &[t, v] : c) {
      TLN(TV(v); cerr << " (" << t.first << ',' << t.second << ")");
      if (v == 3)
        ++ans;
    }
    TLN(TV(ans));
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
