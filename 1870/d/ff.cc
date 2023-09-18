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

int a[99];
vector<int> ans;
int n, K;

void dfs(int r, int u, vector<int> v) {
  if (u > K)
    return;
  if (n == r) {
    for (int i = 0; i < n; ++i)
      if (v[i] != ans[i]) {
        if (v[i] < ans[i])
          return;
        break;
      }
    ans.swap(v);
    return;
  }

  v.push_back(0);
  dfs(r + 1, u, v);
  for (u += a[r]; u <= K; u += a[r]) {
    for_each(v.begin(), v.end(), [](int &x) { x++; });
    dfs(r + 1, u, v);
  }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int _t;
  cin >> _t;
  cin >> n;
  copy_n(std::istream_iterator<int>(std::cin), n, a);
  cin >> K;
  ans.resize(n, 0);
  dfs(0, 0, vector<int>{});

  copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
  cout << endl;

  return 0;
}

// vim: ts=2 sw=2
