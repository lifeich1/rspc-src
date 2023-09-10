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
int ap[N], at[N];
int64_t res[N];
int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  n--;
  int X, Y;
  cin >> X >> Y;
  for (int i = 0; i < n; ++i)
    cin >> ap[i] >> at[i];
  for (int st = 0; st < 840; ++st) {
    int64_t t = st;
    for (int i = 0; i < n; ++i) {
      auto d = t % ap[i];
      if (d)
        t += ap[i] - d;
      t += at[i];
    }
    res[st] = t - st;
  }
  TLN(TV(res[2]));
  int Q;
  cin >> Q;
  while (Q--) {
    int64_t q;
    cin >> q;
    q += X;
    q += res[q % 840];
    q += Y;
    cout << q << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
