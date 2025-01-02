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

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<int> a;
  vector<int> d(n, 0);
  vector<int64_t> s(n, 0);
  vector<int> pa = {0};
  a.reserve(n);
  pa.reserve(n);
  copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
  copy_n(std::istream_iterator<int>(std::cin), n - 1, std::back_inserter(pa));
  for (auto &p : pa)
    --p;
  for (int i = 1; i < n; ++i) {
    d[i] = d[pa[i]] + 1;
    s[d[i]] += a[i];
  }
  s[0] = a[0];
  int k;
  for (k = n - 1; k >= 0 && s[k] == 0; --k)
    ;
  if (k < 0)
    cout << "0\n";
  else
    cout << (s[k] > 0 ? "+\n" : "-\n");
  return 0;
}
// vim: ts=2 sw=2
