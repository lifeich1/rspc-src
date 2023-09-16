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

vector<int> ps[3][10];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  string s1, s2, s3;
  int m;
  cin >> m >> s1 >> s2 >> s3;

  for (int i = 0; i < m; ++i) {
    ps[0][s1[i] - '0'].emplace_back(i);
    ps[1][s2[i] - '0'].emplace_back(i);
    ps[2][s3[i] - '0'].emplace_back(i);
  }
  auto cal = [=](vector<int> const &v1, vector<int> const &v2,
                 vector<int> const &v3) -> int {
    if (v1.empty() || v2.empty() || v3.empty())
      return -1;
    int t = v1.front(), l = 0, nx;
    auto p = upper_bound(v2.begin(), v2.end(), t);
    if (p == v2.end())
      nx = v2.front();
    else
      nx = *p;
    if (t >= nx)
      ++l;
    t = nx;

    p = upper_bound(v3.begin(), v3.end(), t);
    if (p == v3.end())
      nx = v3.front();
    else
      nx = *p;
    if (t >= nx)
      ++l;
    t = nx;
    return l * m + t;
  };
  int ans = -1;
  auto upd = [&](int x) {
    if (x > -1 && (x < ans || ans == -1))
      ans = x;
  };
  for (int i = 0; i < 10; ++i) {
    upd(cal(ps[0][i], ps[1][i], ps[2][i]));
    upd(cal(ps[0][i], ps[2][i], ps[1][i]));
    upd(cal(ps[1][i], ps[0][i], ps[2][i]));
    upd(cal(ps[1][i], ps[2][i], ps[0][i]));
    upd(cal(ps[2][i], ps[1][i], ps[0][i]));
    upd(cal(ps[2][i], ps[0][i], ps[1][i]));
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
