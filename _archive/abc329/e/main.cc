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

  int n, m;
  cin >> n >> m;
  string S, T;
  cin >> S >> T;
  bitset<8> f, g;
  if (S[0] != T[0]) {
    cout << "No\n";
    return 0;
  }
  f.set(0);
  for (int i = 1; i < n; ++i) {
    g = f;
    f.reset();
    for (int j = 0; j < m; ++j)
      if (g.test(j)) {
        if (j + 1 < m && S[i] == T[j + 1]) {
          f.set(j + 1);
        }
        if (S[i] == T[0]) {
          f.set(0);
        }
      }
    if (g.test(m - 1)) {
      for (int j = 0; j < m; ++j)
        if (S[i] == T[j])
          f.set(j);
    }
  }
  if (f.test(m - 1)) {
    cout << "Yes\n";
  } else
    cout << "No\n";
  return 0;
}

// vim: ts=2 sw=2
