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
#define TA(VEC, ITEM, ...)                                                     \
  TRACE(cerr << #VEC << "= ";                                                  \
        for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR))
using namespace std;
#define self_todo_placeholder
const int N = 201001;
int f[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  map<int, int> a;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    a.clear();
    cin >> n;
    fill(f, f + n + 1, 0);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a[x]++;
    }
    for (auto [k, v] : a) {
      for (int t = k; t <= n; t += k)
        f[t] += v;
    }
    cout << (*max_element(f, f + n + 1)) << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
