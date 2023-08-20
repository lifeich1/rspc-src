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

const int N = 301001;
vector<int> a[N];

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
    int f, s;
    cin >> f >> s;
    a[f].emplace_back(s);
  }
  int m = -1;
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (a[i].size()) {
      sort(a[i].begin(), a[i].end());
      ans = max(ans, m + a[i].back());
      if (a[i].size() >= 2) {
        int t = a[i][a[i].size() - 2];
        t /= 2;
        t += a[i].back();
        ans = max(ans, t);
      }
      m = max(m, a[i].back());
    }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
