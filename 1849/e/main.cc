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
int a[N];
int mx[N], mi[N], s[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  copy_n(std::istream_iterator<int>(std::cin), n, a);
  int p1 = 0, p2 = 0;
  int64_t ans = 0, ns = 0;
  set<int> ps;
  for (int i = 0; i < n; ++i) {
    while (p2 > 0 && a[mi[p2 - 1]] > a[i]) {
      int t = mi[--p2];
      auto it = ps.find(t + t + 1);
      if (it != ps.begin()) {
        --it;
        ns -= t - (*it >> 1);
        ++it;
      } else
        ns -= t + 1;
      ps.erase(it);
    }
    while (p1 > 0 && a[mx[p1 - 1]] < a[i]) {
      int t = mx[--p1];
      auto it = ps.find(t + t);
      ++it;
      if (it != ps.end() && (*it & 1) == 1) {
        ns -= (*it >> 1) - t;
        auto nx = it;
        auto z = *it >> 1;
        --nx;
        if (nx != ps.begin()) {
          --nx;
          ns += z - (*nx >> 1);
        } else
          ns += z + 1;
      }
      --it;
      ps.erase(it);
    }
    mx[p1++] = i;
    mi[p2++] = i;
    ans += ns;

    ps.insert(i + i);
    ps.insert(i + i + 1);
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
