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
int n, m;
int64_t K;
int xs[99], ys[99];
int64_t vs[99];
int s[99], ck[99];
vector<int> e[99];

int64_t ans;

int chk(int r) {
  ck[r] = 1;
  int ret = 1;
  for (int y : e[r]) {
    if (0 == ck[y]) {
      ret += chk(y);
    }
  }
  return ret;
}

void dfs(int r, int u, int64_t c = 0) {
  if (r >= m || u == n - 1) {
    if (u == n - 1) {
      if (c >= ans)
        return;
      for (int i = 1; i <= n; ++i)
        e[i].clear();
      for (int i = 0; i < n - 1; ++i) {
        int t = s[i];
        e[xs[t]].emplace_back(ys[t]);
        e[ys[t]].emplace_back(xs[t]);
      }
      fill(ck, ck + n + 1, 0);
      if (chk(1) == n)
        ans = c;
    }
    return;
  }
  s[u] = r;
  dfs(r + 1, u + 1, (c + vs[r]) % K);
  if (r + n - u <= m)
    dfs(r + 1, u, c);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  cin >> n >> m >> K;
  ans = K;
  for (int i = 0; i < m; ++i)
    cin >> xs[i] >> ys[i] >> vs[i];
  dfs(0, 0);
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
