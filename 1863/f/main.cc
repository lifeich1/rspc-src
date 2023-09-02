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

const int N = 10100;
int64_t L[N], R[N], a[N];
int La[N], Ra[N];

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
    for (int i = 1; i < n; ++i)
      a[i] ^= a[i - 1];
    fill(L, L + n, 0);
    fill(R, R + n, 0);
    fill(La, La + n, 0);
    fill(Ra, Ra + n, 0);
    auto tb = [](int64_t x) -> int64_t {
      int b = 63 - __builtin_clzll(x);
      int64_t t = 1;
      t <<= b;
      return t;
    };
    if (a[n - 1]) {
      auto t = tb(a[n - 1]);
      L[0] |= t;
      R[n - 1] |= t;
      TLN(TV(t); TV(a[n - 1]));
    } else {
      La[0] = n;
      Ra[n - 1] = n;
    }
    for (int k = n - 1; k > 1; --k) {
      auto x = a[k - 1];
      for (int i = 0, j = k - 1; j < n; ++i, ++j) {
        if ((L[i] & x) || (R[j] & x) || La[i] || Ra[j]) {
          if (x) {
            auto t = tb(x);
            L[i] |= t;
            R[j] |= t;
          } else
            La[i] = Ra[j] = 1;
        }

        x = a[i] ^ a[j + 1];
      }
    }
    for (int i = n - 1; i > 0; --i)
      a[i] ^= a[i - 1];
    for (int i = 0; i < n; ++i) {
      auto x = a[i];
      if ((L[i] & x) || (R[i] & x) || La[i] || Ra[i])
        cout << 1;
      else
        cout << 0;
    }
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
