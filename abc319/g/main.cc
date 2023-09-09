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
int sz[N * 40], np[N * 40][2], tt;
int ls[N], lsn, u[N];
vector<int> e[N];
mint f[N];

void pins(int &n, int l, int r, int x) {
  int m = ++tt;
  sz[m] = sz[n] + 1;
  np[m][0] = np[n][0];
  np[m][1] = np[n][1];
  n = m;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  if (x <= mid)
    pins(np[m][0], l, mid, x);
  else
    pins(np[m][1], mid + 1, r, x);
}

bool ptest(int n, int l, int r, int x) {
  if (sz[n] == 0)
    return false;
  if (l == r)
    return true;
  int mid = (l + r) >> 1;
  if (x <= mid)
    return ptest(np[n][0], l, mid, x);
  else
    return ptest(np[n][1], mid + 1, r, x);
}

void tra(int n, int l, int r) {
  if (sz[n] == r - l + 1)
    return;
  if (l == r) {
    ls[lsn++] = l;
    return;
  }

  int mid = (l + r) >> 1;
  tra(np[n][0], l, mid);
  tra(np[n][1], mid + 1, r);
}

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
  qs.emplace_back(1);
  f[1] = 1;
  tt = 1;
  int h = 1;
  pins(h, 1, n, 1);
  qs.reserve(n);
  ps.reserve(n);
  u[1] = 1;

  while (qs.size() && u[n] == 0) {
    ps.clear();
    ps.swap(qs);
    for (auto x : ps) {
      int _h = h, _tt = tt;
      for (auto y : e[x]) {
        if (ptest(h, 1, n, y))
          continue;
        pins(h, 1, n, y);
      }
      lsn = 0;
      tra(h, 1, n);
      h = _h;
      tt = _tt;
      for (int i = 0; i < lsn; ++i) {
        int y = ls[i];
        f[y] += f[x];
        if (u[y] == 0) {
          qs.emplace_back(y);
          u[y] = 1;
        }
      }
    }
    for (auto x : qs) {
      pins(h, 1, n, x);
    }
  }
  if (qs.size())
    cout << f[n].v << endl;
  else
    cout << "-1\n";
  return 0;
}

// vim: ts=2 sw=2
