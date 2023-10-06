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

int nx[8][4];
unordered_map<int, int> f;
unordered_map<int, vector<int>> e;

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  vector<pair<int, int>> ls;
  for (int i = 0; i < 8; ++i) {
    int x = i & 1, y = (i >> 1) & 1, m = (i >> 2) & 1;
    auto g = [](int x, int y) { return x + y + y; };
    nx[i][0] = g(x & y, y) | (i & 4);
    nx[i][1] = g(x | y, y) | (i & 4);
    nx[i][2] = g(x, x ^ y) | (i & 4);
    nx[i][3] = g(x, m ^ y) | (i & 4);
  }
  TLN(TV(nx[3][0]));
  for (int i = 0; i < (1 << 8); ++i) {
    int r = 0;
    for (int p = 0; p < 8; ++p) {
      if ((i >> p) & 1) {
        r |= (p & 3) << (3 * p);
      } else {
        r |= 4 << (3 * p);
      }
    }
    f[r] = 0;
    ls.emplace_back(r, 0);
  }
  for (int i = 0, _i = 5 << 21; i < _i;) {
    for (int j = 0; j < 4; ++j) {
      bool ok = true;
      vector<int> h(8, 4);
      for (int p = 0; p < 8; ++p) {
        int t = (i >> (p * 3)) & 7;
        if (t != 4) {
          int y = nx[p][j];
          if (h[y] != 4 && h[y] != t) {
            ok = false;
            break;
          }
          h[y] = t;
        }
      }
      if (!ok)
        continue;
      int r = 0;
      for (int p = 0; p < 8; ++p) {
        r |= h[p] << (3 * p);
      }
      if (r != i) {
#if defined(RSPC_TRACE_HINT)
        if (i == 04400440) {
          TLN(cerr << oct; TV(r); TV(i); cerr << dec; TV(j); TV(ok));
        }
#endif
        e[r].emplace_back(i);
      }
    }
    int g = 0;
    while (g < 8 && ((i >> (g * 3)) & 7) >= 4) {
      i ^= i & (7 << (g * 3));
      ++g;
    }
    if (g >= 8)
      break;
    i += 1 << (3 * g);
  }
  for (size_t p = 0; p < ls.size(); ++p) {
    auto [x, v] = ls[p];
    ++v;
    for (auto y : e[x]) {
#if defined(RSPC_TRACE_HINT)
      if (y == 04400440) {
        TLN(cerr << oct; TV(x); TV(y); cerr << dec; TV(v));
      }
#endif
      if (f.count(y) == 0) {
        f[y] = v;
        ls.emplace_back(y, v);
      }
    }
  }

  while (tt--) {
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    vector<int> h(8, 4);
    bool ok = true;
    TLN(cerr << dec; TV(tt));
    for (int i = 0; i < 30; ++i) {
      int u = (m & 1) * 4 + (b & 1) * 2 + (a & 1);
      int v = (d & 1) * 2 + (c & 1);
      if (h[u] != 4 && h[u] != v) {
        ok = false;
        break;
      }
      h[u] = v;
#if defined(RSPC_TRACE_HINT)
      if ((u & 3) != v)
        TLN(TV(i); TV(u); TV(v));
#endif
      a >>= 1, b >>= 1, c >>= 1, d >>= 1, m >>= 1;
    }
    int ans = -1;
    if (ok) {
      int r = 0;
      for (int i = 0; i < 8; ++i) {
        r |= h[i] << (i * 3);
        TLN(TV(i); TV(h[i]); cerr << oct; TV(r); cerr << dec;);
      }
      TLN(cerr << oct; TV(r));
      if (f.count(r) != 0)
        ans = f[r];
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
