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

const int N = 1010;
int f[N];
int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  cout << "?";
  for (int i = 1; i <= m; ++i)
    cout << ' ' << i;
  cout << endl << flush;
  int a0;
  cin >> a0;
  for (int i = m + 1; i <= n; ++i) {
    cout << "?";
    for (int j = 1; j < m; ++j)
      cout << ' ' << j;
    cout << ' ' << i << endl << flush;
    int t;
    cin >> t;
    f[i] = (t ^ a0);
  }
  for (int i = 1; i < m; ++i) {
    cout << "?";
    for (int j = 1; j < i; ++j)
      cout << ' ' << j;
    for (int j = i + 1; j <= m; ++j)
      cout << ' ' << j;
    cout << ' ' << (m + 1) << endl << flush;
    int t;
    cin >> t;
    f[i] = (t ^ a0 ^ f[m + 1]);
  }
  int am = a0;
  for (int i = 1; i < m; i += 2) {
    am ^= f[i] ^ f[i + 1];
  }
  for (int i = 1; i <= n; ++i)
    f[i] ^= am;
  f[m] = am;
  cout << "! ";
  copy_n(f + 1, n, std::ostream_iterator<int>(std::cout, " "));
  cout << endl << flush;
  return 0;
}

// vim: ts=2 sw=2
