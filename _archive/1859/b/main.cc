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

const int N = 25111;
int e[N][2];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif
  const int M = 1001001000;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int l;
      cin >> l;
      e[i][0] = e[i][1] = M;
      for (int j = 0; j < l; ++j) {
        int t;
        cin >> t;
        if (t <= e[i][0]) {
          e[i][1] = e[i][0];
          e[i][0] = t;
        } else {
          e[i][1] = min(e[i][1], t);
        }
      }
    }
    int64_t s2 = 0;
    for (int i = 0; i < n; ++i)
      s2 += e[i][1];
    int mm = M;
    for (int i = 0; i < n; ++i)
      mm = min(mm, e[i][0]);
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, s2 - e[i][1] + mm);
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
