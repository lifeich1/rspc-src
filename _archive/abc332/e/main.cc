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

const int M = 1 << 15;
const int N = 16;
double f[N][M], w[N], s[M];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, D;
  cin >> n >> D;
  for (int i = 0; i < n; ++i)
    cin >> w[i];
  double aw = accumulate(w, w + n, 0.0f);
  for (int i = 0; i <= D; ++i)
    fill(f[i], f[i] + (1 << n), aw * aw * D);
  f[0][0] = 0;
  aw /= D;
  int m = 1 << n;
  for (int i = 1; i < M; ++i) {
    for (int j = 0; j < n; ++j)
      if (i & (1 << j))
        s[i] += w[j];
  }
  for (int i = 1; i <= D; ++i)
    for (int j = 1; j < m; ++j) {
    }
  return 0;
}

// vim: ts=2 sw=2
