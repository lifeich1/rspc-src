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

  int tt;
  cin >> tt;
  vector<int> a;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    a.resize(n);
    copy_n(std::istream_iterator<int>(std::cin), n, a.begin());
    multiset<int64_t> co;
    a[0] %= k;
    int64_t ans = a[0], l = a[0];
    co.insert(k);
    TLN(TV(ans); TV(l));
    for (int i = 1; i < n; ++i) {
      int64_t t = a[i] % k;
      t += l - l % k;
      if (t >= k && t > l)
        t -= k;
      co.insert(t + k - l);
      if (t <= l) {
        l = t;
      } else {
        co.insert(t - l);
        l = t;
        ans += *co.begin();
        co.erase(co.begin());
      }
      TLN(TV(i); TV(ans); TV(l));
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
