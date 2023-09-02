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
const int N = 101001;
int a[N], u[N];

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
    int n, k;
    cin >> n >> k;
    fill(u, u + n + 1, 0);
    copy_n(std::istream_iterator<int>(std::cin), n, a);
    for_each(a, a + n, [&](int x) { u[x] = 1; });
    for (int i = 0; i <= n; ++i)
      if (u[i] == 0) {
        a[n] = i;
        break;
      }
    k %= n + 1;
    k = n + 1 - k;
    for (int i = 0; i < n; ++i, ++k) {
      if (k > n)
        k = 0;
      cout << a[k] << ' ';
    }
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
