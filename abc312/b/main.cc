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

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  vector<string> M = {"###.     ", "###.     ", "###.     ",
                      "....     ", "         ", "     ....",
                      "     .###", "     .###", "     .###"};
  int n, m;
  cin >> n >> m;
  vector<string> c;
  copy_n(std::istream_iterator<std::string>(std::cin), n,
         std::back_inserter(c));
  auto chk = [&](int a, int b) {
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j)
        if (M[i][j] != ' ') {
          if (M[i][j] != c[a + i][b + j])
            return false;
        }
    return true;
  };
  for (int i = 0; i <= n - 9; ++i)
    for (int j = 0; j <= m - 9; ++j)
      if (chk(i, j)) {
        cout << i + 1 << ' ' << j + 1 << endl;
      }
  return 0;
}

// vim: ts=2 sw=2
