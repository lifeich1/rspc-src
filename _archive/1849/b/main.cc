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

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  vector<pair<int, int>> h;
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    h.clear();
    h.reserve(n);
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      h.emplace_back((x - 1) % k + 1, -i);
    }
    sort(h.begin(), h.end());
    transform(h.rbegin(), h.rend(), std::ostream_iterator<int>(std::cout, " "),
              [](auto p) { return -p.second; });
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
