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

vector<tuple<int, int, int>> md[111];
int s[111];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ++a, ++c;
    md[a].emplace_back(c, d, 1);
    md[b + 1].emplace_back(c, d, -1);
  }
  int ans = 0;
  fill(s, s + 101, 0);
  for (int i = 0; i <= 100; ++i) {
    for (auto [l, r, d] : md[i]) {
      for (int p = l; p <= r; ++p)
        s[p] += d;
    }
    int t = count_if(s, s + 101, [](int t) { return t > 0; });
#if defined(RSPC_TRACE_HINT)
    if (t > 0) {
      TLN(TV(i); TV(ans); TV(t));
    }
#endif
    ans += t;
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
