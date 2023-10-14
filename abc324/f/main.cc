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
int pa[N], sz[N];
vector<int> es[N];
int &fa(int r) {
  if (pa[r] == r)
    return pa[r];
  int &p = fa(pa[r]);
  pa[r] = p;
  return p;
}

void uni(int x, int y) {
  x = fa(x), y = fa(y);
  if (sz[x] < sz[y])
    swap(x, y);
  sz[x] += sz[y];
  fa(y) = x;
}

vector<int> u, v, b, c;
vector<double> bc;
int sb = 0, sc = 0;
bool dfs(int r, int ta) {
  if (r == ta)
    return true;
  for (auto e : es[r]) {
    if (dfs(v[e], ta)) {
      TLN(TV(e));
      sb += b[e], sc += c[e];
      return true;
    }
  }
  return false;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  u.reserve(m);
  v.reserve(m);
  b.reserve(m);
  c.reserve(m);
  bc.reserve(m);
  for (int i = 0; i < m; ++i) {
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    u.emplace_back(x);
    v.emplace_back(y);
    b.emplace_back(z);
    c.emplace_back(w);
  }
  vector<int> h(m, 0);
  for (int i = 0; i < m; ++i)
    h[i] = i;
  sort(h.begin(), h.end(), [&](auto l, auto r) {
    int p = b[l] * c[r], q = b[r] * c[l];
    return p > q || (p == q && b[l] > b[r]);
  });
  for (int i = 1; i <= n; ++i)
    pa[i] = i, sz[i] = 1;

  for (auto e : h) {
    int x = fa(u[e]), y = fa(v[e]);
    if (x == y)
      continue;
    es[u[e]].emplace_back(e);
    uni(x, y);
  }
  dfs(1, n);
  double d = sb;
  d /= sc;
  cout << std::fixed << setprecision(20) << d << endl;
  return 0;
}

// vim: ts=2 sw=2
