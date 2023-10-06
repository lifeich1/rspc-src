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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a, b;
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    copy_n(std::istream_iterator<int>(std::cin), m, std::back_inserter(b));
    int &mia = *min_element(a.begin(), a.end());
    int &mxb = *max_element(b.begin(), b.end());
    if (mia < mxb)
      swap(mia, mxb);
    if (0 == (k & 1)) {
      int &mib = *min_element(b.begin(), b.end());
      int &mxa = *max_element(a.begin(), a.end());
      if (mib < mxa)
        swap(mib, mxa);
    }
    int64_t ans = 0;
    for (auto t : a)
      ans += t;
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
