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
  string T;
  cin >> n >> T;
  vector<int> lf, rf;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int p, q;
    for (p = 0, q = 0; p < s.length() && q < T.length(); ++p) {
      if (s[p] == T[q])
        ++q;
    }
    lf.emplace_back(q);
    for (p = s.length() - 1, q = T.length() - 1; p >= 0 && q >= 0; --p)
      if (s[p] == T[q])
        --q;
    rf.emplace_back(T.length() - q - 1);
  }
  sort(rf.begin(), rf.end());
  int64_t ans = 0;
  for (const auto l : lf) {
    int t = lower_bound(rf.begin(), rf.end(), T.length() - l) - rf.begin();
    ans += rf.size() - t;
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
