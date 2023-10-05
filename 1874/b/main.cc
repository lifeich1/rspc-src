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
  return v;
}

int abl(int a, int b, int c, int d, int m, int vv = 0) {
  int sm = 15;
  for (int i = 0; i < 30 && sm > 0; ++i) {
    sm &= gra((a & 1) + (b & 1) * 2 + (m & 1) * 4, (c & 1) + (d & 1) * 2);
#if defined(RSPC_TRACE_HINT)
    if (vv)
      TLN(TV(i); TV(sm); TV((a & 1) + (b & 1) * 2 + (m & 1) * 4);
          TV((c & 1) + (d & 1) * 2);
          TV(gra((a & 1) + (b & 1) * 2 + (m & 1) * 4, (c & 1) + (d & 1) * 2)));
#endif
    a >>= 1, b >>= 1, c >>= 1, d >>= 1, m >>= 1;
  }
  return sm;
}

unordered_map<int64_t, int> F;
int64_t ban = 0;
int64_t nk(int64_t x, int k) {
  int64_t r = 0;
  for (int i = 0; i < 32; ++i) {
    if ((x >> i) & 1) {
      int st = i & 7, ds = i >> 3;
      st = nx[st][k] | (st & 4);
      r |= int64_t(1) << int64_t(ds * 8 + st);
    }
  }
  return r;
}
int qf(int64_t x) {
  if (x & ban)
    return 0;
  if (F.count(x) != 0)
    return F[x];
  bool ok = true;
  for (int i = 0; i < 32; ++i)
    if ((x >> i) & 1) {
      int st = i & 7, ds = i >> 3;
      if (ds != (st & 3)) {
        ok = false;
        break;
      }
    }
  int &v = F[x];
  v = 0;
  if (ok) {
    v = 1;
    return v;
  }
  for (int k = 0; k < 4; ++k) {
    auto y = nk(x, k);
    auto t = qf(y);
    if (t > 0 && (t + 1 < v || v == 0)) {
      v = t + 1;
    }
  }
  return v;
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
    fill(ra[i], ra[i] + 4, 0);
    ra[i][g(x, y)] = 15;
  }
  for (bool kp = true; kp;) {
    kp = 0;
    for (int st = 0; st < 8; ++st)
      for (int ds = 0; ds < 4; ++ds)
        for (int k = 0; k < 4; ++k) {
          int t = 1 << k;
          if (ra[st][ds] & t)
            continue;
          if (ra[nx[st][k] | (st & 4)][ds]) {
            ra[st][ds] |= t;
            kp = true;
          } else if (nx[st][k] == (st & 3) && ra[st][ds]) {
            ra[st][ds] |= t;
            kp = true;
          }
        }
  }
  for (int st = 0; st < 8; ++st)
    for (int ds = 0; ds < 4; ++ds)
      if (ra[st][ds] == 0) {
        int w = ds;
        w <<= 3;
        w |= st;
        ban |= int64_t(1) << w;
      }

  while (tt--) {
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    if (0 == abl(a, b, c, d, m)) {
      cout << "-1\n";
      continue;
    }
    int64_t s = 0;
    for (int i = 0; i < 30; ++i) {
      int64_t w = 0;
      w <<= 1;
      w |= d & 1;
      w <<= 1;
      w |= c & 1;
      w <<= 1;
      w |= m & 1;
      w <<= 1;
      w |= b & 1;
      w <<= 1;
      w |= a & 1;
      s |= int64_t(1) << w;
      a >>= 1, b >>= 1, c >>= 1, d >>= 1, m >>= 1;
      TV(w);
    }
    TLN(TV(s));
    cout << qf(s) - 1 << endl;
    TLN(TV(F.size()));
  }
  return 0;
}

// vim: ts=2 sw=2
