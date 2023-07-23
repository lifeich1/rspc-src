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

int gen(int f2, int f1) {
  int r = -1;
  while (f2 >= f1 && f1 >= 0) {
    ++r;
    int t = f2 - f1;
    f2 = f1;
    f1 = t;
  }
  return r;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = n / 2; i <= n; ++i) {
      if (gen(n, i) >= k - 2) {
        // TLN(TV(i));
        ++ans;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
