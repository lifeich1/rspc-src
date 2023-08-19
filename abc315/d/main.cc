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

const int N = 2020;
char c[N][N];
bool u[N][N];
int s[N * 2][26];
int d[N * 2];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> c[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      int x = c[i][j] - 'a';
      if (0 == s[i][x]++) {
        d[i]++;
      }
      if (0 == s[j + n][x]++) {
        d[j + n]++;
      }
    }
  set<int> ls, nx;
  for (int i = 0; i < n + m; ++i) {
    if (1 == d[i])
      ls.emplace(i);
  }
  int ans = n * m;
  while (ls.size()) {
    const int k = *ls.begin();
    ls.erase(ls.begin());
    d[k] = 0;
    TV(k);
    if (k < n) {
      for (int i = 0; i < m; ++i)
        if (!u[k][i]) {
          TRACE(cerr << '(' << k << ", " << i << ") ");
          --ans;
          u[k][i] = true;
          int x = c[k][i] - 'a';
          if (0 == --s[i + n][x]) {
            if (1 == --d[i + n]) {
              nx.emplace(i + n);
            }
          }
        }
    } else {
      for (int i = 0; i < n; ++i)
        if (!u[i][k - n]) {
          TRACE(cerr << '(' << i << ", " << (k - n) << ") ");
          --ans;
          u[i][k - n] = true;
          int x = c[i][k - n] - 'a';
          if (0 == --s[i][x]) {
            if (1 == --d[i]) {
              nx.emplace(i);
            }
          }
        }
    }
    TLN(TV(ans));
    if (ls.empty()) {
      for (auto k : nx)
        if (*max_element(s[k], s[k] + 26) >= 2)
          ls.emplace(k);
      nx.clear();
    }
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
