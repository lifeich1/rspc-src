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

const int N = 201001;
int l[N], r[N], a[N], b[N], h[N];

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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i] >> a[i] >> b[i];
      h[i] = i;
    }
    sort(h, h + n, [&](int i, int j) {
      return b[i] < b[j] || (b[i] == b[j] && l[i] < l[j]);
    });
    vector<pair<int, int>> m;
    m.emplace_back(l[h[n - 1]], b[h[n - 1]]);
    for (int i = n - 1; i >= 0; --i) {
      if (b[h[i]] >= m.back().first) {
        m.back().first = min(m.back().first, l[h[i]]);
      } else
        m.emplace_back(l[h[i]], b[h[i]]);
    }
    TLN(TA(m, cerr << '(' << _.first << ',' << _.second << ") ";));
    sort(m.begin(), m.end());
    int K;
    cin >> K;
    while (K--) {
      int x;
      cin >> x;
      int p =
          lower_bound(m.begin(), m.end(), make_pair(x + 1, 0)) - m.begin() - 1;
      if (p >= 0) {
        x = max(x, m[p].second);
      }
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
