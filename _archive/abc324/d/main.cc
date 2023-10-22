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

int d[10];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  string s;
  cin >> s;
  for (char c : s) {
    d[c - '0']++;
  }
  int64_t b = 0, u = 0;
  for (int i = 1; i < 10; ++i)
    for (int j = 0; j < d[i]; ++j)
      b = b * 10 + i;
  for (int i = 9; i >= 0; --i)
    for (int j = 0; j < d[i]; ++j)
      u = u * 10 + i;
  int64_t bb = (int)floor(sqrt((double)b));

  int p[10];
  int64_t ii = bb * bb;
  int64_t a0 = 0;
  for (int64_t i = bb; ii <= u; ii += i + i + 1, ++i) {
    fill(p, p + 10, 0);
    for (auto t = ii; t > 0; t /= 10)
      p[t % 10]++;
    if (p[0] > d[0])
      continue;
    bool ok = true;
    for (int j = 1; j < 10; ++j)
      if (p[j] != d[j]) {
        ok = false;
        break;
      }
    if (ok)
      ++a0;
  }
  cout << a0 << endl;
  return 0;
}

// vim: ts=2 sw=2
