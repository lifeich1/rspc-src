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

void mov(int &x, int &y, char c) {
  switch (c) {
  case 'U':
    y++;
    break;
  case 'D':
    y--;
    break;
  case 'L':
    x--;
    break;
  case 'R':
    x++;
    break;
  }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, Q;
  cin >> n >> Q;
  string s;
  cin >> s;
  map<pair<int, int>, vector<int>> L, R;
  vector<pair<int, int>> lp, rp;
  lp.reserve(n + 1);
  rp.reserve(n + 1);
  lp.emplace_back(0, 0);
  rp.emplace_back(0, 0);
  auto cm = [](auto &m, int x, int y) -> vector<int> & {
    return m[pair<int, int>(x, y)];
  };
  for (int i = 0, x = 0, y = 0; i < n; ++i) {
    mov(x, y, s[i]);
    lp.emplace_back(x, y);
    cm(L, x, y).emplace_back(i);
  }
  for (int i = n - 1, x = 0, y = 0; i >= 0; --i) {
    mov(x, y, s[i]);
    rp.emplace_back(x, y);
    cm(R, x, y).emplace_back(i);
  }
  while (Q--) {
    int x, y, l, r;
    cin >> x >> y >> l >> r;
    if (0 == x && 0 == y) {
      cout << "YES\n";
      continue;
    }
    auto &vl = cm(L, x, y);
    if (vl.size() && (vl.front() < l - 1 || vl.back() >= r)) {
      cout << "YES\n";
      continue;
    }
    auto [tx, ty] = lp[l - 1];
    auto [dx, dy] = rp[n - r];
    int ax = x - tx + dx;
    int ay = y - ty + dy;
    auto &vr = cm(R, ax, ay);
    TLN(TV(ax); TV(ay); TA(vr, cerr << _ << ' '));
    if (vr.size()) {
      if (vr.size() > 1 && vr.front() > vr.back()) {
        sort(vr.begin(), vr.end());
      }
      auto it = lower_bound(vr.begin(), vr.end(), l - 1);
      if (it != vr.end() && *it <= r - 1) {
        cout << "YES\n";
        continue;
      }
    }
    cout << "NO\n";
  }
  return 0;
}

// vim: ts=2 sw=2
