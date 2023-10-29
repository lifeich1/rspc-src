#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
template <class T> int64_t qpow64(int64_t v, T k, int64_t m) {
  int64_t r = 1;
  for (; k > 0; k >>= 1, v = (v * v) % m)
    if (k & 1)
      r = (r * v) % m;
  return r;
}
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
  template <class T> Self qpow(T k) {
    Self r = Self::one();
    if (k <= 0)
      return r;
    Self t = *this;
    for (; k > 0; k >>= 1, t *= t)
      if (k & 1)
        r *= t;
    return r;
  }
  template <class T> Self &pow(T k) {
    *this = this->qpow(k);
    return *this;
  }
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
  bool operator<(Self const &rhs) const { return this->cmp(rhs) < 0; }
  bool operator>(Self const &rhs) const { return this->cmp(rhs) > 0; }
  bool operator==(Self const &rhs) const { return this->cmp(rhs) == 0; }
  bool operator<=(Self const &rhs) const { return this->cmp(rhs) == 0; }
  bool operator>=(Self const &rhs) const { return this->cmp(rhs) >= 0; }
};
template <int64_t M> struct modint_impl {
  typedef modint_impl<M> Self;
  int64_t v;
  modint_impl() : v{0} {}
  template <class T> explicit modint_impl(T t) : v{t} {}
  static Self one() { return Self(1); }
  void add(Self const &rhs) { v = (v + rhs.v) % M; }
  void sub(Self const &rhs) { v = (v + M - rhs.v) % M; }
  void mul(Self const &rhs) { v = (v * rhs.v) % M; }
  void inv() { v = qpow64(v, M - 2, M); }
  int cmp(Self const &rhs) const {
    return v == rhs.v ? 0 : (v < rhs.v ? -1 : 1);
  }
};
template <int64_t M> using modint = number_interface<modint_impl<M>>;
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: qpow64 number_interface modint

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

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  mint ans = 0;
  mint p = 1;
  mint dn = n;
  dn.inv();
  // vector<int> a;
  // a.reserve(n);
  // copy_n(std::istream_iterator<int>(std::cin),n, std::back_inserter(a));
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    mint t = p * dn;
    ans += t * v;
    p += t;
  }
  cout << ans.v << endl;
  return 0;
}

// vim: ts=2 sw=2
