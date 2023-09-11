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
#define TI(HEAD, TAIL, ...)                                                    \
  TRACE(cerr << "[" #HEAD "," #TAIL ") = ";                                    \
        for_each((HEAD), (TAIL), [&](auto _) { __VA_ARGS__; }))
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR) << ' ')
using namespace std;
#define self_todo_placeholder

const int N = 201001;
int64_t a[N];

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
    int n;
    cin >> n;
    copy_n(std::istream_iterator<int64_t>(std::cin), n, a);
    auto s = accumulate(a, a + n, int64_t(0));
    if (s % n != 0) {
      cout << "No\n";
      continue;
    }
    map<int, int> c;
    s /= n;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      auto t = abs(a[i] - s);
      if (0 == t)
        continue;
      auto v = t & (-t);
      auto u = t + v;
      if (__builtin_popcountll(u) != 1) {
        ok = false;
        break;
      }
      int _u = __builtin_clzll(u);
      int _v = __builtin_clzll(v);
      if (a[i] > s) {
        c[_u]++;
        c[_v]--;
      } else {
        c[_u]--;
        c[_v]++;
      }
    }
    if (!ok) {
      cout << "No\n";
      continue;
    }
    for (auto [k, v] : c) {
      if (v != 0)
        ok = false;
    }
    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}

// vim: ts=2 sw=2
