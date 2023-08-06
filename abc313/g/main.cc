#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
/// floor_sum(a,b,c,n) = sum{(a*i+b) div c | i in 0..=n}
template <typename T> T floor_sum(T a, T b, T c, T n) {
  T r = 0;
  r += (a / c) * n * (n + 1) / 2;
  r += (b / c) * (n + 1);
  a %= c, b %= c;
  if (a == 0)
    return r;
  T m = (a * n + b) / c;
  r += m * n;
  return r - floor_sum<T>(c, c - b - 1, a, m - 1);
}
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: floor_sum

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
  const int M = 998244353;

  int n;
  cin >> n;
  vector<int> a;
  a.reserve(n);
  copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
  sort(a.begin(), a.end());
  int64_t ans = a.front() + 1;
  int64_t s = int64_t(a.front()) * n;
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1])
      continue;
    int64_t t = a[i] - a[i - 1];
    TLN(TV(t); TV(a[i]); TV(s); TV(ans));
    ans += floor_sum<int64_t>(n - i, s, n, a[i] - a[i - 1]) - s / n;
    ans %= M;
    ans += t;
    ans %= M;
    s += t * (n - i);
    TLN(TV(i); TV(a[i]); TV(s); TV(ans));
  }
  ans = (ans + M) % M;
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
