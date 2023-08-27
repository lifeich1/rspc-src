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
const int M = 40000;
int ip[M];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  vector<int> ps;
  map<int, map<int, int>> pm;
  for (int i = 2; i < M; ++i)
    if (0 == ip[i]) {
      ps.emplace_back(i);
      if (i * i < M) {
        for (int t = i + i; t < M; t += i)
          ip[t] = 1;
      }
      int k = i - 1;
      for (int p : ps) {
        if (p > k)
          break;
        while (k % p == 0) {
          pm[i][p]++;
          k /= p;
        }
      }
    }

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    map<int, int> c;
    map<int, int> b;
    vector<int> a = {n};
    int t = n;
    for (int p : ps) {
      while (t % p == 0) {
        ++b[p];
        t /= p;
      }
      if (t < p)
        break;
    }
    if (t > 1)
      b[t]++;
    while (n > 1) {
      int d = n;
      for (auto it = b.rbegin(); it != b.rend(); ++it) {
        int td = it->first;
        int t = n / td;
        if (c[t] == 2)
          continue;
        d = td;
        break;
      }
      int t = n / d;
      if (++c[t] > 2) {
        TLN(TV(t); TA(a, cerr << _ << ' '));
        exit(1);
      }
      if (--b[d] == 0) {
        b.erase(b.find(d));
      }
      if (pm.find(d) != pm.end()) {
        for (auto [k, v] : pm[d]) {
          b[k] += v;
        }
      } else {
        --d;
        for (auto p : ps) {
          if (p > d)
            break;
          while (d % p == 0) {
            d /= p;
            b[p]++;
          }
        }
        if (d > 1)
          b[d]++;
      }
      n -= t;
      a.emplace_back(n);
    }
    cout << a.size() << endl;
    copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
