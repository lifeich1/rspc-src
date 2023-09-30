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

int n, K, P;

int se(int *a) {
  int r = 0;
  for (int i = 0; i < K; ++i)
    r = r * (P + 1) + min(a[i], P);
  return r;
}
void de(int x, int *a) {
  for (int i = K - 1; i >= 0; --i, x /= (P + 1))
    a[i] = x % (P + 1);
}

int A[9];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  cin >> n >> K >> P;
  map<int, int64_t> f, g;
  f[0] = 0;
  int tm[9];
  for (int i = 0; i < n; ++i) {
    int C;
    cin >> C;
    copy_n(std::istream_iterator<int>(std::cin), K, A);
    g = f;
    for (auto [k, v] : g) {
      de(k, tm);
      for (int p = 0; p < K; ++p)
        tm[p] += A[p];
      int y = se(tm);
      v += C;
      if (f.count(y) == 0 || f[y] > v)
        f[y] = v;
    }
  }
  fill(tm, tm + K, P);
  int u = se(tm);
  TLN(TV(u); TV(f.count(u)));
  if (f.count(u) == 0)
    cout << "-1\n";
  else
    cout << f[u] << endl;
  ;
  return 0;
}

// vim: ts=2 sw=2
