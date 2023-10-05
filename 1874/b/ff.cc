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

int ra[8][4], nx[8][4];

int gra(int i, int j) {
  int &v = ra[i][j];
  if (v != -1)
    return v;
  v = 0;
  for (int k = 0; k < 4; ++k) {
    int t = gra(nx[i][k] + (i >= 4 ? 4 : 0), j);
    if (t > 0)
      v |= 1 << k;
  }
  return v;
}

int abl(int a, int b, int c, int d, int m) {
  int sm = 15;
  for (int i = 0; i < 30 && sm > 0; ++i) {
    sm &= gra((a & 1) + (b & 1) * 2 + (m & 1) * 4, (c & 1) + (d & 1) * 2);
    a >>= 1, b >>= 1, c >>= 1, d >>= 1, m >>= 1;
  }
  return sm;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  vector<tuple<int, int, int, int>> ls;
  for (int i = 0; i < 8; ++i) {
    int x = i & 1, y = (i >> 1) & 1, m = (i >> 2) & 1;
    auto g = [](int x, int y) { return x + y + y; };
    nx[i][0] = g(x & y, y);
    nx[i][1] = g(x | y, y);
    nx[i][2] = g(x, x ^ y);
    nx[i][3] = g(x, m ^ y);
    fill(ra[i], ra[i] + 4, -1);
    ra[i][g(x, y)] = 15;
  }

  while (tt--) {
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    map<int64_t, int> f;
    auto F = [&](int x, int y) -> int & {
      int64_t t = x;
      t <<= 30;
      t |= y;
      return f[t];
    };
    F(a, b) = 1;
    ls.clear();
    ls.emplace_back(a, b, 1, abl(a, b, c, d, m));
    bool keep = true;
    auto upd = [&](int x, int y, int v) {
      int &a = F(x, y);
      int dr = 0;
      if (0 == a && (dr = abl(x, y, c, d, m)) > -1) {
        a = v + 1;
        ls.emplace_back(x, y, a, dr);
        if (x == c && y == d)
          keep = false;
      } else {
        TLN(TV(x); TV(y); TV(v); TV(dr));
      }
    };
    for (unsigned i = 0; keep && i < ls.size(); ++i) {
      const auto [x, y, v, dr] = ls[i];
      upd(x & y, y, v);
      upd(x | y, y, v);
      upd(x, y ^ x, v);
      upd(x, y ^ m, v);
    }
    TLN(TV(f.size()));
    TLN(TA(ls, cerr << "(" << get<0>(_) << ',' << get<1>(_) << ',' << get<2>(_)
                    << ',' << get<3>(_) << ") "));
    cout << F(c, d) - 1 << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
