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
bool f[N];
string s1, s2;

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
    cin >> s1 >> s2;
    int n = s1.length();
    f[0] = s1[0] == s2[0];
    for (int i = 1; i < n; ++i) {
      f[i] = f[i - 1] && (s1[i] == s2[i]);
      if (f[i] || s1[i] != s2[i])
        continue;
      char c = s1[i];
      for (int j = i - 1; j >= 0; --j)
        if (s1[j] == c && s2[j] == c && (j == 0 || f[j - 1])) {
          f[i] = true;
          break;
        }
    }
    cout << (f[n - 1] ? "YES\n" : "NO\n");
  }
  return 0;
}

// vim: ts=2 sw=2
