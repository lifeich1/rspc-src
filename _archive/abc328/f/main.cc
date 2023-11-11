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
int fa[N], sz[N];
int64_t da[N];

int zr(int r) {
  if (fa[r] == r)
    return r;
  int t = zr(fa[r]);
  da[r] += da[fa[r]];
  return fa[r] = t;
}

// a[x]-a[y]=d
void uni(int x, int y, int d) {
  int bx = zr(x), by = zr(y);
  if (sz[bx] < sz[by]) {
    swap(bx, by);
    swap(x, y);
    d = -d;
  }
  sz[bx] += sz[by];
  fa[by] = bx;
  da[by] = d - da[y] + da[x];
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, Q;
  cin >> n >> Q;
  for (int i = 0; i <= n; ++i)
    fa[i] = i;
  for (int tt = 1; tt <= Q; ++tt) {
    int l, r, d;
    cin >> l >> r >> d;
    if (zr(l) != zr(r)) {
      uni(l, r, d);
      cout << tt << ' ';
    } else if (d == da[r] - da[l]) {
      cout << tt << ' ';
    }
  }
  cout << endl;
  return 0;
}

// vim: ts=2 sw=2
