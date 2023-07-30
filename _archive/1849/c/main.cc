#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

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

struct mint {
  int64_t m;
  int64_t x = 0;
  explicit mint() : m{1000000007} {}
  explicit mint(int64_t m) : m{m} {}
  typedef mint type;
  // explicit mint(type const &other) = default;
  // explicit mint(type &&other) = default;
  // explicit mint(type &other) : m{other.m}, x{other.x} {}
  mint g(int64_t x) const {
    mint r(m);
    r.x = x;
    return r;
  }
  type &operator=(type const &other) = default;
  type mul(type const &rhs) const { return g(x * rhs.x % m); }
  type mul(int rhs) const { return g(x * rhs % m); }
  type add(type const &rhs) const { return g((x + rhs.x) % m); }
  type add(int rhs) const { return g((x + rhs) % m); }
  type sub(type const &rhs) const { return g((x - rhs.x + m) % m); }
  type sub(int rhs) const { return g((x - rhs + m) % m); }
  template <typename T> type operator*(T const &rhs) const { return mul(rhs); }
  template <typename T> type operator+(T const &rhs) const { return add(rhs); }
  template <typename T> type operator-(T const &rhs) const { return sub(rhs); }
  template <typename T> type &operator*=(T const &rhs) {
    *this = mul(rhs);
    return *this;
  }
  template <typename T> type &operator+=(T const &rhs) {
    *this = add(rhs);
    return *this;
  }
  template <typename T> type &operator-=(T const &rhs) {
    *this = sub(rhs);
    return *this;
  }
  bool eq(type const &rhs) const { return x == rhs.x && m == rhs.m; }
  bool operator==(type const &rhs) const { return eq(rhs); }
  bool le(type const &rhs) const { return x < rhs.x; }
  bool operator<(type const &rhs) const { return le(rhs); }
  size_t hash() const { return static_cast<size_t>(x); }
};

struct mint_gp {
  vector<mint> v;
  typedef mint_gp type;
  bool le(type const &rhs) const { return v < rhs.v; }
  bool operator<(type const &rhs) const { return le(rhs); }

  type mul(type const &rhs) const {
    type r;
    r.v.reserve(v.size());
    transform(v.begin(), v.end(), rhs.v.begin(), std::back_inserter(r.v),
              multiplies<mint>{});
    return r;
  }
  type mul(int rhs) const {
    type r;
    r.v.reserve(v.size());
    using namespace std::placeholders;
    transform(v.begin(), v.end(), std::back_inserter(r.v),
              [&](auto &x) { return x * rhs; });
    return r;
  }
  type add(type const &rhs) const {
    type r;
    r.v.reserve(v.size());
    transform(v.begin(), v.end(), rhs.v.begin(), std::back_inserter(r.v),
              plus<mint>{});
    return r;
  }
  type add(int rhs) const {
    type r;
    r.v.reserve(v.size());
    using namespace std::placeholders;
    transform(v.begin(), v.end(), std::back_inserter(r.v),
              [&](auto &x) { return x + rhs; });
    return r;
  }
  type sub(type const &rhs) const {
    type r;
    r.v.reserve(v.size());
    using namespace std::placeholders;
    transform(v.begin(), v.end(), rhs.v.begin(), std::back_inserter(r.v),
              minus<mint>{});
    return r;
  }
  type sub(int rhs) const {
    type r;
    r.v.reserve(v.size());
    using namespace std::placeholders;
    transform(v.begin(), v.end(), std::back_inserter(r.v),
              [&](auto &x) { return x - rhs; });
    return r;
  }
  template <typename T> type operator*(T const &rhs) const { return mul(rhs); }
  template <typename T> type operator+(T const &rhs) const { return add(rhs); }
  template <typename T> type operator-(T const &rhs) const { return sub(rhs); }
  template <typename T> type &operator*=(T const &rhs) {
    *this = mul(rhs);
    return *this;
  }
  template <typename T> type &operator+=(T const &rhs) {
    *this = add(rhs);
    return *this;
  }
  template <typename T> type &operator-=(T const &rhs) {
    *this = sub(rhs);
    return *this;
  }
};

mint_gp zero() {
  mint_gp r;
  r.v.emplace_back(100000007);
  r.v.emplace_back(998244353);
  r.v.emplace_back(1073741789);
  r.v.emplace_back(536870909);
  return r;
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
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<mint_gp> pf(n + 1, zero()), sf(n + 1, zero()), b2;
    vector<int> s(n + 1, 0);
    set<mint_gp> ss;
    string st;
    cin >> st;
    for (int i = 0; i < n; ++i) {
      int x = st[i] - '0';
      s[i + 1] = s[i] + x;
      pf[i + 1] = (pf[i] * 2) + x;
    }
    mint_gp o = zero() + 1;
    b2.reserve(n + 1);
    b2.emplace_back(o);
    for (int i = n - 1; i >= 0; --i) {
      int x = st[i] - '0';
      sf[i] = sf[i + 1];
      if (x)
        sf[i] += o;
      o *= 2;
      b2.emplace_back(o);
    }
    while (m--) {
      int l, r;
      cin >> l >> r;
      auto t1 = pf[l - 1] * b2[n - l + 1];
      auto t2 = (b2[s[r] - s[l - 1]] - 1) * b2[n - r];
      auto t3 = sf[r];
      auto t = t1 + t2 + t3;
      TLN(TA(t2.v, cerr << _.x << ' '));
      TLN(TA(t.v, cerr << _.x << ' '));
      ss.emplace(t);
    }
    TLN();
    cout << ss.size() << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
