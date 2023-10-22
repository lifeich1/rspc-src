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
  vector<int> ans;
  int L = T.length();
  for (int tt = 1; tt <= n; ++tt) {
    string s;
    cin >> s;
    int l = s.length();
    if (abs(l - L) > 1)
      continue;
    if (l == L) {
      int t = 0;
      for (int i = 0; i < l; ++i)
        if (s[i] != T[i])
          t++;
      if (t <= 1)
        ans.emplace_back(tt);
      continue;
    }
    int el = 0, er = 0;
    int ml = min(l, L);
    while (el < ml && s[el] == T[el])
      ++el;
    while (er < ml && s[l - er - 1] == T[L - er - 1])
      ++er;
    if (el + er >= ml)
      ans.emplace_back(tt);
  }
  cout << ans.size() << endl;
  if (ans.size()) {
    copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
