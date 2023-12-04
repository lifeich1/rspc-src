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

const int N = 100001;
int lp[N], c[N];
vector<int> ps;
vector<int> h[N];
int64_t f[N];

void getds(vector<int> &ds, int x) {
  ds.clear();
  ds.emplace_back(1);
  while (x > 1) {
    int t = lp[x];
    if (0 == t)
      t = x;
    int k = 1;
    x /= t;
    while (x % t == 0)
      ++k, x /= t;
    int m = ds.size();
    for (int i = 0, u = t; i < k; ++i, u *= t)
      for (int j = 0; j < m; ++j)
        ds.emplace_back(ds[j] * u);
  }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif
  for (int i = 2; i < N; ++i) {
    if (0 == lp[i])
      ps.emplace_back(i);
    for (int p : ps) {
      int t = p * i;
      if (t >= N)
        break;
      lp[t] = p;
      if (i % p == 0)
        break;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a;
    a.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    sort(a.begin(), a.end());
    vector<int> ds;
    for (int i = 1; i <= a.back(); ++i)
      h[i].clear();
    for (int i = 0; i < n; ++i) {
      if (0 == i || a[i] > a[i - 1]) {
        getds(ds, a[i]);
      }
      for (int d : ds) {
        h[d].emplace_back(i);
      }
    }
    fill(f, f + a.back() + 1, 0);
    for (int i = 1; i <= a.back(); ++i) {
      auto &v = f[i];
      for (int k = 1; k < h[i].size(); ++k)
        v += int64_t(n - h[i][k] - 1) * k;
    }
    for (int i = a.back(); i > 0; --i) {
      for (int t = i + i; t <= a.back(); t += i)
        f[i] -= f[t];
    }
    int64_t ans = 0;
    for (int i = 1; i <= a.back(); ++i)
      ans += f[i] * i;
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
