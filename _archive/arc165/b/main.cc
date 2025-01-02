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
int a[N], b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, K;
  cin >> n >> K;
  copy_n(std::istream_iterator<int>(std::cin), n, a);
  for (int i = 0, l = -1; i < n - 1; ++i) {
    if (a[i] < a[i + 1]) {
      if (i - l >= K - 1) {
        copy_n(a, n, std::ostream_iterator<int>(std::cout, " "));
        cout << endl;
        return 0;
      }
    } else
      l = i;
  }
  for (int i = 0; i < n; ++i)
    b[a[i]] = i;
  int ans = n - K;
  set<int> ss;
  for (int i = n - K; i < n; ++i)
    ss.emplace(a[i]);
  int bi = ans, bv = *ss.begin();
  for (auto it = ss.begin(); *it == a[bi]; bv = *(++it), ++bi)
    ;
  TLN(TV(ans); TV(bi); TV(bv));
  int ti = bi, tv = bv;
  for (int i = ans - 1; i >= 0; --i) {
    auto pt = ss.find(a[i + K]);
    ++pt;
    ss.erase(ss.find(a[i + K]));
    ss.emplace(a[i]);
    if (a[i] != *ss.begin()) {
      ti = i, tv = *ss.begin();
    } else if (a[i + K] == tv) {
      auto it = pt;
      if (it == ss.end()) {
        it = ss.begin();
        ti = i;
      }
      for (; *it == a[ti]; ++ti, ++it)
        ;
      tv = *it;
    }
    TLN(TV(i); TV(ti); TV(tv); TV(a[i + K]));
    if (ti > bi || (bi == ti && bv <= tv)) {
      ans = i;
      bi = ti, bv = tv;
    }
    if (bi > ti + K)
      break;
  }

  TLN(TV(ans));
  sort(a + ans, a + ans + K);
  copy_n(a, n, std::ostream_iterator<int>(std::cout, " "));
  cout << endl;
  return 0;
}

// vim: ts=2 sw=2
