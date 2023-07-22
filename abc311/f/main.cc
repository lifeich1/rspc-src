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
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR))
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
  vector<int> a(m, n + 1);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '#')
        a[j] = min(a[j], i);
    }
  }
  TA(a, cerr << _);
  TLN();
  vector<int> f(n, 0), g(n, 0);
  for (int i = 0; i <= min(a[0], n - 1); ++i)
    f[i] = 1;
  if (a[0] > n)
    f[n - 1] = 2;
  const int M = 998244353;
  auto ad = [&](int &x, int v) { x = (x + v) % M; };
  for (int j = 1; j < m; ++j) {
    f.swap(g);
    fill(f.begin(), f.end(), 0);
    if (a[j] >= n)
      ad(f[n - 1], g[n - 1]);
    for (int i = n - 1, s = 0; i >= 0; --i) {
      ad(s, g[i]);
      if (i <= a[j]) {
        ad(f[i], s);
        if (i > 0) {
          ad(f[i], g[i - 1]);
        }
      }
    }
    TLN(TA(f, cerr << _ << ' '));
  }
  int ans = 0;
  for_each(f.begin(), f.end(), [&](int x) { ad(ans, x); });
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
