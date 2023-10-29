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
int64_t a[N];
pair<int64_t, int> p[N];
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
    int64_t m;
    cin >> n >> m;
    copy_n(std::istream_iterator<int64_t>(std::cin), n, a + 1);
    for (int i = 2; i <= n; ++i)
      p[i] = {a[i] - i * m, i};
    sort(p + 2, p + n + 1);
    int64_t s = a[1];
    int k = n;
    while (k > 1 && p[k].first + s >= 0) {
      s += a[p[k--].second];
    }

    if (k == 1) {
      cout << "Yes\n";
    } else
      cout << "No\n";
  }
  return 0;
}

// vim: ts=2 sw=2
