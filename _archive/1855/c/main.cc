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

int f[22][22], u[22][22];

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
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    bool qk = true;
    for (int i = 1; i < n; ++i)
      if (a[i - 1] > a[i]) {
        qk = false;
        break;
      }
    if (qk) {
      cout << "0\n";
      continue;
    }
    int t1 = *max_element(a.begin(), a.end());
    int t2 = *min_element(a.begin(), a.end());
    int y1 = count_if(a.begin(), a.end(), [](int x) { return x < 0; });
    int y2 = count_if(a.begin(), a.end(), [](int x) { return x > 0; });
    int x1 = 0, x2 = 0;
    if (t1 <= 0)
      x1 = n;
    if (t2 >= 0)
      x2 = n;
    if (t1 > 0 && t2 < 0) {
      for (int t = t1; t + t2 < 0; t += t, x1++)
        ;
      for (int t = t2; t + t1 > 0; t += t, x2++)
        ;
    }
    vector<pair<int, int>> ans;
    bool rb = false;
    if (x1 + y1 > x2 + y2) {
      rb = true;
      for_each(a.begin(), a.end(), [](int &x) { x = -x; });
    }
    t1 = *max_element(a.begin(), a.end());
    t2 = *min_element(a.begin(), a.end());
    int k1 = max_element(a.begin(), a.end()) - a.begin();
    while (a[k1] + t2 < 0) {
      a[k1] += a[k1];
      ans.emplace_back(k1 + 1, k1 + 1);
    }
    for (int i = 0; i < n; ++i)
      if (a[i] < 0) {
        a[i] += a[k1];
        ans.emplace_back(i + 1, k1 + 1);
      }
    if (rb) {
      for (int i = n; i > 1; --i)
        ans.emplace_back(i - 1, i);
    } else {
      for (int i = 1; i < n; ++i)
        ans.emplace_back(i + 1, i);
    }
    cout << ans.size() << endl;
    for (auto [i, j] : ans) {
      cout << i << ' ' << j << endl;
    }
  }
  return 0;
}

// vim: ts=2 sw=2
