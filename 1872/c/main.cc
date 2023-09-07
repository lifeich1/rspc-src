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

const int M = 10000000;
int d[M + 1];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif
  for (int i = 2; i < 4000; ++i)
    if (0 == d[i]) {
      for (int k = i + i; k <= M; k += i)
        d[k] = i;
    }

  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    bool no = true;
    for (int i = l; i <= r; ++i)
      if (d[i]) {
        cout << d[i] << ' ' << (i - d[i]) << endl;
        no = false;
        break;
      }
    if (no)
      cout << "-1\n";
  }
  return 0;
}

// vim: ts=2 sw=2
