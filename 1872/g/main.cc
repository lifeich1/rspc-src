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
const int N = 201001;
int a[N], sp[N], mp[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  const int m = 1 << 21;
  while (tt--) {
    int n;
    cin >> n;
    copy_n(std::istream_iterator<int>(std::cin), n, a);
    int l = 0, r = n - 1;
    while (1 == a[l] && l < n - 1)
      ++l;
    while (1 == a[r] && r > l)
      --r;
    int64_t t = 1, ts = 0;
    for (int i = l; i <= r; ++i) {
      ts += a[i];
      t *= a[i];
      if (t > m)
        t = m;
    }
    if (t >= m || l == r) {
      ++l, ++r;
      cout << l << ' ' << r << endl;
      continue;
    }
    vector<int> ps;
    mp[0] = 1, sp[0] = 0;
    for (int i = 0; i < n; ++i) {
      sp[i + 1] = sp[i] + a[i];
      mp[i + 1] = mp[i] * a[i];
      if (a[i] > 1)
        ps.emplace_back(i);
    }
    int bs = 0;
    l = 1, r = 1;
    for (int i = 0; i < ps.size(); ++i)
      for (int j = i + 1; j < ps.size(); ++j) {
        int x = ps[i], y = ps[j];
        int t = mp[y + 1] / mp[x] - sp[y + 1] + sp[x];
        if (t > bs) {
          bs = t;
          l = x + 1, r = y + 1;
          TLN(TV(tt); TV(bs); TV(l); TV(r));
        }
      }
    cout << l << ' ' << r << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
