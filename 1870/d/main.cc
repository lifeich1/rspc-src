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
int a[N];

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
    copy_n(std::istream_iterator<int>(std::cin), n, a);
    vector<pair<int, int>> ans;
    int K;
    cin >> K;
    multiset<int> ss(a, a + n);
    map<int, int> vp;
    for (int i = 0; i < n; ++i)
      vp[a[i]] = i;
    {
      int l = vp.begin()->second;
      for (auto it = vp.begin(); it != vp.end(); ++it) {
        l = it->second = max(it->second, l);
      }
    }
    int dt = 0;
    int la = -1;
    while (1) {
      int cnt = K / (*ss.begin() - dt);
      TLN(TV(K); TV(cnt));
      if (0 == cnt)
        break;
      int mv = K / cnt;
      auto it = vp.upper_bound(mv + dt);
      if (it == vp.begin())
        break;
      --it;
      auto [_v, i] = *it;
      int v = a[i];
      if (i <= la)
        break;
      for (int j = la + 1; j <= i; ++j)
        ss.erase(ss.find(a[j]));
      la = i;
      ans.emplace_back(i, cnt);
      K -= (v - dt) * cnt;
      dt = v;
      TLN(TV(K); TV(dt); TV(i); TV(cnt); TV(v));
    }
    auto it = ans.begin();
    for (int i = 0; i < n; ++i) {
      if (it != ans.end()) {
        auto [p, c] = *it;
        cout << c << ' ';
        if (i == p)
          ++it;
      } else
        cout << "0 ";
    }
    cout << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
