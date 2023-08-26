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

vector<string> c;

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  c.reserve(n);
  copy_n(std::istream_iterator<std::string>(std::cin), n,
         std::back_inserter(c));
  map<char, pair<int, int>> pd;
  pd['>'] = {0, 1};
  pd['<'] = {0, -1};
  pd['^'] = {-1, 0};
  pd['v'] = {1, 0};
  auto is_p = [&](char ch) { return pd.find(ch) != pd.end(); };
  auto is_nc = [&](int i, int j) {
    return i < 0 || j < 0 || i >= n || j >= m || c[i][j] == '#' ||
           is_p(c[i][j]);
  };
  auto is_bl = [&](int i, int j) { return is_nc(i, j) || c[i][j] == '0'; };

  vector<tuple<int, int, int>> ls;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      auto ch = c[i][j];
      if (is_p(ch)) {
        auto [dx, dy] = pd[ch];
        int x = i + dx, y = j + dy;
        while (!is_nc(x, y)) {
          c[x][y] = '0';
          x += dx;
          y += dy;
        }
      }
      if (ch == 'S') {
        ls.emplace_back(i, j, 0);
        c[i][j] = '0';
      }
    }
  ls.reserve(n * m);
  int dd[] = {1, 0, -1, 0, 0, 1, 0, -1};
  for (int p = 0; p < ls.size(); ++p) {
    auto [x, y, v] = ls[p];
    ++v;
    for (int i = 0; i < 8; i += 2) {
      int tx = x + dd[i], ty = y + dd[i + 1];
      if (is_bl(tx, ty))
        continue;
      if (c[tx][ty] == 'G') {
        cout << v << endl;
        TLN(TV(ls.size()));
        return 0;
      }
      ls.emplace_back(tx, ty, v);
      c[tx][ty] = '0';
    }
  }
  TLN(TV(ls.size()));
  cout << "-1\n";
  return 0;
}

// vim: ts=2 sw=2
