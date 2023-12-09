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
const int N = 201001;
int a[N], b[N];
int64_t sb[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m, P;
  cin >> n >> m >> P;
  copy_n(std::istream_iterator<int>(std::cin), n, a);
  copy_n(std::istream_iterator<int>(std::cin), m, b);
  sort(b, b + m);
  sb[0] = 0;
  for (int i = 0; i < m; ++i)
    sb[i + 1] = sb[i] + b[i];
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    int t = lower_bound(b, b + m, P - a[i]) - b;
    ans += int64_t(t) * a[i] + sb[t];
    ans += int64_t(m - t) * P;
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
