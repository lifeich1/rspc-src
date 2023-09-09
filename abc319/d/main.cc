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

  int n, m;
  cin >> n >> m;
  copy_n(std::istream_iterator<int>(std::cin), n, a);
  int64_t l, r;
  l = r = *max_element(a, a + n) + 1;
  --l;
  r *= n;
  auto cal = [&](int64_t w) {
    int r = 1;
    int64_t t = -1;
    for (int i = 0; i < n; ++i) {
      t += a[i] + 1;
      if (t > w) {
        ++r, t = a[i];
      }
    }
    return r;
  };
  while (l < r) {
    auto mi = (l + r) >> 1;
    auto t = cal(mi);
    if (t > m)
      l = mi + 1;
    else
      r = mi;
  }
  cout << l << endl;
  return 0;
}

// vim: ts=2 sw=2
