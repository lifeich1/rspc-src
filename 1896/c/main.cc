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
    int n, X;
    cin >> n >> X;
    vector<int> a, b;
    a.reserve(n);
    b.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(b));
    vector<pair<int, int>> ha;
    ha.reserve(n);
    for (int i = 0; i < n; ++i)
      ha.emplace_back(a[i], i);
    sort(ha.begin(), ha.end());
    sort(b.begin(), b.end());
    vector<int> c(b.begin() + X, b.end());
    c.reserve(n);
    for (int i = 0; i < X; ++i)
      c.emplace_back(b[i]);
    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
      auto [k, x] = ha[i];
      b[x] = c[i];
      if (i < n - X)
        ok = k <= c[i];
      else
        ok = k > c[i];
    }
    if (ok) {
      cout << "YES\n";
      copy(b.begin(), b.end(), std::ostream_iterator<int>(std::cout, " "));
      cout << endl;
    } else
      cout << "NO\n";
  }

  return 0;
}

// vim: ts=2 sw=2
