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

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<pair<int64_t, int64_t>> a;
  for (int i = 0; i < n; ++i) {
    int64_t T, D;
    cin >> T >> D;
    a.emplace_back(T, T + D);
  }
  sort(a.begin(), a.end());
  int64_t l = -1;
  int ans = 0;
  multiset<int64_t> z;
  for (int i = 0; i < n || z.size() > 0;) {
    if (i < n && (z.empty() || l >= a[i].first)) {
      if (l < a[i].first)
        l = a[i].first;
      z.emplace(a[i].second);
      ++i;
    } else {
      auto t = *z.begin();
      z.erase(z.begin());
      if (t >= l) {
        ++l;
        ++ans;
        TLN(TV(ans); TV(l); TV(t));
      }
    }
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
