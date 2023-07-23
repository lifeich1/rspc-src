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

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  vector<int> a, ans;
  vector<pair<int, int>> h;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    a.resize(n);
    ans.resize(n);
    copy_n(std::istream_iterator<int>(std::cin), n, a.begin());
    h.clear();
    h.reserve(n);
    for (int i = 0; i < n; ++i)
      h.emplace_back(a[i], i);
    sort(h.begin(), h.end());
    bool ok = true;
    for (int i = n, l = 0, r = n - 1, pn = 0; i > 0; --i) {
      int pa = i + pn, na = pn;
      if (h[l].first == na) {
        if (h[r].first >= pa) {
          ok = false;
          break;
        }
        TLN(cerr << h[l].second << ' ' << l << ' ' << -i);
        ans[h[l].second] = -i;
        ++l;
      } else {
        if (h[r].first != pa || h[l].first < na) {
          ok = false;
          break;
        }
        TLN(cerr << h[r].second << ' ' << r << ' ' << i);
        ans[h[r].second] = i;
        ++pn, --r;
      }
    }
    if (ok) {
      cout << "YES\n";
      copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
      cout << endl;
    } else
      cout << "NO\n";
  }
  return 0;
}

// vim: ts=2 sw=2
