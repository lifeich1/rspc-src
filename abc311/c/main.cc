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
#define TA(VEC, ITEM, ...)                                                     \
  TRACE(cerr << #VEC << "= ";                                                  \
        for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR))
using namespace std;
#define self_todo_placeholder

const int N = 201001;
int u[N], d[N];
vector<int> ans;

int dfs(int r, int depth) {
  u[r] = depth;
  if (u[d[r]] > 0) {
    ans.emplace_back(r);
    return d[r];
  }
  int t = dfs(d[r], depth + 1);
  if (t != 0) {
    ans.emplace_back(r);
    if (t != r) {
      return t;
    } else {
      cout << ans.size() << endl;
      copy(ans.rbegin(), ans.rend(),
           std::ostream_iterator<int>(std::cout, " "));
      cout << endl;
    }
  }
  return 0;
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
  copy_n(std::istream_iterator<int>(std::cin), n, d + 1);
  dfs(1, 1);
  return 0;
}

// vim: ts=2 sw=2
