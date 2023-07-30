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

  vector<int> a;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    a.resize(n);
    copy_n(std::istream_iterator<int>(std::cin), n, a.begin());
    transform(a.begin() + 1, a.end(), a.begin(), a.begin(), minus<int>{});
    a.resize(n - 1);
    int k = *min_element(a.begin(), a.end());
    if (k < 0) {
      cout << "0\n";
    } else {
      cout << (k / 2 + 1) << endl;
    }
  }
  return 0;
}

// vim: ts=2 sw=2
