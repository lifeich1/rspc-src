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
    int n;
    string s;
    cin >> n >> s;
    int off = 0;
    if (n & 1) {
      cout << "-1\n";
      continue;
    }
    list<int> ls;
    transform(s.begin(), s.end(), std::back_inserter(ls),
              [](char ch) { return ch - '0'; });
    vector<int> ans;
    while (ans.size() < 300 && ls.size()) {
      if (ls.front() != ls.back()) {
        ls.pop_back();
        ls.pop_front();
        ++off;
        continue;
      }
      if (ls.front() == 0) {
        ans.emplace_back(off + ls.size());
        ls.push_back(0);
        ls.push_back(1);
      } else {
        ans.emplace_back(off);
        ls.push_front(1);
        ls.push_front(0);
      }
    }
    if (ls.size())
      cout << "-1\n";
    else {
      cout << ans.size() << endl;
      copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
      cout << endl;
    }
  }
  return 0;
}

// vim: ts=2 sw=2
