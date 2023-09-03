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

  int n;
  cin >> n;
  vector<int> a;
  map<int, pair<int, int>> m;
  a.reserve(n);
  copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
  for (int i = 0; i < n; ++i) {
    m[a[i]].second++;
  }
  int64_t t = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    auto &[l, r] = m[a[i]];
    t -= int64_t(l) * r;
    ans += t;
    --r, ++l;
    t += int64_t(l) * r;
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
