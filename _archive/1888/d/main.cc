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
const int N = 101001;
int a[N], b[N], f[N];

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
    int n, m;
    cin >> n >> m;
    a[0] = 1;
    copy_n(std::istream_iterator<int>(std::cin), n - 1, a + 1);
    copy_n(std::istream_iterator<int>(std::cin), n, b);
    sort(a, a + n);
    sort(b, b + n);
    int64_t ans = 0;

    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
      f[i] = (upper_bound(b, b + n, a[i]) - b) - i;
      s.emplace(f[i], i);
    }
    b[n] = a[n] = m + 1;
    for (int z = 1, p = 0; z <= m;) {
      int nz = a[p + 1] + 1;
      nz = min(nz, b[p + f[p]]);
      nz = min(m + 1, nz);
      ans += int64_t(nz - z) * s.rbegin()->first;
      z = nz;
      s.erase(s.find(make_pair(f[p], p)));
      TLN(TV(z); TV(a[p + 1]); TV(b[p + f[p]]); TV(p + f[p]));
      while (z > a[p + 1]) {
        if (p < n) {
          TLN(TV(p); TV(f[p + 1]););
          s.erase(s.find(make_pair(f[p + 1], p + 1)));
          f[p] = f[p + 1] + 1;
          s.emplace(f[p], p);
        }
        ++p;
      }
      f[p] = (upper_bound(b, b + n, z) - b) - p;
      s.emplace(f[p], p);
    }

    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
