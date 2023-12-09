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
vector<int> e[N];
int a[N], b[N], f[N];

bool dfs(int r, int fl) {
  if (-1 != f[r]) {
    if (f[r] != fl)
      return false;
    else
      return true;
  }
  f[r] = fl;
  for (int y : e[r])
    if (!dfs(y, fl ^ 1))
      return false;
  return true;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  fill(f, f + n + 1, -1);
  copy_n(std::istream_iterator<int>(std::cin), m, a);
  copy_n(std::istream_iterator<int>(std::cin), m, b);
  for (int i = 0; i < m; ++i) {
    e[a[i]].emplace_back(b[i]);
    e[b[i]].emplace_back(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (-1 == f[i]) {
      if (!dfs(i, 0)) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
  return 0;
}

// vim: ts=2 sw=2
