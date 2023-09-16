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
vector<tuple<int, int, int>> e[N];
optional<pair<int64_t, int64_t>> f[N];
int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    e[a].emplace_back(b, x, y);
    e[b].emplace_back(a, -x, -y);
    TLN(TV(a); TV(b); TV(x); TV(y));
  }
  f[1] = {0, 0};
  vector<int> ls = {1};
  ls.reserve(n);
  for (int i = 0; i < ls.size(); ++i) {
    int r = ls[i];
    auto [x, y] = f[r].value();
    TLN(TV(r));
    for (auto [p, u, v] : e[r]) {
      if (f[p].has_value())
        continue;
      TLN(TV(p); TV(u); TV(v));
      ls.emplace_back(p);
      f[p] = {x + u, y + v};
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (f[i].has_value()) {
      auto [x, y] = f[i].value();
      cout << x << ' ' << y << endl;
    } else
      cout << "undecidable\n";
  }
  return 0;
}

// vim: ts=2 sw=2
