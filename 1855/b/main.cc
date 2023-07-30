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
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR) << ' ')
using namespace std;
#define self_todo_placeholder

const int M = 5000;
bool np[M];

vector<int64_t> u;
void dfs(int64_t v, pair<int, int> *first, pair<int, int> *last) {
  if (first == last) {
    u.emplace_back(v);
    // TLN(TV(v));
    return;
  }
  auto [k, n] = *first;
  auto p = first;
  p++;
  dfs(v, p, last);
  for (int i = 0; i < n; ++i) {
    v *= k;
    dfs(v, p, last);
  }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif
  vector<int> ps;
  for (int i = 2; i < M; ++i) {
    if (!np[i]) {
      ps.emplace_back(i);
      if (i * i < M) {
        for (int t = i + i; t < M; t += i)
          np[t] = true;
      }
    }
  }
  TLN(TV(ps.size()));

  int tt;
  cin >> tt;
  while (tt--) {
    int64_t x;
    cin >> x;
    int ans = 1;
    while (x % (ans + 1) == 0)
      ++ans;
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
