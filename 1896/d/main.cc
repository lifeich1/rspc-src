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

const int N = 101001;
int a[N], s[N];

void ta_a(int n, int x, int v) {
  while (x <= n) {
    s[x] += v;
    x += x & (-x);
  }
}

pair<int, int> ta_lb(int n, int T) {
  if (a[1] > T)
    return {0, 0};
  int k = 0, r = 0, x = 0;
  for (; (1 << k) <= n && s[1 << k] <= T; ++k)
    ;
  --k;
  x = 1 << k;
  r += s[x];
  for (--k; k >= 0; --k)
    if (x + (1 << k) <= n && r + s[x + (1 << k)] <= T) {
      x += 1 << k;
      r += s[x];
    }
  return {r, x};
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
    int n, Q;
    cin >> n >> Q;
    copy_n(std::istream_iterator<int>(std::cin), n, a + 1);
    fill(s, s + n + 1, 0);
    set<int> pos1;
    for (int i = 1; i <= n; ++i) {
      ta_a(n, i, a[i]);
      if (1 == a[i])
        pos1.emplace(i);
    }
    while (Q--) {
      int op;
      cin >> op;
      if (1 == op) {
        int S;
        cin >> S;
        auto [ts, x] = ta_lb(n, S);
        if (ts == S) {
          cout << "YES\n";
          continue;
        }
        if (n == x) {
          cout << "NO\n";
          continue;
        }
        int l = n - x;
        if (pos1.size() && (*pos1.begin() <= l || *pos1.rbegin() > x)) {
          cout << "YES\n";
        } else
          cout << "NO\n";
      } else {
        int i, v;
        cin >> i >> v;
        ta_a(n, i, -a[i]);
        if (1 == a[i])
          pos1.erase(pos1.find(i));
        a[i] = v;
        ta_a(n, i, a[i]);
        if (1 == a[i])
          pos1.emplace(i);
      }
    }
  }
  return 0;
}

// vim: ts=2 sw=2
