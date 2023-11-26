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

const int N = 100001;
int lp[N], c[N];
vector<int> ps;

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif
  for (int i = 2; i < N; ++i) {
    if (0 == lp[i])
      ps.emplace_back(i);
    for (int p : ps) {
      int t = p * i;
      if (t >= N)
        break;
      lp[t] = p;
      if (i % p == 0)
        break;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a;
    a.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    sort(a.begin(), a.end());
    fill(c, c + a.back() + 1, 0);
    map<int,int> cnt;
    for (int x : a) cnt[x]++;
    int64_t ans = 0;
    int res = n;
    for (auto [x, ct] : cnt) {
      int64_t wt = 0;
      for (int i = 0; i < ct; ++i)
        wt += --res;
      if (ct > 1) {
        ans += int64_t(x) * ct * (ct - 1) / 2 * res;
      }
      if (ct > 2) {
        ans += int64_t(x) * int64_t(ct)*(ct-1)/2*(ct-2)/3;
      }
      map<int, int> pc;
      for (int t = x; t > 1; t /= lp[t])
        if (0 == lp[t]) {
          pc[t]++;
          break;
        } else
          pc[lp[t]]++;
      set<int> y = {1};
      for (auto [k, c] : pc) {
        vector<int> ad;
        for (int v : y)
          for (int i = 1, t = v * k; i <= c; ++i, t *= k)
            ad.emplace_back(t);
        for (auto t : ad)
          y.emplace(t);
      }
      vector<int> yl(y.begin(), y.end());
      vector<int> f(yl.size(), 0);
      for (int i = 0; i < yl.size(); ++i)
        f[i] = c[yl[i]];
      for (int i = yl.size() - 1; i >= 0; --i) {
        for (int j = yl.size() - 1; j > i; --j)
          if (yl[j] % yl[i] == 0)
            f[i] -= f[j];
        ans += int64_t(f[i]) * yl[i] * wt;
      }
      for (int t : yl)
        c[t]+=ct;
    }
    cout << ans << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
