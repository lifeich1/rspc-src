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
    int n, m;
    cin >> n >> m;
    map<int, int> l, r;
    set<pair<int, int>> nr;
    vector<pair<int, int>> sg;
    sg.resize(n);
    for (int i = 0; i < n; ++i) {
      auto &[x, y] = sg[i];
      cin >> x >> y;
    }
    sort(sg.begin(), sg.end());
    int ans = 0;
    sg.emplace_back(m + 1, m + 1);
    for (int cur = sg[0].first, i = 0; cur <= m;
         cur = min((nr.empty() ? m + 1 : nr.begin()->first + 1), sg[i].first)) {
      TLN(TV(cur); TV(i));
      while (i < n && sg[i].first <= cur) {
        r[sg[i].second]++;
        l[sg[i].first]++;
        nr.emplace(sg[i].second, i);
        ++i;
      }
      while (!nr.empty() && nr.begin()->first < cur) {
        auto [t1, t] = *nr.begin();
        nr.erase(nr.begin());
        r[sg[t].second]--;
        l[sg[t].first]--;
      }
      int s = nr.size();
      s -= min(l[1], r[m]);
      ans = max(ans, s);
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
