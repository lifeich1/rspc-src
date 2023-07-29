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

const int N = 201001;
int f[N][3];

int mi(int a, int b, int c) { return min(a, min(b, c)); }
int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    f[0][1] = f[0][2] = n;
    switch (x) {
    case 0:
      f[i][0] = mi(f[i - 1][0] + 1, f[i - 1][1] + 2, f[i - 1][2]);
      f[i][1] = min(f[i - 1][0], f[i - 1][1] + 1);
      f[i][2] = n;
      break;
    case 1:
      f[i][0] = min(f[i - 1][1] + 1, f[i - 1][2]);
      f[i][1] = min(f[i - 1][0], f[i - 1][1]);
      f[i][2] = min(f[i - 1][0] + 1, f[i - 1][2]);
      break;
    case 2:
      f[i][2] = mi(f[i - 1][0] + 1, f[i - 1][1] + 1, f[i - 1][2]);
      f[i][0] = f[i][2];
      f[i][1] = min(f[i - 1][0], f[i - 1][1]);
      break;
    }
  }
  cout << f[n][0] << endl;
  return 0;
}

// vim: ts=2 sw=2
