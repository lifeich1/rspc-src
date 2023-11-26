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

const int N = 301001;
char s[N];
int l[N], r[N];
int n;

int dfs(int x) {
  if (l[x] == 0 && r[x] == 0)
    return 0;
  int rt = n;
  if (l[x])
    rt = min(rt, dfs(l[x]) + (s[x - 1] != 'L' ? 1 : 0));
  if (r[x])
    rt = min(rt, dfs(r[x]) + (s[x - 1] != 'R' ? 1 : 0));
  return rt;
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
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
      cin >> l[i] >> r[i];
    cout << dfs(1) << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
