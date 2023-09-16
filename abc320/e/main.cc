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
int64_t ans[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  set<int> fre;
  for (int i = 0; i < n; ++i)
    fre.emplace(i);
  set<pair<int, int>> rt;
  while (m--) {
    int t, w, s;
    cin >> t >> w >> s;
    while (rt.size() && rt.begin()->first <= t) {
      fre.emplace(rt.begin()->second);
      rt.erase(rt.begin());
    }
    if (fre.size()) {
      auto x = *fre.begin();
      fre.erase(fre.begin());
      ans[x] += w;
      rt.emplace(t + s, x);
    }
  }
  copy_n(ans, n, std::ostream_iterator<int64_t>(std::cout, "\n"));
  return 0;
}

// vim: ts=2 sw=2
