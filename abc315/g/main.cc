#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
template <typename T = int64_t> std::tuple<T, T, T> ext_gcd(T a, T b) {
  T ia[] = {1, 0, 0, 0}, ib[] = {0, 1, 0, 0}, a1, b1, d;
  do {
    if (0 == b)
      return {a, ia[0], ib[0]};
    d = a / b;
    a1 = b, b1 = a - d * b;
    ia[2] = ia[1], ib[2] = ib[1];
    ia[3] = ia[0] - d * ia[1], ib[3] = ib[0] - d * ib[1];
    if (0 == b1)
      return {a1, ia[2], ib[2]};
    d = a1 / b1;
    a = b1, b = a1 - d * b1;
    ia[0] = ia[3], ib[0] = ib[3];
    ia[1] = ia[2] - d * ia[3], ib[1] = ib[2] - d * ib[3];
  } while (1);
  return {a, 1, 0};
}
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: ext_gcd

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

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int64_t n, a, b, c, x, ans = 0;
  cin >> n >> a >> b >> c >> x;
  auto [g, jg, kg] = ext_gcd(b, c);
  b /= g, c /= g;
  TLN(TV(g); TV(b); TV(c); TV(jg); TV(kg));
  for (int64_t i = 1; i <= n; ++i) {
    auto tar = x - i * a;
    if (tar % g != 0)
      continue;
    tar /= g;
    if (tar < b + c) {
      TLN(TV(tar); TV(i));
      break;
    }
    if (tar > (b + c) * n)
      continue;
    auto t = tar % b;
    auto j0 = jg * t;
    auto k0 = kg * t;
    j0 += (tar - j0 * b - k0 * c) / b;
    int64_t l, r;

    auto po = [](int64_t x, int64_t m) -> int64_t {
      if (x > 0)
        return (x - 1) / m + 1;
      if (0 == x)
        return 0;
      return -(-x / m);
    };

    l = max(po(1 - j0, c), po(k0 - n, b));
    r = min(po(n + 1 - j0, c) - 1, po(k0, b) - 1);

    // TLN(TV(i); TV(l); TV(r); TV(j0); TV(k0); TV(tar); TV(po(1 - j0, c));
    // TV(po(k0 - n, b)));
    if (l <= r) {
      ans += r - l + 1;
    }
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
