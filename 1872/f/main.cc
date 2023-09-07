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
int a[N], d[N];
pair<int, int> h[N];

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
    fill(d, d + n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      int c;
      cin >> c;
      h[i] = {c, i};
      d[a[i]]++;
    }
    sort(h + 1, h + 1 + n);
    for (int i = 1; i <= n; ++i) {
      if (d[i] != 0)
        continue;
      for (int x = i; 0 == d[x]; --d[x = a[x]]) {
        d[x] = -1;
        cout << x << ' ';
      }
    }
    for (int i = 1; i <= n; ++i) {
      auto [c, x] = h[i];
      if (d[x] > 0) {
        x = a[x];
        --d[x];
        for (; 0 == d[x]; --d[x = a[x]]) {
          d[x] = -1;
          cout << x << ' ';
        }
      }
    }
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
