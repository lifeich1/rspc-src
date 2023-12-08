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
  Self operator-() const { // TODO: add to template
    Self r;
    r -= *this;
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
template <std::size_t L, int ResId = 0> struct array_modint_impl {
  typedef array_modint_impl<L> Self;
  typedef int compare_r;
  typedef std::array<int64_t, L> m_type;
  static m_type M;
  std::array<int64_t, L> v;
  array_modint_impl() { std::fill(v.begin(), v.end(), 0); }
  template <class T> explicit array_modint_impl(T t) {
    std::fill(v.begin(), v.end(), t);
    if (t < 0) {
      for (unsigned i = 0; i < L; ++i) // TODO: add to template
        v[i] += M[i];
    }
  }
  int64_t operator[](const int i) const { return v[i]; }
  static Self one() { return Self(1); }
  int cmp(Self const &rhs) const {
    for (std::size_t i = 0; i < L; ++i)
      if (v[i] != rhs[i])
        return v[i] < rhs[i] ? -1 : 1;
    return 0;
  }
  void add(Self const &rhs) {
    for (std::size_t i = 0; i < L; ++i)
      v[i] = (v[i] + rhs[i]) % M[i];
  }
  void sub(Self const &rhs) {
    for (std::size_t i = 0; i < L; ++i)
      v[i] = (v[i] + M[i] - rhs[i]) % M[i];
  }
  void mul(Self const &rhs) {
    for (std::size_t i = 0; i < L; ++i)
      v[i] = (v[i] * rhs[i]) % M[i];
  }
  void inv() {
    for (std::size_t i = 0; i < L; ++i)
      v[i] = qpow64(v[i], M[i] - 2, M[i]);
  }
};
template <std::size_t L, int ResId = 0>
using amodint = number_interface<array_modint_impl<L, ResId>>;
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: number_interface amodint

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

typedef amodint<4> mint;
// TODO: add to template
#define MINT_M(L, ...)                                                         \
  template <> std::array<int64_t, L> array_modint_impl<L>::M = {__VA_ARGS__}
#define EXMINT_M(L, RID, ...)                                                  \
  template <>                                                                  \
  std::array<int64_t, L> array_modint_impl<L, RID>::M = {__VA_ARGS__}
MINT_M(4, 100000007, 998244353, 1073741789, 536870909);

const int N = 1001001;
mint ls[N], rs[N], dd[N];

int n;

void t_a(mint *a, int x, mint v) {
  for (; x <= n; x += x & (-x))
    a[x] += v;
}
mint t_g(mint *a, int x) {
  mint r;
  for (; x > 0; x -= x & (-x))
    r += a[x];
  return r;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int Q;
  string s;
  cin >> n >> Q >> s;
  dd[0] = 1;
  dd[1].v = {509, 491, 467, 283};
  for (int i = 1; i <= n; ++i) {
    if (i > 1)
      dd[i] = dd[i - 1] * dd[1];
    int t = s[i - 1] - 'a';
    t_a(ls, i, dd[i - 1] * t);
    t = s[n - i] - 'a';
    t_a(rs, i, dd[i - 1] * t);
  }

  while (Q--) {
    int op;
    cin >> op;
    if (1 == op) {
      int x;
      char c;
      cin >> x >> c;
      int t = c - s[x - 1];
      s[x - 1] = c;
      t_a(ls, x, dd[x - 1] * t);
      t_a(rs, n - x + 1, dd[n - x] * t);
    } else {
      int l, r;
      cin >> l >> r;
      auto x = t_g(ls, r);
      x -= t_g(ls, l - 1);
      x *= dd[n - l + 1];
      auto y = t_g(rs, n - l + 1);
      y -= t_g(rs, n - r);
      y *= dd[r];
      cout << (x == y ? "Yes\n" : "No\n");
    }
  }
  return 0;
}

// vim: ts=2 sw=2
