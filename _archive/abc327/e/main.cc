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

const int N = 5050;
int p[N];
double f[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  copy_n(std::istream_iterator<int>(std::cin), n, p);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j)
      f[j + 1] = max(f[j + 1], f[j] * 0.9 + p[i]);
  }
  double d = 1;
  double ans = -1e20;
  for (int i = 1; i <= n; ++i) {
    double t = f[i] / d;
    d = d * 0.9 + 1;
    t -= 1200.0 / sqrt(i);
    ans = max(ans, t);
  }
  TLN(TI(f + 1, f + n + 1, cerr << _ << ' '));
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
