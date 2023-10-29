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

char c[9][9];
int n;
string R, C;
char tc[2][9];
bool sc[2][9][3];

vector<pair<int, int>> ps;

bool goodrc(int x, int y) {
  if (y == n - 1) {
    return sc[0][x][0] && sc[0][x][1] && sc[0][x][2];
  } else {
    return sc[1][y][0] && sc[1][y][1] && sc[1][y][2];
  }
}

bool finchk() {
  {
    int x = n - 1;
    if (sc[0][x][0] && sc[0][x][1] && sc[0][x][2]) {
    } else
      return false;
    if (sc[1][x][0] && sc[1][x][1] && sc[1][x][2]) {
    } else
      return false;
  }
  return true;
}

bool dfs(int d) {
  if (d == ps.size()) {
    return finchk();
  }
  string z = "ABC.";
  auto [x, y] = ps[d];
  for (char ch : z) {
    bool tc0 = false, tc1 = false;
    if (ch != '.') {
      if (sc[0][x][ch - 'A'])
        continue;
      if (sc[1][y][ch - 'A'])
        continue;
      if (0 == tc[0][x]) {
        if (R[x] != ch)
          continue;
      }
      if (0 == tc[1][y]) {
        if (C[y] != ch)
          continue;
      }
      if (0 == tc[0][x]) {
        tc0 = true;
        tc[0][x] = ch;
      }
      if (0 == tc[1][y]) {
        tc1 = true;
        tc[1][y] = ch;
      }
      sc[0][x][ch - 'A'] = true;
      sc[1][y][ch - 'A'] = true;
    }
    if ((n - 1 != x && n - 1 != y) || goodrc(x, y)) {
      c[x][y] = ch;
#if defined(RSPC_TRACE_HINT)
      TLN(TV(d));
      for (int i = 0; i < n; ++i)
        cerr << c[i] << endl;
#endif
      if (dfs(d + 1))
        return true;
      c[x][y] = '.';
    }
    if (ch != '.') {
      sc[0][x][ch - 'A'] = false;
      sc[1][y][ch - 'A'] = false;
    }
    if (tc0)
      tc[0][x] = 0;
    if (tc1)
      tc[1][y] = 0;
  }
  return false;
};

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  cin >> n >> R >> C;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      if (0 == c[i][j]) {
        c[i][j] = '.';
        ps.emplace_back(i, j);
      }
    for (int j = 0; j < n; ++j)
      if (0 == c[j][i]) {
        c[j][i] = '.';
        ps.emplace_back(j, i);
      }
  }
  TLN(TA(ps, cerr << _.first << ',' << _.second << ' '));
  if (dfs(0)) {
    cout << "Yes\n";
    for (int i = 0; i < n; ++i)
      cout << c[i] << endl;
    ;
  } else {
    cout << "No\n";
  }

  return 0;
}

// vim: ts=2 sw=2
