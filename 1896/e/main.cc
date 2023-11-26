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

const int N = 2001001;
int a[N], c[N], u[N], s[N], l[N];

void ta_a(int n, int x, int v) {
  while (x <= n) {
    s[x] += v;
    x += x & (-x);
  }
}

int ta_ps(int x) {
  int r = 0;
  while (x > 0) {
    r += s[x];
    x -= x & (-x);
  }
  return r;
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
    copy_n(std::istream_iterator<int>(std::cin), n, a + 1);
    fill(c, c + n + 1, -1);
    fill(u, u + n + 1, -1);
    fill(s, s + n + n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      u[a[i]] = ta_ps(i);
      l[a[i]] = i;
      if (u[i] != -1) {
        ta_a(n + n, l[i], 1);
        c[i] = ta_ps(l[i]) - u[i] - 1;
      } else
        ta_a(n + n, 1, 1);
    }
    for (int i = 1; i <= n; ++i) {
      u[a[i]] = ta_ps(i + n);
      l[a[i]] = i + n;
      if (u[i] != -1) {
        ta_a(n + n, l[i], 1);
        if (-1 == c[i])
          c[i] = ta_ps(l[i]) - u[i] - 1;
      } else
        ta_a(n + n, 1, 1);
    }
    copy_n(c + 1, n, std::ostream_iterator<int>(std::cout, " "));
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
