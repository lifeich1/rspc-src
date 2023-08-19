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

const int N = 301001;
int a[N], b[N];

void sbit(int n, int x, int v) {
  for (; x <= n; x += x & (-x)) {
    a[x] += 1;
    b[x] += v;
  }
}
int gn(int x) {
  int c = 0;
  for (; x > 0; x -= x & (-x))
    if (a[x] != b[x])
      return 0;
    else
      c += a[x];
  return c != 0;
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
  while (tt--) {
    int n;
    cin >> n;
    fill(a, a + n + 1, 0);
    fill(b, b + n + 1, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      int v = gn(x) ^ 1;
      sbit(n, x, v);
      if (v == 0) {
        ++ans;
      }
      TLN(TV(i); TV(v));
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
