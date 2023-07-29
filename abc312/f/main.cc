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

  int n, m;
  cin >> n >> m;
  vector<int64_t> a, b, c;
  a.reserve(n);
  b.reserve(n);
  c.reserve(n);
  for (int i = 1; i <= n; ++i) {
    int t, x;
    cin >> t >> x;
    switch (t) {
    case 0:
      a.emplace_back(x);
      break;
    case 1:
      b.emplace_back(x);
      break;
    case 2:
      c.emplace_back(x);
      break;
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  int64_t s = 0, ans = 0;
  int p = max(0, int(a.size() - m));
  s = accumulate(a.begin() + p, a.end(), 0ll);
  ans = s;
  int64_t ub = 0;
  for (int q = b.size() - 1; q >= 0; --q) {
    s += b[q];
    while (ub < b.size() - q && c.size()) {
      ub += c.back();
      c.pop_back();
      --m;
    }
    if (ub < b.size() - q)
      break;
    while (a.size() + b.size() - p - q > m && p < a.size()) {
      s -= a[p++];
    }
    if (a.size() + b.size() - p - q <= m) {
      ans = max(ans, s);
    } else
      break;
  }
  cout << ans << endl;

  return 0;
}

// vim: ts=2 sw=2
