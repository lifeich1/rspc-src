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

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  vector<int> a;
  while (tt--) {
    int n;
    int64_t m;
    cin >> n >> m;
    a.clear();
    a.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    auto chk = [&](int w) {
      w <<= 1;
      auto s = m;
      for (auto i : a) {
        int64_t t = i + w;
        t *= t;
        if (t > s)
          return 1;
        s -= t;
      }
      return s > 0 ? -1 : 0;
    };
    if (chk(0) == 0) {
      cout << "0\n";
      continue;
    }
    int k = 1, r;
    while ((r = chk(k)) < 0)
      k <<= 1;
    if (0 == r) {
      cout << k << endl;
      continue;
    }
    k >>= 1;
    int ans = k;
    for (k >>= 1; k > 0; k >>= 1) {
      r = chk(k + ans);
      if (r <= 0) {
        ans += k;
        if (0 == r)
          break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
