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

int a[99];

optional<vector<int>> search(vector<int> &d, int T) {
  const int n = d.size();
  int l = n / 2;
  unordered_map<int, int> tp;
  for (int i = 0, m = 1 << l; i < m; ++i) {
    int v = T;
    for (int k = 0, t = i; k < l; ++k, t >>= 1)
      if (t & 1)
        v -= d[n - k - 1];
      else
        v += d[n - k - 1];
    tp[v] = i;
  }
  l = n - l;
  for (int i = 0, m = 1 << l; i < m; ++i) {
    int v = 0;
    for (int k = 0, t = i; k < l; ++k, t >>= 1) {
      if (t & 1)
        v += d[k];
      else
        v -= d[k];
    }
    if (tp.count(v) > 0) {
      vector<int> rt;
      for (int k = 0, t = i; k < l; ++k, t >>= 1)
        rt.emplace_back((t & 1) ? 1 : -1);
      int t = tp[v];
      for (int k = n - l - 1; k >= 0; --k)
        rt.emplace_back(((1 << k) & t) ? 1 : -1);
      return rt;
    }
  }
  return nullopt;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, X, Y;
  cin >> n >> X >> Y;
  copy_n(std::istream_iterator<int>(std::cin), n, a);
  vector<int> yd, xd;
  for (int i = 0; i < n; i += 2)
    yd.emplace_back(a[i]);
  for (int i = 1; i < n; i += 2)
    xd.emplace_back(a[i]);
  auto sy = search(yd, Y);
  if (!sy.has_value()) {
    cout << "No\n";
    return 0;
  }
  auto sx = search(xd, X);
  if (!sx.has_value()) {
    cout << "No\n";
    return 0;
  }
  TLN(TA(*sx, cerr << _ << ' '));
  TLN(TA(*sy, cerr << _ << ' '));
  vector<pair<int, int>> rd;
  for (int i = 0; i < n; ++i) {
    if (sy->size() > i) {
      rd.emplace_back(0, sy->at(i));
    }
    if (sx->size() > i) {
      rd.emplace_back(sx->at(i), 0);
    }
  }
  int dx = 1, dy = 0;
  cout << "Yes\n";
  for (auto [x, y] : rd) {
    int t = -dy * x + dx * y;
    cout << (t > 0 ? 'L' : 'R');
    dx = x, dy = y;
  }
  cout << endl;
  return 0;
}

// vim: ts=2 sw=2
