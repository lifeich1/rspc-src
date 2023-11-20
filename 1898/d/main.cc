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

void vm(int64_t &x, int64_t y) {
  if (x < y)
    x = y;
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
    vector<int> a, b;
    a.reserve(n);
    b.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(b));
    int64_t d1, d2, d3, d4;
    d1 = (a[0] - b[0] - abs(a[0] - b[0]));
    d2 = (-a[0] + b[0] - abs(a[0] - b[0]));
    d3 = (a[0] + b[0] - abs(a[0] - b[0]));
    d4 = (-a[0] - b[0] - abs(a[0] - b[0]));
    int64_t ans = 0;
    for (int i = 1; i < n; ++i) {
      int64_t t = abs(a[i] - b[i]);
      int64_t t1 = -t + a[i] - b[i];
      int64_t t2 = -t - a[i] + b[i];
      int64_t t3 = -t - a[i] - b[i];
      int64_t t4 = -t + a[i] + b[i];
      t1 += d1;
      t2 += d2;
      t3 += d3;
      t4 += d4;
      vm(ans, t1);
      vm(ans, t2);
      vm(ans, t3);
      vm(ans, t4);
      vm(d1, a[i] - b[i] - t);
      vm(d2, -a[i] + b[i] - t);
      vm(d3, a[i] + b[i] - t);
      vm(d4, -a[i] - b[i] - t);
    }
    for (int i = 0; i < n; ++i)
      ans += abs(a[i] - b[i]);
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
