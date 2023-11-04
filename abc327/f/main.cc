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
int s[N * 4], mx[N * 4];

void add(int n, int l, int r, int x, int y, int da) {
  if (y < l || r < x)
    return;
  if (l >= x && r <= y) {
    s[n] += da;
    mx[n] += da;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    add(n + n, l, mid, x, y, da);
  if (y > mid)
    add(n + n + 1, mid + 1, r, x, y, da);
  mx[n] = s[n] + max(mx[n + n], mx[n + n + 1]);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, D, W;
  cin >> n >> D >> W;
  vector<pair<int, int>> a;
  a.resize(n);
  int len = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    len = max(len, a[i].second);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && a[j].first - a[i].first < D) {
      add(1, 1, len, a[j].second - W + 1, a[j].second, 1);
      ++j;
    }
    ans = max(ans, mx[1]);
    add(1, 1, len, a[i].second - W + 1, a[i].second, -1);
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
