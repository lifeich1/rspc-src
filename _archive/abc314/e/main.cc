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

const int N = 111;
vector<int> d[N];
double f[N];
int c[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> c[i] >> l;
    copy_n(std::istream_iterator<int>(std::cin), l, std::back_inserter(d[i]));
  }
  for (int p = 1; p <= m; ++p) {
    double b = 1e15;
    for (int o = 0; o < n; ++o) {
      int c0 = 0;
      int l = d[o].size();
      double t = 0;
      for (auto y : d[o]) {
        if (0 == y)
          ++c0;
        else
          t += f[max(p - y, 0)] / l;
      }
      if (l == c0)
        continue;
      t += c[o];
      t *= l;
      t /= l - c0;
      b = min(b, t);
    }
    f[p] = b;
  }
  cout << fixed << setprecision(6);
  cerr << fixed << setprecision(6);
#if defined(RSPC_TRACE_HINT)
  for (int i = 0; i < m; ++i)
    TLN(TV(i); TV(f[i]));
#endif
  cout << f[m] << endl;
  return 0;
}

// vim: ts=2 sw=2
