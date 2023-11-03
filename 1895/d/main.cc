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
int a[N], s[18][1 << 18];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  copy_n(std::istream_iterator<int>(std::cin), n - 1, a);
  for (int i = 1; i < n - 1; ++i) {
    a[i] ^= a[i - 1];
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < 18; ++j) {
      int x = a[i] >> j;
      s[j][x]++;
    }
  }
  for (int st = 0; st < n; ++st) {
    int y = 0;
    for (int i = 17; i >= 0; --i) {
      int t = (st >> i) & 1;
      y <<= 1;
      y |= t ^ 1;
      if (s[i][y] == 0)
        y ^= 1;
    }
    if ((st ^ y) >= n)
      continue;
    cout << st;
    for (int i = 0; i < n - 1; ++i)
      cout << ' ' << (st ^ a[i]);
    break;
  }
  cout << endl;
  return 0;
}

// vim: ts=2 sw=2
