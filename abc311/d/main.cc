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
#define TA(VEC, ITEM, ...)                                                     \
  TRACE(cerr << #VEC << "= ";                                                  \
        for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR))
using namespace std;
#define self_todo_placeholder

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  vector<string> c;
  copy_n(std::istream_iterator<std::string>(std::cin), n,
         std::back_inserter(c));
  vector<tuple<int, int, int>> lis;
  map<pair<int, int>, int> u;
  u[make_pair(2, 2)] = 15;
  for (int i = 0; i < 4; ++i)
    lis.emplace_back(2, 2, i);
  for (int p = 0; p < lis.size(); ++p) {
    auto [x, y, d] = lis[p];
    TLN(cerr << ' ' << x << ' ' << y << ' ' << d);
    auto x1 = x, y1 = y;
    switch (d) {
    case 0:
      x1++;
      break;
    case 1:
      x1--;
      break;
    case 2:
      y1++;
      break;
    case 3:
      y1--;
      break;
    }
    if (c[x1 - 1][y1 - 1] == '#') {
      auto &K = u[make_pair(x, y)];
      int k = ~K;
      K = 15;
      for (int i = 0; i < 4; ++i)
        if ((1 << i) & k) {
          lis.emplace_back(x, y, i);
        }
    } else {
      auto &k = u[make_pair(x1, y1)];
      if (k & (1 << d))
        continue;
      k |= (1 << d);
      lis.emplace_back(x1, y1, d);
    }
  }
  cout << u.size() << endl;
  return 0;
}

// vim: ts=2 sw=2
