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

  int tt;
  cin >> tt;
  while (tt--) {
    int n, K;
    cin >> n >> K;
    int ans = 0;
    vector<int> a;
    a.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    ans = *max_element(a.begin(), a.end());
    for (int i = 1; i < n; ++i) {
      int k = 0, v = a[i];
      int mi = a[i] - a[i - 1] + 1, wd = 0;
      for (int j = i - 1; j >= 0; --j) {
        ++v;
        k += max(0, v - a[j]);
        mi = min(mi, v - a[j] + wd);
        while (k > K && wd < mi) {
          v--;
          ++wd;
          k -= i - j;
        }
        if (k <= K) {
          ans = max(v, ans);
        } else
          break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
