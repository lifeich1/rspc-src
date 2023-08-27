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

const int N = 201001;
int a[N];
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
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a[i] = x;
      m[x]++;
      while (x > 0) {
        x -= x & (-x);
        if (x > 0)
          m[x]++;
      }
    }
    Cm ans = n;
    ans *= n;
    for (int i = 0; i < n; ++i) {
      int x = a[i];
      while (x > 0) {
        ans += m[x];
        x -= x & (-x);
      }
      TV(ans.v);
      for (int k = 2; k <= a[i]; k <<= 1) {
        ans += m[k / 2];
      }
      TLN(TV(i); TV(ans.v); TV(a[i]));
    }
    Cm rn = Cm{n}.mul_inv();
    TLN(TV(ans.v));
    ans *= rn;
    ans *= rn;
    cout << ans.v << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
