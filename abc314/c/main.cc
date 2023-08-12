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
vector<int> p[N];
int h[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    p[x].emplace_back(i);
  }
  fill(h, h + n, -1);
  for (int i = 1; i <= m; ++i)
    if (p[i].size()) {
      h[p[i][0]] = p[i].back();
      for (int k = 1; k < p[i].size(); ++k)
        h[p[i][k]] = p[i][k - 1];
    }
  for (int i = 0; i < n; ++i) {
    if (h[i] > -1)
      cout << s[h[i]];
    else
      cout << s[i];
  }
  cout << endl;
  return 0;
}

// vim: ts=2 sw=2
