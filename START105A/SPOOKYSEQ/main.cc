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
const int N = 201001;
int u[N], a[N];
vector<int> e[N];
typedef modint<1000000007> mint;
mint pp[N];

void dfs(int r, map<int, int> &g) {
  g[a[r]]++;
  u[r] = 1;
  for (int y : e[r])
    if (0 == u[y]) {
      dfs(y, g);
    }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  pp[0] = 1;
  for (int i = 1; i < N; ++i)
    pp[i] = pp[i - 1] * i;
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      e[i].clear();
    fill(u, u + n + 1, 0);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      e[x].emplace_back(y);
      e[y].emplace_back(x);
    }
    copy_n(std::istream_iterator<int>(std::cin), n, a + 1);
    mint ans = 1;
    int l = 0;
    for (int i = 1; i <= n; ++i) {
      if (u[i])
        continue;
      map<int, int> g;
      dfs(i, g);
      int nl = l;
      for (auto [k, v] : g) {
        nl += v;
        ans *= pp[v];
      }
      ans *= pp[nl] / pp[l] / pp[nl - l];
      l = nl;
    }
    cout << ans.v << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
