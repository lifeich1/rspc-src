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

const int N = 501001;
char cv[N], ic[N];
int it[N], ix[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, Q;
  string s;
  cin >> n >> s >> Q;
  fill(cv, cv + n, 0);
  int q = Q;
  while (Q--) {
    cin >> it[Q] >> ix[Q] >> ic[Q];
    TLN(TV(it[Q]); TV(ix[Q]); TV(ic[Q]));
  }
  int T = 0;
  for (int i = 0; i < q; ++i) {
    if (it[i] == 1) {
      int x = ix[i] - 1;
      if (0 == cv[x]) {
        cv[x] = ic[i];
        if (0 != T) {
          if (T == 2)
            cv[x] = tolower(cv[x]);
          else
            cv[x] = toupper(cv[x]);
        }
      }
    } else if (0 == T) {
      T = it[i];
    }
  }
  for (int i = 0; i < n; ++i)
    if (0 != cv[i])
      s[i] = cv[i];
    else if (T) {
      if (T == 2)
        s[i] = tolower(s[i]);
      else
        s[i] = toupper(s[i]);
    }
  cout << s << endl;
  return 0;
}

// vim: ts=2 sw=2
