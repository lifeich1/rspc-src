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

  int n, X;
  cin >> n;
  vector<set<int>> a;
  for (int i = 0; i < n; ++i) {
    set<int> s;
    int k;
    cin >> k;
    while (k-- > 0) {
      int t;
      cin >> t;
      s.emplace(t);
    }
    a.emplace_back(std::move(s));
  }
  cin >> X;
  int l = 99;
  for (int i = 0; i < n; ++i) {
    if (a[i].find(X) != a[i].end()) {
      l = min(l, (int)a[i].size());
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (a[i].size() == l && a[i].find(X) != a[i].end()) {
      ans.emplace_back(i + 1);
    }
  }
  cout << ans.size() << endl;
  if (ans.size()) {
    copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
