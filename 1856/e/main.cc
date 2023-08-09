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
const int N = 1001001;
vector<int> sn[N];
int pa[N], z[N];
uint64_t g[N / 60];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  copy_n(std::istream_iterator<int>(std::cin), n - 1, pa + 2);
  int64_t ans = 0;
  for (int i = n; i > 0; --i) {
    int r = (z[i] >> 6) + 1;
    int lm = z[i] >> 1;
    z[i]++;
    for (auto p : sn[i])
      if (z[p] >= lm) {
        int64_t t = z[p];
        t *= z[i] - 1 - t;
        ans += t;
        lm = -1;
        z[pa[i]] += z[i];
        sn[pa[i]].emplace_back(i);
        break;
      }
    if (lm < 0)
      continue;
    fill(g, g + r, 0);
    g[0] = 1;
    map<int, int> c;
    for (auto p : sn[i])
      c[z[p]]++;
    for (auto &[k, v] : c) {
      if (v > 2) {
        int t = (v - 1) / 2;
        v -= t + t;
        c[k + k] += t;
      }
    }

    int l = 0;
    for (auto [k, v] : c) {
      for (int _i = 0; _i < v; ++_i) {
        l += k;
        int nl = ((l - 1) >> 6) + 1;
        for (int p = nl; p >= 0; --p) {
          int t = p - (k >> 6);
          if (t < 0)
            break;
          auto t1 = g[t];
          t1 <<= k & 63;
          g[p] |= t1;
          if ((k & 63) > 0 && t > 0) {
            t1 = g[t - 1];
            t1 >>= 64 - (k & 63);
            g[p] |= t1;
          }
        }
      }
    }
    auto chp = [&](int i) { return (g[i >> 6] >> (i & 63)) & 1; };
    int bs = -1;
    for (l = (z[i] - 1) / 2; (l & 63) != 0; --l)
      if (chp(l)) {
        bs = l;
        break;
      }
    if (chp(l))
      bs = l;
    if (bs < 0) {
      for (int p = (l >> 6) - 1; p >= 0 && g[p] == 0; --p)
        l -= 64;
      for (; l >= 0; --l)
        if (chp(l)) {
          bs = l;
          break;
        }
    }

    int64_t t = bs;
    t *= z[i] - bs - 1;
    ans += t;
    TLN(TV(i); TV(bs); TV(t); TV(ans); TV(g[0]); cerr << " 0x" << hex << g[0];
        TA(c, auto [k, v] = _; cerr << '(' << k << ',' << v << ") "));

    z[pa[i]] += z[i];
    sn[pa[i]].emplace_back(i);
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
