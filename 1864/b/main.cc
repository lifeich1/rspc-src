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
char s[N], a[N], b[N];

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
    cin >> n >> k >> s;
    if (k & 1) {
      int l = (n + 1) / 2;
      for (int i = 0; i < n; i += 2) {
        a[i / 2] = s[i];
        b[i / 2] = s[i + 1];
      }
      sort(a, a + l);
      sort(b, b + (n - l));
      for (int i = 0; i < n; ++i) {
        if (i & 1) {
          s[i] = b[i >> 1];
        } else
          s[i] = a[i >> 1];
      }
    } else
      sort(s, s + n);
    s[n] = '\0';
    cout << s << endl;
  }
  return 0;
}

// vim: ts=2 sw=2