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
int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  const int m = 1 << 20;
  while (tt--) {
    int n;
    cin >> n;
    copy_n(std::istream_iterator<int>(std::cin), n, a);
    int l = 0, r = n - 1;
    while (1 == a[l] && l < n - 1)
      ++l;
    while (1 == a[r] && r > l)
      --r;
    int64_t t = 1, ts = 0;
    for (int i = l; i <= r; ++i) {
      ts += a[i];
      t *= a[i];
      if (t > m)
        t = m;
    }
    if (t >= m || l == r) {
      ++l, ++r;
      cout << l << ' ' << r << endl;
      continue;
    }
    if (ts >= t) {
      cout << "1 1\n";
      continue;
    }
    for (bool go = true; go;) {
      go = false;
      int s = a[l], j = l;
      while (a[j + 1] == 1 && j < r)
        s++, j++;
      if (s > (t - t / a[l])) {
        t /= a[l];
        l = j;
        go = true;
      }
    }
    for (bool go = true; go;) {
      int s = a[r], j = r;
      go = false;
      while (a[j - 1] == 1 && j > l)
        --j, ++s;
      if (s > (t - t / a[r])) {
        t /= a[r];
        r = j;
        go = true;
      }
    }
    ++l, ++r;
    cout << l << ' ' << r << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
