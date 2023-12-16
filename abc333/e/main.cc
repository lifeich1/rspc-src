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

  int n;
  vector<pair<int, int>> a;
  cin >> n;
  map<int, vector<int>> c;
  vector<int> ans(n, 0);
  vector<int> d(n, 0);
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    a.emplace_back(u, v);
    if (1 == u)
      c[v].emplace_back(i);
  }
  int ba = 0;
  for (int i = n - 1, s = 0; i >= 0; --i) {
    auto [t, x] = a[i];
    if (2 == t) {
      auto &v = c[x];
      while (v.size() && v.back() > i)
        v.pop_back();
      if (v.empty()) {
        cout << "-1\n";
        return 0;
      }
      ans[v.back()] = 1;
      d[v.back()]++;
      v.pop_back();
      if (++s > ba)
        ba = s;
    } else
      s -= d[i];
  }

  cout << ba << endl;
  for (int i = 0; i < n; ++i)
    if (1 == a[i].first)
      cout << ans[i] << ' ';
  cout << endl;
  return 0;
}

// vim: ts=2 sw=2
