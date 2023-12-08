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
int bl[N], btt = 1;

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m, L;
  cin >> n >> m >> L;
  vector<int> a, b;
  vector<pair<int, int>> c(L);
  a.reserve(n);
  b.reserve(m);
  copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
  copy_n(std::istream_iterator<int>(std::cin), m, std::back_inserter(b));

  for (int i = 0; i < L; ++i) {
    cin >> c[i].first >> c[i].second;
    c[i].first--;
    c[i].second--;
  }
  sort(c.begin(), c.end());
  set<pair<int, int>> h;
  vector<pair<int, int>> s;
  s.reserve(m);
  for (int i = 0; i < m; ++i)
    h.emplace(b[i], i);
  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    ++btt;
    while (j < L && c[j].first == i)
      bl[c[j++].second] = btt;
    while (h.size() && btt == bl[h.rbegin()->second]) {
      auto it = h.end();
      --it;
      s.emplace_back(*it);
      h.erase(it);
    }
    if (h.size()) {
      ans = max(a[i] + h.rbegin()->first, ans);
    }
    for (const auto &p : s) {
      h.emplace(p);
    }
    s.clear();
  }
  cout << ans << endl;

  return 0;
}

// vim: ts=2 sw=2
