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
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR) << ' ')
using namespace std;
#define self_todo_placeholder

int sm[4][101][101][101];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<vector<int>> a;
  vector<vector<int>> pl[3][101];
  for (int i = 0; i < n; ++i) {
    vector<int> t;
    copy_n(std::istream_iterator<int>(std::cin), 6, std::back_inserter(t));
    pl[0][t[0]].emplace_back(vector<int>{t[1], t[2], t[4], t[5]});
    pl[0][t[3]].emplace_back(vector<int>{t[1], t[2], t[4], t[5]});
    pl[1][t[1]].emplace_back(vector<int>{t[0], t[2], t[3], t[5]});
    pl[1][t[4]].emplace_back(vector<int>{t[0], t[2], t[3], t[5]});
    pl[2][t[2]].emplace_back(vector<int>{t[0], t[1], t[3], t[4]});
    pl[2][t[5]].emplace_back(vector<int>{t[0], t[1], t[3], t[4]});
    a.emplace_back(std::move(t));
  }
  /*
   * 01
   * 32
   */
  vector<int> ans(n, 0);
  for (int p = 0; p < 3; ++p) {
    for (int i = 0; i < 4; ++i)
      for (int t0 = 0; t0 <= 100; ++t0)
        for (int t1 = 0; t1 <= 100; ++t1)
          fill(sm[i][t0][t1], sm[i][t0][t1] + 101, 0);
    for (int t0 = 0; t0 <= 100; ++t0) {
      for (auto &v : pl[p][t0]) {
        sm[0][t0][max(v[0], v[2])][max(v[1], v[3])]++;
        sm[1][t0][max(v[0], v[2])][min(v[1], v[3])]++;
        sm[2][t0][min(v[0], v[2])][min(v[1], v[3])]++;
        sm[3][t0][min(v[0], v[2])][max(v[1], v[3])]++;
      }
      for (int i = 1; i <= 100; ++i) {
        sm[0][t0][i][0] += sm[0][t0][i - 1][0];
        sm[0][t0][0][i] += sm[0][t0][0][i - 1];

        sm[1][t0][i][0] += sm[1][t0][i - 1][0];
        sm[1][t0][0][100 - i] += sm[1][t0][0][100 - i + 1];

        sm[2][t0][100 - i][0] += sm[2][t0][100 - i + 1][0];
        sm[2][t0][0][100 - i] += sm[2][t0][0][100 - i + 1];

        sm[3][t0][100 - i][0] += sm[3][t0][101 - i][0];
        sm[3][t0][0][i] += sm[3][t0][0][i - 1];
      }
      for (int i = 1; i <= 100; ++i)
        for (int j = 1; j <= 100; ++j) {
          sm[0][t0][i][j] += sm[0][t0][i - 1][j] + sm[0][t0][i][j - 1] -
                             sm[0][t0][i - 1][j - 1];
          sm[1][t0][i][100 - j] += sm[1][t0][i - 1][100 - j] +
                                   sm[1][t0][i][101 - j] -
                                   sm[1][t0][i - 1][101 - j];
          sm[2][t0][100 - i][100 - j] += sm[2][t0][101 - i][100 - j] +
                                         sm[2][t0][100 - i][101 - j] -
                                         sm[2][t0][101 - i][101 - j];
          sm[3][t0][100 - i][j] += sm[3][t0][101 - i][j] +
                                   sm[3][t0][100 - i][j - 1] -
                                   sm[3][t0][101 - i][j - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
      vector<int> v = a[i];
      v.erase(v.begin() + 3 + p);
      v.erase(v.begin() + p);
      if (v[0] > v[2])
        swap(v[0], v[2]);
      if (v[1] > v[3])
        swap(v[1], v[3]);
      auto gs = [&](int t0, auto &v) {
        return sm[0][t0][v[0]][100] + sm[0][t0][100][v[1]] +
               sm[2][t0][v[2]][0] + sm[2][t0][0][v[3]] - sm[1][t0][v[0]][v[3]] -
               sm[3][t0][v[2]][v[1]];
      };
      ans[i] += sm[2][v[p]][0][0] - gs(v[p], v) - 1;
      TLN(TV(i); TV(ans[i]));
      ans[i] += sm[2][v[p + 3]][0][0] - gs(v[p + 3], v) - 1;
      TLN(TV(i); TV(ans[i]));
    }
  }
  copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, "\n"));
  return 0;
}

// vim: ts=2 sw=2
