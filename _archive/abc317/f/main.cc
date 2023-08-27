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
  CalcInMod() : v{0} {}
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
#define TI(HEAD, TAIL, ...)                                                    \
  TRACE(cerr << "[" #HEAD "," #TAIL ") = ";                                    \
        for_each((HEAD), (TAIL), [&](auto _) { __VA_ARGS__; }))
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR) << ' ')
using namespace std;
#define self_todo_placeholder

const int M = 998244353;
typedef A::CalcInMod<998244353> Cm;

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int64_t n;
  int a, b, c;
  cin >> n >> a >> b >> c;
  // icmp, jcmp,  kcmp, r1, r2, r3
  typedef map<tuple<int, int, int, int, int, int>, Cm> F;
  F _f, _g;
  auto f = [&](int c1, int c2, int c3, int i, int j, int k) -> Cm & {
    return _f[make_tuple(c1, c2, c3, i, j, k)];
  };
  auto rf = [&](int c1, int c2, int c3, int i, int j, int k) -> Cm {
    auto K = make_tuple(c1, c2, c3, i, j, k);
    if (_f.count(K) == 0)
      return 0;
    return _f[K];
  };
  auto ad = [&](int c1, int c2, int c3, int i, int j, int k, Cm const &v) {
    auto &T = f(c1, c2, c3, i, j, k);
    TLN(cerr << "    " << c1 << ' ' << c2 << ' ' << c3 << ',' << i << ' ' << j
             << ' ' << k << "+=" << v.v << ((i | j | k) == 0 ? "  !! " : " ")
             << T.v << ' ';
        TV(_f.size()));
    T += v;
  };
  f(0, 0, 0, 0, 0, 0) = 1;
  Cm ans = 0;
  vector<int> w;
  for (auto t = n; t > 0; t >>= 1)
    w.emplace_back(t & 1);
  reverse(w.begin(), w.end());
  for (auto bt : w) {
    _g.swap(_f);
    _f.clear();
    TLN(static int tt = 0; cerr << tt++ << ':' << bt);
    TLN(TV(_f.size()); TV(rf(-1, -1, -1, 0, 0, 0).v));
    for (auto const &[K, v] : _g) {
      auto nxcmp = [](int c0, int b, int d) {
        if (c0 != 0)
          return c0;
        if (b == d)
          return 0;
        return b > d ? -1 : 1;
      };
      auto nxr = [](int r0, int d, int m) { return (r0 + r0 + d) % m; };
      auto ta = [&](auto const &K, Cm v, int d0, int d1, int d2) {
        auto const &[c0, c1, c2, r0, r1, r2] = K;
        ad(nxcmp(c0, bt, d0), nxcmp(c1, bt, d1), nxcmp(c2, bt, d2),
           nxr(r0, d0, a), nxr(r1, d1, b), nxr(r2, d2, c), v);
      };
      TLN(auto const &[c0, c1, c2, r0, r1, r2] = K;
          cerr << "  " << c0 << ' ' << c1 << ' ' << c2 << ',' << r0 << ' ' << r1
               << ' ' << r2 << '=' << v.v);
      ta(K, v, 0, 0, 0);
      ta(K, v, 1, 0, 1);
      ta(K, v, 1, 1, 0);
      ta(K, v, 0, 1, 1);
    }
  }
  for (int i = -1; i < 1; ++i)
    for (int j = -1; j < 1; ++j)
      for (int k = -1; k < 1; ++k)
        ans += rf(i, j, k, 0, 0, 0);
  auto rd = [](int64_t n, int a, int b) -> Cm {
    a /= __gcd(a, b);
    n /= a * b;
    n %= M;
    TLN(TV(n); TV(a); TV(b));
    return Cm{n};
  };
#if 1
  ans -= rd(n, a, b);
  ans -= rd(n, c, b);
  ans -= rd(n, a, c);
  ans -= 1;
#endif
  cout << ans.v << endl;
  return 0;
}

// vim: ts=2 sw=2
