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

int zi(char m[4][4]) {
  int r = 0;
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      if (m[i][j] == '#')
        r |= 1 << (i * 4 + j);
  return r;
}

void unzi(int x, char m[4][4]) {
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j, x >>= 1)
      m[i][j] = ((x & 1) ? '#' : '.');
}

optional<int> tr(int rm, int x, int y) {
  char m[4][4], d[4][4];
  unzi(rm, m);
  unzi(0, d);
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j) {
      int u = i + x, v = j + y;
      if (u >= 0 && u < 4 && v >= 0 && v < 4) {
        d[u][v] = m[i][j];
      } else if (m[i][j] == '#')
        return nullopt;
    }
  int r = zi(d);
  if (__builtin_popcount(r) != __builtin_popcount(rm))
    return nullopt;
  return r;
}

int rota(int rm) {
  char m[4][4], d[4][4];
  unzi(rm, m);
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      d[i][j] = m[3 - j][i];
  return zi(d);
}

set<int> c[3];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  for (int a = 0; a < 3; ++a) {
    char m[4][4];
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        cin >> m[i][j];
    int e = zi(m);
    for (int ro = 0; ro < 4; ++ro) {
      for (int x = -3; x < 4; ++x)
        for (int y = -3; y < 4; ++y) {
          auto t = tr(e, x, y);
          if (t)
            c[a].emplace(*t);
        }
      e = rota(e);
    }
  }
  TLN(TV(c[0].find(0x232) != c[0].end()); TV(c[0].size()));
  TLN(TA(c[0], cerr << hex << "0x" << _ << ' '));
  TLN(TV(tr(0x270, -1, 0).value_or(-1)));
  const int M = (1 << 16) - 1;
  for (int i : c[0]) {
    for (int j : c[1]) {
      if (i & j)
        continue;
      int k = M ^ i ^ j;
      if (c[2].find(k) != c[2].end()) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}

// vim: ts=2 sw=2
