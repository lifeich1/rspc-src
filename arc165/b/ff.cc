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
int a[N], b[N], c[N];

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
  auto chk = [&]() {
    for (int i = 0; i < n; ++i)
      if (b[i] != c[i]) {
        if (b[i] > c[i])
          copy_n(b, n, c);
        break;
      }
  };
  for (int i = 0, j = K; j <= n; ++i, ++j) {
    copy_n(a, n, b);
    sort(b + i, b + j);
    chk();
  }
  copy_n(c, n, std::ostream_iterator<int>(std::cout, " "));
  cout << endl;
  return 0;
}

// vim: ts=2 sw=2
