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
int sm[111];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; ++i)
    sm[i + 1] = sm[i] + (s[i] - '0');
  // ((1s) << 20) | (sured 01 - 10)
  const int z = 100000;
  map<int, int> f;
  f[z] = 0;
  const int M = (1 << 20) - 1;
  for (int i = 0; i < n; ++i) {
    map<int, int> g;
    g.swap(f);
    auto upd = [&](int k, int v) {
      if (f.count(k))
        f[k] = min(f[k], v);
      else
        f[k] = v;
    };
    for (auto [k, v] : g) {
      int x = k >> 20;
      int y = k & M;
      int d = s[i] - '0';
      // to 0
      int x0 = x + d;
      int y0 = x0 + sm[n] - sm[i + 1];
      if (y0 >= 0) {
        y0 += y;
        upd((x0 << 20) + y0, v + d);
      }
      // to 1
      int x1 = x - (1 - d);
      int y1 = -x1 + (n - i - 1) - (sm[n] - sm[i + 1]);
      if (y1 >= 0) {
        y1 = y - y1;
        upd((x1 << 20) + y1, v + 1 - d);
      }
    }
    TLN(TA(f, cerr << (_.first >> 20) << '^' << (_.first & M) << ": "
                   << _.second << ", "));
  }
  cout << f[z] / 2 << endl;
  return 0;
}

// vim: ts=2 sw=2
