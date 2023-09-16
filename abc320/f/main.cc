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

const int N = 333;
int F[2][N][N], ps[N], fl[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, H;
  cin >> n >> H;
  vector<int> xs;
  copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(xs));
  for (int i = 0; i < n - 1; ++i) {
    cin >> ps[i] >> fl[i];
  }
  auto f = F[0], g = F[1];
  auto clr = [&](auto *f) {
    for (int i = 0; i <= H; ++i)
      fill(f[i], f[i] + H + 1, -1);
  };
  clr(f);
  f[H][0] = 0;
  int la = 0;
  auto upd = [](int &x, int y) {
    if (y > -1 && (y < x || -1 == x))
      x = y;
  };
  for (int k = 0; k < n; ++k) {
    const int co = xs[k] - la;
    la = xs[k];
    swap(f, g);
    clr(f);
    TLN(TV(k));
    for (int i = co; i <= H; ++i) {
      copy_n(g[i], H - co + 1, f[i - co] + co);
    }
    if (k < n - 1) {
      for (int i = H - co; i >= 0; --i)
        for (int j = co; j <= H; ++j) {
          if (f[i][j] < 0)
            continue;
          upd(f[min(i + fl[k], H)][j], f[i][j] + ps[k]);
          upd(f[i][max(j - fl[k], 0)], f[i][j] + ps[k]);
        }
    }
#if defined(RSPC_TRACE_HINT)
    for (int i = 0; i <= H; ++i) {
      for (int j = 0; j <= H; ++j)
        cerr << setw(4) << f[i][j];
      cerr << endl;
    }
#endif
  }
  int ans = -1;
  for (int i = 0; i <= H; ++i)
    for (int j = 0; j <= i; ++j)
      if (f[i][j] >= 0)
        upd(ans, f[i][j]);
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
