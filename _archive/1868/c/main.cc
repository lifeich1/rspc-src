#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
template <typename Base> struct number_interface : public Base {
  typedef number_interface<Base> Self;
  template <typename... Args>
  number_interface(Args... args) : Base(std::forward<Args>(args)...) {}
  Self get_inv() const {
    Self r = *this;
    r.inv();
    return r;
  }
  void div(Self const &rhs) { this->mul(rhs.get_inv()); }
  Self &operator+=(Self const &other) {
    this->add(other);
    return *this;
  }
  Self &operator*=(Self const &other) {
    this->mul(other);
    return *this;
  }
  Self &operator/=(Self const &other) {
    this->div(other);
    return *this;
  }
  Self &operator-=(Self const &other) {
    this->sub(other);
    return *this;
  }
  Self operator+(Self const &other) const {
    Self r{*this};
    r += other;
    return r;
  }
  Self operator-(Self const &other) const {
    Self r{*this};
    r -= other;
    return r;
  }
  Self operator*(Self const &other) const {
    Self r{*this};
    r *= other;
    return r;
  }
  Self operator/(Self const &other) const {
    Self r{*this};
    r /= other;
    return r;
  }
  template <class T> Self get_pow(T k) {
    Self r{*this};
    r.pow(k);
    return r;
  }
  bool operator<(Self const &rhs) const { return this->cmp(rhs) < 0; }
  bool operator>(Self const &rhs) const { return this->cmp(rhs) > 0; }
  bool operator==(Self const &rhs) const { return this->cmp(rhs) == 0; }
  bool operator<=(Self const &rhs) const { return this->cmp(rhs) == 0; }
  bool operator>=(Self const &rhs) const { return this->cmp(rhs) >= 0; }
};
template <class T> int64_t qpow64(int64_t v, T k, int64_t m) {
  int64_t r = 1;
  for (; k > 0; k >>= 1, v = (v * v) % m)
    if (k & 1)
      r = (r * v) % m;
  return r;
}
template <int64_t M> struct modint_impl {
  typedef modint_impl<M> Self;
  int64_t v;
  modint_impl() : v{0} {}
  template <class T> explicit modint_impl(T t) : v{t} {}
  void add(Self const &rhs) { v = (v + rhs.v) % M; }
  void sub(Self const &rhs) { v = (v + M - rhs.v) % M; }
  void mul(Self const &rhs) { v = (v * rhs.v) % M; }
  void inv() { v = qpow64(v, M - 2, M); }
  template <class T> void pow(T k) { v = qpow64(v, k, M); }
  int cmp(Self const &rhs) const {
    return v == rhs.v ? 0 : (v < rhs.v ? -1 : 1);
  }
};
template <int64_t M> using modint = number_interface<modint_impl<M>>;
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: number_interface qpow64 modint

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

typedef modint<998244353> mint;

map<pair<int64_t, int>, mint> _f, _g;

bool used(int64_t x, int y) { return _f.count(make_pair(x, y)) != 0; }
mint &f(int64_t x, int y) { return _f[make_pair(x, y)]; }

int64_t gn;
mint fca(int64_t x, int l) {
  if (x > gn)
    return 0;
  if (1 == l)
    return 1;
  auto it = _f.find({x, l});
  if (it != _f.end())
    return it->second;
  mint &r = _f[make_pair(x, l)];
  r = 0;
  int64_t t = 1;
  t <<= 64 - __builtin_clzll(x);
  mint k0 = x + x + 1 - t;
  k0 *= 1;
  r += k0 * fca(t, l - 1);
  r += fca(x + x + 1, l - 1);
  return r;
}

mint gca(int64_t x, int l) {
#error TODO
  return 0;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  vector<pair<int64_t, int>> qq;
  qq.resize(tt);
  set<int> sm;
  map<int, vector<mint>> mu;
  for (int i = 0; i < tt; ++i) {
    auto &[n, m] = qq[i];
    cin >> n >> m;
    sm.emplace(m);
    mu[m].emplace_back(0);
  }
  int mm = *sm.rbegin();
  vector<mint> tk(mm + 1, 1);
  for (int l = 1; l < 64; ++l) {
    mint rh = 0;
    for (int i = 1; i <= mm; ++i) {
      if (sm.find(i) != sm.end())
        mu[i].emplace_back(mint(i).get_pow(l + 1) - rh);
      tk[i] *= i;
      rh += tk[i];
    }
  }
  for (auto [n, m] : qq) {
    _f.clear();
    _g.clear();
    auto t0 = n;
    mint ans = 0;
    gn = n;
    for (int i = 1; t0 > 0; t0 >>= 1, ++i) {
      int64_t t1 = t0;
      while (__builtin_popcountll(t1) > 1)
        t1 -= t1 & (-t1);
      mint k0 = t0 - t1;
      k0 *= 1;
      for (int j = 1; j <= i + i - 1; ++j) {
        ans += gca(t0, j) * mu[m][j];
        ans += gca(t1, j) * mu[m][j] * k0;
        TLN(TV(i); TV(j); TV(ans.v));
      }
    }
#if defined(RSPC_TRACE_HINT)
    for (auto [k, v] : _f) {
      auto [x, l] = k;
      TLN(TV(x); TV(l); TV(v.v));
    }
#endif
    cout << ans.v << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
