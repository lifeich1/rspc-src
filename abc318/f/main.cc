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
  vector<int64_t> xs, ls, cp;
  copy_n(std::istream_iterator<int64_t>(std::cin), n, std::back_inserter(xs));
  copy_n(std::istream_iterator<int64_t>(std::cin), n, std::back_inserter(ls));
  cp.reserve(n * n * 2);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cp.emplace_back(xs[i] - ls[j]);
      cp.emplace_back(xs[i] + ls[j] + 1);
    }
  sort(cp.begin(), cp.end());
  cp.erase(unique(cp.begin(), cp.end()), cp.end());
  int64_t ans = 0, last = cp.front() - 1;
  bool now = false;
  vector<int64_t> h;
  h.reserve(n);
  sort(ls.begin(), ls.end());
  auto chk = [&](int64_t p) {
    h.clear();
    for (int i = 0; i < n; ++i)
      h.emplace_back(abs(xs[i] - p));
    sort(h.begin(), h.end());
    for (int i = 0; i < n; ++i)
      if (h[i] > ls[i])
        return false;
    return true;
  };
  for (auto p : cp) {
    if (now)
      ans += p - last;
    now = chk(p);
    last = p;
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
