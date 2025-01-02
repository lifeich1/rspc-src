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
    int n;
    cin >> n;
    vector<int> a;
    a.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    vector<int> b[2];
    for (int i = 0; i < n; ++i) {
      int j = (i + 1) % n;
      if (a[i] != a[j]) {
        if (a[i] > a[j])
          b[0].emplace_back(j);
        else
          b[1].emplace_back(j);
      }
    }
    if (b[0].size() > 1 && b[1].size() > 1) {
      cout << -1 << endl;
      continue;
    } else if (b[0].empty() || b[1].empty()) {
      cout << 0 << endl;
      continue;
    }
    std::vector<int> h(n + n, n * 4 + 4);
    h[0] = 0;
    vector<int> ls = {0};
    ls.reserve(n + n);
    for (int i = 0; i < ls.size(); ++i) {
      int x = ls[i];
      int v = h[x] + 1;
      int y, y1;
      if (x < n)
        y = (x + n - 1) % n;
      else
        y = (x + 1) % n + n;
      if (x < n)
        y1 = x + n;
      else
        y1 = x - n;
      if (v < h[y])
        h[y] = v, ls.emplace_back(y);
      if (v < h[y1])
        h[y1] = v, ls.emplace_back(y1);
    }
    int ans = n * 4 + 4;
    if (b[0].size() == 1)
      ans = h[b[0][0]];
    if (b[1].size() == 1)
      ans = min(ans, h[b[1][0] + n]);
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
