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
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR) << ' ')
using namespace std;
#define self_todo_placeholder

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  vector<int> a, b;
  a.reserve(n);
  b.reserve(m);
  map<int, int> c;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    c[x]++;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    c[x + 1]++;
  }
  int s = -m;
  for (auto [k, v] : c) {
    s += v;
    TLN(TV(s); TV(k); TV(v));
    if (s >= 0) {
      cout << k << endl;
      break;
    }
  }

  return 0;
}

// vim: ts=2 sw=2
