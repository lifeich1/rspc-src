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

  set<int> r[9], c[9], s[3][3];
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      int x;
      cin >> x;
      r[i].emplace(x);
      c[j].emplace(x);
      s[i / 3][j / 3].emplace(x);
    }
  }
  bool ok = all_of(r, r + 9, [](auto &s) { return s.size() == 9; });
  ok &= all_of(c, c + 9, [](auto &s) { return s.size() == 9; });
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      ok &= s[i][j].size() == 9;
  cout << (ok ? "Yes\n" : "No\n");
  return 0;
}

// vim: ts=2 sw=2
