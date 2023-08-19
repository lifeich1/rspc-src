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

int64_t dis2(pair<int64_t, int64_t> const &l, pair<int64_t, int64_t> const &r) {
  auto t = l.first - r.first;
  t *= t;
  auto s = l.second - r.second;
  s *= s;
  return t + s;
}
const int N = 10101;
double f[N][40];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<pair<int64_t, int64_t>> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  for (int i = 1; i < n; ++i) {
    int l = max(0, i - 40);
    f[i][0] = f[i - 1][0] + sqrt((double)dis2(p[i], p[i - 1]));
    fill(f[i] + 1, f[i] + 40, f[i][0]);
    for (int j = l; j < i; ++j) {
      double d = dis2(p[j], p[i]);
      d = sqrt(d);
      TV(j);
      TV(d);
      int k = i - j - 1;
      for (int t = k; t < 40; ++t)
        f[i][t] = min(f[i][t], f[j][t - k] + d);
    }
    TLN();
    TLN(TV(i); TI(f[i], f[i] + 10, cerr << setprecision(10) << _ << ' '));
  }
  double ans = f[n - 1][0];
  int64_t k = 1;
  for (int i = 1; i < 40; ++i) {
    double t = f[n - 1][i];
    t += k;
    k <<= 1;
    ans = min(ans, t);
  }
  cout << setprecision(10) << ans << endl;

  return 0;
}

// vim: ts=2 sw=2
