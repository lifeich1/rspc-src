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

const int N = 3030;
int b[N], fl[N][N], fr[N][N], oz[N];

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
    int n, K;
    cin >> n >> K;
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(),
              [](auto c) { return (c == '0' ? '1' : '0'); });
    b[0] = 0;
    for (int i = 1; i <= n; ++i)
      b[i] = (s[i - 1] - '0') + b[i - 1];
    fl[0][0] = fl[0][1] = 0;
    if (s[0] == '0')
      fl[0][0] = 1;
    else
      fl[0][1] = 1;
    for (int i = 1; i < n; ++i)
      for (int j = 0; j <= i + 1; ++j) {
        if (s[i] == '0') {
          fl[i][j] = fl[i - 1][j] + 1;
        } else if (j) {
          fl[i][j] = fl[i - 1][j - 1] + 1;
        } else
          fl[i][j] = 0;
      }
    for (int i = 1; i < n; ++i)
      for (int j = 0, t = 0; j <= i; ++j) {
        t = max(t, max(fl[i][j], fl[i - 1][j]));
        fl[i][j] = t;
      }

    fr[n - 1][0] = fr[n - 1][1] = 0;
    if (s[n - 1] == '0')
      fr[n - 1][0] = 1;
    else
      fr[n - 1][1] = 1;
    for (int i = n - 2; i >= 0; --i) {
      int t = n - i;
      for (int j = 0; j <= t; ++j) {
        if (s[i] == '0') {
          if (j < t)
            fr[i][j] = fr[i + 1][j] + 1;
          else
            fr[i][j] = 0;
        } else if (j) {
          fr[i][j] = fr[i + 1][j - 1] + 1;
        } else
          fr[i][j] = 0;
      }
    }
    for (int i = n - 2; i >= 0; --i)
      for (int j = 0, t = 0; j <= n - i; ++j) {
        t = max(t, fr[i][j]);
        if (j < n - i)
          t = max(t, fr[i + 1][j]);
        fr[i][j] = t;
      }

    fill(oz, oz + n + 1, -1);
    oz[0] = fl[n - 1][K];
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j) {
        int k0 = b[j + 1] - b[i];
        k0 = j - i + 1 - k0;
        if (k0 > K)
          break;
        int v = 0;
        if (i)
          v = max(v, fl[i - 1][min(K - k0, i)]);
        if (j + 1 < n)
          v = max(v, fr[j + 1][min(K - k0, n - j - 1)]);
        oz[j - i + 1] = max(oz[j - i + 1], v);
      }
    TLN(TV(s));
    TLN(TI(oz, oz + n + 1, cerr << _ << ' '));
    for (int a1 = 1; a1 <= n; ++a1) {
      int ans = 0;
      for (int i = 0; i <= n; ++i)
        if (oz[i] != -1) {
          ans = max(ans, i * a1 + oz[i]);
        }
      cout << ans << ' ';
    }
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
