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
#define TI(HEAD, TAIL, ...)                                                    \
  TRACE(cerr << "[" #HEAD "," #TAIL ") = ";                                    \
        for_each((HEAD), (TAIL), [&](auto _) { __VA_ARGS__; }))
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR) << ' ')
using namespace std;
#define self_todo_placeholder

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
  typedef map<tuple<int, int, int>, Cm> F;
  F _f, _g;
  auto f = [&](int i, int j, int k) -> Cm & { return _f[make_tuple(i, j, k)]; };
  f(0, 0, 0) = 1;
  Cm ans = 0;
  int l = 0;
  for (auto t = n; t > 0; t >>= 1, ++l)
    ;
  bool nfr = false;
  while (--l >= 0) {
    auto w = (n >> l) & 1;
    _g.swap(_f);
    _f.clear();
    for (auto const &[K, v] : _g) {
      if (v.v == 0)
        continue;
      auto [ri, rj, rk] = K;
      auto id = ri / a, jd = rj / b, kd = rk / c;
      auto i = ri % a, j = rj % b, k = rk % c;
      auto tw = [](int w, int d0, int d) -> int { // rc: 0n  1eq 2lt 3gt
        if (1 == d0 || (0 == d0 && d != 0)) {     // eq
          if (w > d)
            return 2;
          if (w < d)
            return 3;
          return 1;
        } else
          return d0;
      };
      Cm vv = v;
#if defined(RSPC_TRACE_HINT)
      auto KK = K;
#endif
      auto ta = [&](int d0, int d1, int d2) {
        auto x = (i * 2 + d0) % a + tw(w, id, d0) * a;
        auto y = (j * 2 + d1) % b + tw(w, jd, d1) * b;
        auto z = (k * 2 + d2) % c + tw(w, kd, d2) * c;
#if 1
        TLN(auto [ri, rj, rk] = KK;
            cerr << "::" << ri << ',' << rj << ',' << rk << " => " << x << ','
                 << y << ',' << z << "  +" << vv.v;
            cerr << "  ||" << i << ' ' << j << ' ' << k << ' ' << w << " -- "
                 << tw(w, jd, d1) << ' ' << w << jd << d1);
#endif
        f(x, y, z) += vv;
      };
      if (nfr)
        ta(0, 0, 0);
      ta(0, 1, 1);
      ta(1, 0, 1);
      ta(1, 1, 0);
    }
    nfr = true;
#if defined(RSPC_TRACE_HINT)
    for (auto [K, v] : _f) {
      if (v.v == 0)
        continue;
      auto [i, j, k] = K;
      TLN(TV(l); TV(w); cerr << i << ',' << j << ',' << k << '=' << v.v;
          if (i % a == 0 && j % b == 0 && k % c == 0 && i > 0 && j > 0 && k > 0)
              cerr
          << "  !!");
    }
#endif
    int u = l > 0 ? 4 : 3;
    for (int i = 1; i < u; ++i)
      for (int j = 1; j < u; ++j)
        for (int k = 1; k < u; ++k)
          ans += f(i * a, j * b, k * c);
    TLN(TV(ans.v));
  }
  cout << ans.v << endl;
  return 0;
}

// vim: ts=2 sw=2
