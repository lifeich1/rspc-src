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
const int N = 201001;
mint f[N];
vector<int> e[N];
int u[N], nr[N], bu[N], bs[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }

  vector<int> ps, qs;
  ps.reserve(n);
  qs.reserve(n);
  qs.emplace_back(1);
  f[1] = 1;
  nr[0] = 2;
  for (int i = 2; i < n; ++i)
    nr[i] = i + 1;

  while (qs.size() && 0 == u[n]) {
    ps.clear();
    ps.swap(qs);
    mint w = 0;
    const int fl = ps.front();
    for (auto x : ps) {
      w += f[x];
      for (auto y : e[x])
        if (bu[y] == fl)
          ++bs[y];
        else
          bu[y] = fl, bs[y] = 1;
    }
    TLN(TA(ps, cerr << _ << ' '); TV(w.v));
    for (auto h = 0, x = nr[0]; x != 0;)
      if (fl != bu[x] || bs[x] < ps.size()) {
        qs.emplace_back(x);
        f[x] = w;
        u[x] = 1;
        bu[x] = -fl;
        x = nr[h] = nr[x];
      } else
        h = x, x = nr[x];
    for (auto x : ps)
      for (auto y : e[x])
        if (-fl == bu[y]) {
          f[y] -= f[x];
        }
  }

  if (u[n])
    cout << f[n].v << endl;
  else
    cout << "-1\n";
  return 0;
}

// vim: ts=2 sw=2
