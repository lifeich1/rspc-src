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

  vector<int> a;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    a.clear();
    a.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    if (1 == n) {
      cout << "1\n";
      continue;
    }
    sort(a.begin(), a.end());
    int k = a.back() - a.front();
    for (int i = 1; i < n - 1; ++i)
      k = __gcd(k, a.back() - a[i]);
    for (int i = 0; i < n - 1; ++i)
      a[i] = (a.back() - a[i]) / k;
    int l = 1;
    for (int i = n - 2; i >= 0; --i, ++l)
      if (a[i] != l)
        break;
    int64_t ans = l;
    for (int i = 0; i < n - 1; ++i)
      ans += a[i];
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2