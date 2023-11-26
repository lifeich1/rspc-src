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

const int N = 101001;
int a[N];

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
    int n, Q;
    cin >> n >> Q;
    copy_n(std::istream_iterator<int>(std::cin), n, a);
    while (Q--) {
      int op;
      cin >> op;
      if (1 == op) {
        int s;
        cin >> s;
        bool ok = false;
        for (int i = 0, j = 0, t = 0; i < n; ++i) {
          t += a[i];
          while (t > s) {
            t -= a[j++];
          }
          if (t == s) {
            ok = true;
            break;
          }
        }
        cout << (ok ? "YES\n" : "NO\n");
      } else {
        int i, v;
        cin >> i >> v;
        a[i - 1] = v;
      }
    }
  }
  return 0;
}

// vim: ts=2 sw=2
