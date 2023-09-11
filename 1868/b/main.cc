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
      TLN(TV(tt); TV(s); TV(n));
      cout << "No\n";
      continue;
    }
    map<int, int> c;
    s /= n;
    bool ok = true;
    map<int, int> e, ei, eo;
    for (int i = 0; i < n; ++i) {
      auto t = abs(a[i] - s);
      if (0 == t)
        continue;
      if (__builtin_popcountll(t) == 1) {
        int x = 63 - __builtin_clzll(t);
        if (a[i] > s)
          e[x]++, eo[x]++;
        else
          e[x]--, ei[x]++;
        continue;
      }
      auto v = t & (-t);
      auto u = t + v;
      if (__builtin_popcountll(u) != 1) {
        ok = false;
        TLN(TV(tt); TV(i); TV(u); TV(v));
        break;
      }
      int _u = 63 - __builtin_clzll(u);
      int _v = 63 - __builtin_clzll(v);
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
    for (int i = 0; i < 60; ++i) {
      auto t = c[i] + e[i];
      if (t == 0) {
        c[i] = 0;
        continue;
      }
      int el = 0;
      if (t > 0)
        el = eo[i];
      else
        el = ei[i];
      TLN(TV(tt); TV(i); TV(t); TV(e[i]));
      if (abs(t) > el * 2 || abs(t) % 2 != 0) {
        ok = false;
        break;
      }
      c[i] = 0;
      c[i + 1] += t / 2;
    }
    for (auto [k, v] : c) {
      if (v != 0) {
        TLN(TV(k); TV(v));
        ok = false;
      }
    }
    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}

// vim: ts=2 sw=2
