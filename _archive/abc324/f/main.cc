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

vector<int> u, v, b, c;
vector<int> es[N];
int g[N];
double f[N];
int n, m;

bool check(double K) {
  f[1] = 0;
  g[1] = 1;
  fill(g + 2, g + n + 1, 0);
  for (int i = 1; i < n; ++i) {
    if (0 == g[i])
      continue;
    for (auto e : es[i]) {
      double t = f[i] + b[e] - K * c[e];
      int y = v[e];
      if (0 == g[y] || f[y] < t) {
        f[y] = t;
        g[y] = 1;
      }
    }
  }
  return g[n] && f[n] >= 0;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  cin >> n >> m;
  u.reserve(m);
  v.reserve(m);
  b.reserve(m);
  c.reserve(m);
  for (int i = 0; i < m; ++i) {
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    u.emplace_back(x);
    v.emplace_back(y);
    b.emplace_back(z);
    c.emplace_back(w);
    es[x].emplace_back(i);
  }
  double l = 0, r = 1e4;
  for (int _it = 0; _it < 100; ++_it) {
    auto t = (l + r) / 2;
    if (check(t))
      l = t;
    else
      r = t;
  }
  cout << fixed << setprecision(16) << l << endl;
  return 0;
}

// vim: ts=2 sw=2
