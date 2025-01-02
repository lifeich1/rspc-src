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

  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    vector<int> l, u;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == 'b') {
        if (l.size())
          l.pop_back();
      } else if (s[i] == 'B') {
        if (u.size())
          u.pop_back();
      } else if (isupper(s[i]))
        u.emplace_back(i);
      else
        l.emplace_back(i);
    }
    u.insert(u.end(), l.begin(), l.end());
    sort(u.begin(), u.end());
    for (auto x : u)
      cout << s[x];
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
