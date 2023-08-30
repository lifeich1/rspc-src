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
    map<int, vector<int>> e;
    map<int, int> d;
    int n, m, K;
    cin >> n >> m >> K;
    vector<int> h = {0};
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(h));
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      e[u].emplace_back(v);
      d[v]++;
    }
    int ans = 1 << 28;
    for (int st = 1; st <= n; ++st) {
      map<int, int> td(d);
      map<int, int> f;
      f[st] = 0;
      for (int i = 1; i <= n; ++i)
        if (h[i] < h[st])
          f[i] = 1;
      bool chan;
      do {
        chan = false;
        for (int i = 1; i <= n; ++i)
          for (int y : e[i]) {
            int t = f[i];
            if (h[y] < h[i])
              ++t;
            if (t > f[y]) {
              chan = true;
              f[y] = t;
            }
          }
      } while (chan);
      int ed = h[st];
      for (int i = 1; i <= n; ++i) {
        ed = max(ed, f[i] * K + h[i]);
      }
      int t = ed - h[st];
      TLN(TV(st); TV(t); TA(f, cerr << _.second << ' '));
      if (ans < 0 || ans > t)
        ans = t;
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
