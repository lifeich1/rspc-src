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

const int N = 201001;
int ka[64][N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  int64_t K;
  cin >> n >> K;
  vector<int> a = {0}, b;
  a.reserve(n + 1);
  b.reserve(n);
  copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
  copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(b));
  vector<Cm> tb(n + 1, 0), tb2(n + 1), ans(n + 1, Cm{0}), t1(n + 1);
  copy(b.begin(), b.end(), tb.begin() + 1);

  copy(a.begin(), a.end(), ka[0]);
  for (int64_t k = 2, p = 1; k <= K; k <<= 1, ++p) {
    for (int i = 1; i <= n; ++i)
      ka[p][i] = a[a[i]];
    copy_n(ka[p] + 1, n, a.begin() + 1);
  }
  auto jp = [&](auto &v, auto &j) {
    fill(t1.begin(), t1.end(), 0);
    for (int i = 1; i <= n; ++i) {
      t1[j[i]] += v[i];
    }
    copy(t1.begin(), t1.end(), v.begin());
  };
  auto ad = [&](auto &v, auto &d) {
    transform(v.begin(), v.end(), d.begin(), v.begin(), plus<Cm>{});
  };
  jp(tb, ka[0]);
  for (int64_t k = 1, p = 0; k <= K; k <<= 1, ++p) {
    if (k & K) {
      jp(ans, ka[p]);
      ad(ans, tb);
    }
    TV(k);
    TA(ans, cerr << _.v << ' ');
    TLN();
    copy(tb.begin(), tb.end(), tb2.begin());
    jp(tb, ka[p]);
    ad(tb, tb2);
  }
  auto rv = Cm{(K) % 998244353}.mul_inv();
  TA(ans, cerr << _.v << ' ');
  TLN();
  for (int i = 1; i <= n; ++i) {
    auto t = ans[i] * rv;
    cout << t.v << ' ';
  }
  cout << endl;
  return 0;
}

// vim: ts=2 sw=2
