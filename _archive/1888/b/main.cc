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
const int N = 201001;
int a[N];

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
    int n, K;
    cin >> n >> K;
    copy_n(std::istream_iterator<int>(std::cin), n, a);
    int ans = K;
    for (int i = 0; i < n; ++i) {
      int t = a[i] % K;
      if (t == 0)
        ans = 0;
      else
        ans = min(ans, K - t);
    }
    if (4 == K && ans > 0) {
      for (int i = 0; i < n; ++i)
        a[i] %= 2;
      sort(a, a + n);
      if (0 == a[1])
        ans = 0;
      else if (0 == a[0])
        ans = min(ans, 1);
      else
        ans = min(ans, 2);
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
