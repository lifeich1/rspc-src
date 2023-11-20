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
    string s;
    int n, m;
    cin >> n >> m >> s;
    int t = count(s.begin(), s.end(), 'B');
    if (m == t) {
      cout << "0\n";
      continue;
    }

    cout << "1\n";
    if (m > t) {
      for (int i = 0, k = 0; i < n; ++i) {
        if (s[i] == 'A')
          ++k;
        if (k + t == m) {
          cout << i + 1 << " B\n";
          break;
        }
      }
    } else {
      for (int i = 0, k = 0; i < n; ++i) {
        if (s[i] == 'B')
          ++k;
        if (t - k == m) {
          cout << 1 + i << " A\n";
          break;
        }
      }
    }
  }
  return 0;
}

// vim: ts=2 sw=2
