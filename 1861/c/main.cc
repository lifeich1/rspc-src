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
int a[N];
char s[N];

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
    cin >> s;
    int n = strlen(s);
    bool ok = true;
    int m = 0;
    a[0] = 1;
    for (int i = 0; i < n && ok; ++i) {
      switch (s[i]) {
      case '+':
        ++m;
        a[m] = a[m - 1] & 2;
        break;
      case '-':
        --m;
        if (m < 0)
          ok = false;
        break;
      case '0':
        if (m < 2 || a[m] == 1)
          ok = false;
        a[m] |= 2;
        break;
      case '1':
        if (a[m] & 2)
          ok = false;
        for (int k = m; k > 1 && a[k] != 1; --k)
          a[k] = 1;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}

// vim: ts=2 sw=2
