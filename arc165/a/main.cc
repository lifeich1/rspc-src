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

vector<int> ps;
const int N = 40000;

int ip[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  ps.reserve(4400);
  for (int i = 2; i < N; ++i)
    if (0 == ip[i]) {
      ps.emplace_back(i);
      if (i * i < N)
        for (int t = i + i; t < N; t += i)
          ip[t] = 1;
    }

  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    int s = 0;
    for (int p : ps)
      if (x % p == 0) {
        ++s;
        while (x % p == 0)
          x /= p;
      }
    if (x > 1)
      ++s;
    cout << (s < 2 ? "No" : "Yes") << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
