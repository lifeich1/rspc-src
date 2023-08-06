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

  int n;
  cin >> n;
  vector<int> a;
  a.reserve(n);
  copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
  sort(a.begin(), a.end());
  int64_t s = 0;
  for (int x : a)
    s += x;
  int64_t d = s / n, e = s % n;
  int64_t ans = 0;
  for (int i = n - e - 1; i >= 0; --i) {
    ans += abs(d - a[i]);
  }
  for (int i = n - e; i < n; ++i) {
    ans += abs(d + 1 - a[i]);
  }
  ans >>= 1;
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
