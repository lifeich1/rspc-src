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
    int n, K;
    cin >> n >> K;
    TLN(TV(n); TV(K));
    if (K > 2) {
      int64_t t;
      for (int i = 0; i < n; ++i)
        cin >> t;
      cout << "0\n";
      continue;
    }
    vector<int64_t> a;
    a.reserve(n);
    copy_n(std::istream_iterator<int64_t>(std::cin), n, std::back_inserter(a));
    sort(a.begin(), a.end());
    int64_t ans = a.front();
    for (int i = 1; i < n; ++i)
      ans = min(ans, a[i] - a[i - 1]);
    if (1 == K || 0 == ans) {
      cout << ans << endl;
      continue;
    }
    for (const auto &x : a) {
      for (int i = 1, j = 0; i < n; ++i) {
        while (j + 1 < i && a[i] - a[j] > x)
          ++j;
        ans = min(ans, abs((a[i] - a[j]) - x));
        if (j)
          ans = min(ans, abs((a[i] - a[j - 1]) - x));
      }
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
