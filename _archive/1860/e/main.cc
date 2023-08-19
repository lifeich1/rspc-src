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
const int N = 52001, A = 32 * 26;
char s[N];
int _l[2][N], d[N], u[N];
vector<int> fm[A];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  cin >> s;
  int n = strlen(s);
  vector<pair<int, int>> Q;
  int q;
  cin >> q;
  Q.resize(q);
  vector<int> ans(q, n);
  for (int i = 0; i < q; ++i) {
    cin >> Q[i].first >> Q[i].second;
    ans[i] = abs(Q[i].first - Q[i].second);
  }
  auto dm = [&](int i) {
    int x = s[i - 1] - 'a';
    int y = s[i] - 'a';
    return (x << 5) + y + n;
  };
  for (int i = 1; i < n; ++i)
    fm[dm(i) - n].emplace_back(i);
  fill(u, u + n + A, -1);
  for (int i = 0; i < A; ++i) {
    if (fm[i].empty())
      continue;
    int *l = _l[0], *nl = _l[1];
    int p = 0, q = 0;
    u[n + i] = i;
    for (auto y : fm[i])
      u[y] = i, l[p++] = y;
    for (int dv = 0; p > 0; ++dv) {
      for (int ip = 0; ip < p; ++ip) {
        int x = l[ip];
        d[x] = dv;
        auto ad = [&](int y) {
          if (u[y] != i) {
            u[y] = i;
            nl[q++] = y;
          }
        };
        if (x > 1)
          ad(x - 1);
        if (x < n - 1)
          ad(x + 1);
        int z = dm(x);
        if (u[z] != i) {
          u[z] = i;
          z -= n;
          for (auto y : fm[z])
            ad(y);
        }
      }
      TLN(TV(p); TI(l, l + p, cerr << _ << ' '));
      p = q, q = 0;
      swap(l, nl);
    }

    // upd ans
    for (int k = 0; k < Q.size(); ++k) {
      auto [s, t] = Q[k];
      auto it = lower_bound(fm[i].begin(), fm[i].end(), s) - fm[i].begin();
      if (it >= fm[i].size() || (it > 0 && s - fm[i][it - 1] < fm[i][it] - s)) {
        --it;
      }
      ans[k] = min(ans[k], d[t] + abs(fm[i][it] - s) + 1);
    }
    TLN(TV(i >> 5); TV(i & 31); TV(d[dm(7)]); TV(dm(7)));
    TLN(TI(d + 1, d + n, cerr << _ << ' '));
  }
  copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, "\n"));

  return 0;
}

// vim: ts=2 sw=2
