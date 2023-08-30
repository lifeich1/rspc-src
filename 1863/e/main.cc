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
int u[N], h[N], d[N], f[N], pa[N], sz[N], ll[N];
vector<int> e[N];

int &fa(int r) {
  if (r == pa[r])
    return pa[r];
  int &rc = fa(pa[r]);
  pa[r] = rc;
  return rc;
}
void uni(int x, int y) {
  x = fa(x), y = fa(y);
  if (x == y)
    return;
  if (sz[x] < sz[y])
    swap(x, y);
  pa[y] = x;
  sz[x] += sz[y];
}

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
    int n, m, K;
    cin >> n >> m >> K;
    for (int i = 1; i <= n; ++i)
      pa[i] = i, e[i].clear();
    fill(u, u + n + 1, 0);
    fill(d, d + n + 1, 0);
    fill(sz, sz + n + 1, 1);
    fill(f, f + n + 1, 0);
    copy_n(std::istream_iterator<int>(std::cin), n, h + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      e[u].emplace_back(v);
      d[v]++;
    }
    int nll = 0;
    for (int i = 1; i <= n; ++i) {
      if (u[i] || d[i])
        continue;
      set<tuple<int, int, int>> ls;
      ls.emplace(f[i], h[i], i);
      pair<int, int> R = {0, h[i]};
      while (ls.size()) {
        auto [x, y, r] = *ls.begin();
        u[r] = 1;
        ll[nll++] = r;
        ls.erase(ls.begin());
        R = max(R, make_pair(x, y));
        for (auto p : e[r]) {
          int t = x;
          if (y > h[p])
            ++t;
          f[p] = max(f[p], t);
          uni(r, p);
          if (--d[p] == 0) {
            ls.emplace(f[p], h[p], p);
          }
        }
      }
    }

    pair<int, int> R = {0, 0};
    for (int i = 1; i <= n; ++i)
      R = max(R, make_pair(f[i], h[i]));
    vector<pair<int, int>> hh;
    for (int i = 1; i <= n; ++i)
      if (0 == f[i])
        hh.emplace_back(h[i], i);
    sort(hh.begin(), hh.end());

    int64_t ans = -1;
    auto upd = [&](int y, pair<int, int> R) {
      TLN(TV(y); cerr << R.first << ' ' << R.second);
      auto [u, v] = R;
      int64_t t = u;
      t *= K;
      t += v - y;
      if (ans < 0 || ans > t)
        ans = t;
    };

    for (auto [l, x] : hh) {
      upd(l, R);
      if (0 != f[x])
        continue;
      vector<int> ls;
      ls.emplace_back(x);
      f[x]++;
      for (int i = 0; i < ls.size(); ++i) {
        int x = ls[i];
        R = max(R, make_pair(f[x], h[x]));
        for (int y : e[x]) {
          int t = f[x];
          if (h[y] < h[x])
            ++t;
          if (t > f[y]) {
            f[y] = t;
            ls.emplace_back(y);
          }
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
