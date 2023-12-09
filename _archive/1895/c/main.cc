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
map<int, int> sl[11][6], sr[11][6];

int ub(string_view s, int p, int len) {
  int t = len >> 1;
  int v = 0;
  int p1 = s.length() + p;
  for (int i = 0; i < t; ++i)
    if (i >= p && i < p1)
      v += s[i - p] - '0';
  for (int i = t; i < len; ++i)
    if (i >= p && i < p1)
      v -= s[i - p] - '0';
  return v;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  int64_t ans = n;
  while (n--) {
    string st;
    cin >> st;
    for (int i = st.length() + 2 - (st.length() & 1);
         i <= 10 && i <= st.length() + 5; i += 2) {
      int tl = ub(st, 0, i), tr = ub(st, i - st.length(), i);
      ans += sr[i][i - st.length()][-tl];
      ans += sl[i][i - st.length()][-tr];
      sl[i][st.length()][tl]++;
      sr[i][st.length()][tr]++;
    }
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
