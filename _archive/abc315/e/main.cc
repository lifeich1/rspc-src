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
vector<int> e[N], d[N];
int u[N], du[N];

void dfs(int r) {
  if (u[r])
    return;
  u[r] = 1;
  du[r] = e[r].size();
  TLN(TV(r); TV(du[r]); TA(e[r], cerr << _ << ' '));
  for (int y : e[r]) {
    d[y].emplace_back(r);
    dfs(y);
  }
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
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> c;
    e[i].reserve(c);
    if (c)
      copy_n(std::istream_iterator<int>(std::cin), c, std::back_inserter(e[i]));
    TLN(TV(i); TV(c); TA(e[i], cerr << _ << ' '));
  }
  dfs(1);
  vector<int> ls;
  ls.reserve(n);
  for (int i = 1; i <= n; ++i)
    if (u[i] && 0 == du[i])
      ls.emplace_back(i);
  TLN(TI(u + 1, u + n + 1, cerr << _ << ' '));
  TLN(TI(du + 1, du + n + 1, cerr << _ << ' '));
  for (int p = 0; p < ls.size(); ++p) {
    const int x = ls[p];
    if (x == 1)
      break;
    cout << x << ' ';
    for (int y : d[x]) {
      if (0 == --du[y]) {
        ls.emplace_back(y);
      }
    }
  }
  cout << endl;
  return 0;
}

// vim: ts=2 sw=2
