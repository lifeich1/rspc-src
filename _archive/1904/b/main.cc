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
    vector<int> a;
    vector<int64_t> s;
    int n;
    cin >> n;
    a.reserve(n);
    s.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    vector<int> b(a);
    sort(a.begin(), a.end());
    s[0] = a[0];
    for (int i = 1; i < n; ++i)
      s[i] = s[i - 1] + a[i];
    map<int, int> c;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && a[i - 1] == a[i])
        continue;
      int k = i;
      int64_t ts = s[i];
      while (ts < a.back()) {
        int t =
            upper_bound(a.begin(), a.end(), static_cast<int>(ts)) - a.begin();
        --t;
        if (t > k) {
          k = t;
          ts = s[k];
        } else
          break;
      }
      TLN(TV(a[i]); TV(k); TV(ts));
      if (ts >= a.back())
        k = n - 1;
      c[a[i]] = k;
    }
    for (const auto &x : b)
      cout << c[x] << ' ';
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
