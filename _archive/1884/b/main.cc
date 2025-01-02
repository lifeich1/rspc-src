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
int64_t a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  string s;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    fill(a, a + n, -1);
    int64_t v = 0;
    for (int i = 0, c = 0; i < n; ++i) {
      if (s[i] == '0') {
        v += i - c;
        if (a[c] < 0)
          a[c] = v;
        ++c;
      }
    }
    copy(a, a + n, std::ostream_iterator<int64_t>(std::cout, " "));
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
