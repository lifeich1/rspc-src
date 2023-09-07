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
int a[N];
char s[N];

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
    copy_n(std::istream_iterator<int>(std::cin), n, a + 1);
    cin >> s;
    int a1 = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1')
        a1 ^= a[i + 1];
      a[i + 1] ^= a[i];
    }
    int q;
    cin >> q;
    while (q--) {
      int op;
      cin >> op;
      if (1 == op) {
        int l, r;
        cin >> l >> r;
        a1 ^= a[r] ^ a[l - 1];
      } else if (2 == op) {
        int t;
        cin >> t;
        if (t == 1)
          cout << a1 << ' ';
        else
          cout << (a1 ^ a[n]) << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
