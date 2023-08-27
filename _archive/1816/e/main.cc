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

const int N = 2020;
vector<int> e[N], ns[N];
int d[N];

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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      e[i].clear();
    fill(d, d + n + 1, n + 1);
    vector<int> ls = {1};
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      e[y].emplace_back(x);
    }
    d[1] = 0;
    for (int i = 0; i < ls.size(); ++i) {
      int x = ls[i];
      int v = d[x] + 1;
      for (int y : e[x]) {
        if (d[y] > v) {
          d[y] = v;
          ls.emplace_back(y);
        }
      }
    }
    if (ls.size() != n) {
      cout << "INFINITE\n";
      continue;
    }
    for (int i = 0; i < n; ++i)
      ns[i].clear();
    for (int i = 1; i <= n; ++i)
      ns[d[i]].emplace_back(i);
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans += (i + 1) * ns[i].size();
    cout << "FINITE\n" << ans << endl;
    for (int l = n - 1; l >= 0; --l) {
      for (int i = l; i < n; ++i)
        copy(ns[i].begin(), ns[i].end(),
             std::ostream_iterator<int>(std::cout, " "));
    }
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
