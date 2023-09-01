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
int s[N], a[N];

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
    copy_n(std::istream_iterator<int>(std::cin), n, a);
    s[n] = 0;
    s[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i)
      s[i] = s[i + 1] + (a[i] >= a[i + 1] ? 1 : 0);
    int ans = s[0], l = 0;
    for (int i = 0; i < n; ++i) {
      if (i)
        l += a[i - 1] <= a[i];
      ans = min(ans, l + 1 + s[i + 1]);
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
