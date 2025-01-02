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

  int n, m;
  cin >> n >> m;
  vector<int> a;
  copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
  sort(a.begin(), a.end());
  int64_t ans = 0;
  int l = (n - m) * 2;
  for (int i = 0; i < n - m; ++i) {
    int64_t t = a[i] + a[l - i - 1];
    t *= t;
    ans += t;
  }
  for (int i = l; i < n; ++i) {
    int64_t t = a[i];
    t *= t;
    ans += t;
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
