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
const int N = 1001001;
vector<int> sn[N];
int pa[N], z[N];
int g[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  copy_n(std::istream_iterator<int>(std::cin), n - 1, pa + 2);
  int64_t ans = 0;
  for (int i = n; i > 0; --i) {
    z[i]++;
    fill(g + 1, g + z[i] + 1, 0);
    g[0] = 1;
    int l = 0;
    for (auto p : sn[i]) {
      for (int k = l; k >= 0; --k)
        g[k + z[p]] |= g[k];
      l += z[p];
    }
    int64_t t = 0;
    l /= 2;
    for (int k = 0; k <= l; ++k)
      if (g[k])
        t = max(t, int64_t(k) * (z[i] - k - 1));
    ans += t;
    TLN(TV(i); TV(t); TV(ans));
    z[pa[i]] += z[i];
    sn[pa[i]].emplace_back(i);
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
