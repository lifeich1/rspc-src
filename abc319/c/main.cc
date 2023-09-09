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

int a[5][5];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> a[i][j];
  int s = 362880, ans = 0;
  vector<int> p;
  for (int i = 0; i < 9; ++i)
    p.emplace_back(i);
  vector<int> d[8];
  do {
    ++ans;
    for (int i = 0; i < 8; ++i)
      d[i].clear();
    for (auto x : p) {
      int i = x / 3, j = x % 3;
      d[i].emplace_back(a[i][j]);
      d[j + 3].emplace_back(a[i][j]);
      if (i == j)
        d[6].emplace_back(a[i][j]);
      if (2 - i == j)
        d[7].emplace_back(a[i][j]);
    }
    for (int i = 0; i < 8; ++i)
      if (d[i][0] == d[i][1]) {
        --ans;
        break;
      }
  } while (next_permutation(p.begin(), p.end()));
  cout << fixed << setprecision(20) << static_cast<double>(ans) / s << endl;
  return 0;
}

// vim: ts=2 sw=2
