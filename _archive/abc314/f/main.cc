#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
namespace A {
template <class T> inline constexpr T qpow_in_mod(T base, T ind, T m) {
  T res = 1;
  for (T bi = base; ind > 0; ind >>= 1, bi = (bi * bi) % m)
    if (ind & 1)
      res = (res * bi) % m;
  return res;
}
template <int64_t M, class T = int64_t> class CalcInMod {
public:
  typedef T data_t;
  T v;
  CalcInMod() {}
  CalcInMod(int v) : v{static_cast<T>(v)} {}
  CalcInMod(T v) : v{v} {}
  int as_i() { return static_cast<int>(v); }
  using type = CalcInMod<M, T>;
  inline static T add(T a, T b) { return (a + b) % M; }
  inline static T sub(T a, T b) { return (a - b + M) % M; }
  inline static T mul(T a, T b) { return (a * b) % M; }
  inline static T qpow(T base, T ind) {
    T res = 1;
    for (T bi = base; ind > 0; ind >>= 1, bi = mul(bi, bi))
      if (ind & 1)
        res = mul(res, bi);
    return res;
  }
  inline type operator+(type const &a) const { return {(a.v + v) % M}; }
  inline type operator-(type const &a) const { return {(v - a.v + M) % M}; }
  inline type operator*(type const &a) const { return {(a.v * v) % M}; }
  inline type &operator+=(type const &a) {
    *this = *this + a;
    return *this;
  }
  inline type &operator-=(type const &a) {
    *this = *this - a;
    return *this;
  }
  inline type &operator*=(type const &a) {
    *this = *this * a;
    return *this;
  }
  inline type mul_inv() const { return {qpow(M - 2)}; }
  inline type qpow(T ind) const { return {qpow(v, ind)}; }
  inline bool operator==(type const &a) const { return v == a.v; }
  inline bool operator<(type const &a) const { return v < a.v; }
};
} // namespace A
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: calc_in_mod

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

typedef A::CalcInMod<998244353> Cm;
const int N = 401001;
int fa[N], sz[N], e[N][2];
Cm ans[N];

int &pa(int i) {
  if (0 == fa[i]) {
    fa[i] = i;
  }
  if (i == fa[i])
    return fa[i];
  auto &r = pa(fa[i]);
  fa[i] = r;
  return r;
}

void dfs(int r, Cm a) {
  ans[r] = a;
  if (e[r][0]) {
    Cm d = Cm{sz[r]}.mul_inv();
    dfs(e[r][0], a + (d * sz[e[r][0]]));
    dfs(e[r][1], a + (d * sz[e[r][1]]));
  }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  fill(sz + 1, sz + n + 1, 1);
  for (int i = 1; i < n; ++i) {
    int p, q;
    cin >> p >> q;
    p = pa(p);
    q = pa(q);
    sz[n + i] = sz[p] + sz[q];
    fa[q] = n + i;
    fa[p] = n + i;
    e[n + i][0] = p;
    e[n + i][1] = q;
  }
  dfs(n + n - 1, 0);
  for (int i = 1; i <= n; ++i)
    cout << ans[i].v << ' ';
  cout << endl;
  return 0;
}

// vim: ts=2 sw=2
