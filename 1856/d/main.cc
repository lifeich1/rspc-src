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

const int N = 2020;
int A[N], an, cn;

int q(int l, int r) {
  int rc = 0;
#if defined(RSPC_TRACE_HINT)
  cn += (r - l) * (r - l);
  if (cn > 5 * an * an) {
    cout << "OF\n";
    exit(1);
  }
  for (int i = l; i < r; ++i)
    for (int j = i + 1; j <= r; ++j)
      if (A[i] > A[j])
        ++rc;
#else
  cout << "? " << l << ' ' << r << endl << flush;
  cin >> rc;
#endif
  return rc;
}

void ans(int i) {
#if defined(RSPC_TRACE_HINT)
  if (A[i] != an) {
    cout << i << " WA\n";
    exit(1);
  }
  cout << "OK\n";
#else
  cout << "! " << i << endl << flush;
#endif
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
    int n;
    cin >> n;
#if defined(RSPC_TRACE_HINT)
    an = n;
    copy_n(std::istream_iterator<int>(std::cin), n, A + 1);
    cn = 0;
#endif
    set<int> p;
    for (int i = 1, l = 0; i < n; ++i) {
      int r = q(i, i + 1);
      if (r) {
        if (l != r)
          p.emplace(i);
      } else {
        if (i == n - 1)
          p.emplace(n);
      }
      l = r;
    }
    while (p.size() > 1) {
      int t = n, l, r;
      for (auto it = p.begin(); it != p.end();) {
        int tl = *it;
        if (++it != p.end()) {
          int tr = *it;
          if (tr - tl < t) {
            t = tr - tl;
            l = tl, r = tr;
          }
        }
      }
      int t1 = q(l + 1, r);
      int t2 = q(l, r);
      if (t1 + r - l == t2)
        p.erase(p.find(r));
      else
        p.erase(p.find(l));
    }
    ans(*p.begin());
  }
  return 0;
}

// vim: ts=2 sw=2
