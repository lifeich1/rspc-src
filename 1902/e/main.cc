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

const int N = 1001001;
int nx[N][26], c[N], e[N], tt = 1;
int64_t s[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  vector<string> a;
  cin >> n;
  a.reserve(n);
  copy_n(std::istream_iterator<string>(cin), n, std::back_inserter(a));

  for (const auto &st : a) {
    int x = 1;
    for (int i = 0; i < st.length(); ++i) {
      s[x] += st.length() - i;
      c[x]++;
      int &p = nx[x][st[i] - 'a'];
      if (0 == p)
        p = ++tt;
      x = p;
    }
    c[x]++;
    e[x]++;
  }
  int64_t ans = 0;
  for (const auto &st : a) {
    int x = 1;
    for (int i = st.length() - 1; i >= 0; --i) {
      int p = nx[x][st[i] - 'a'];
      ans += int64_t(c[x] - c[p]) * (i + 1);
      ans += s[x] - s[p] - c[p];
      TLN(TV(s[x]); TV(s[p]); TV(c[p]); TV(c[x] - c[p]); TV(ans); TV(e[x]));
      x = p;
      if (0 == x)
        break;
    }
    ans += s[x];
    TLN(TV(ans));
  }
  cout << ans << endl;
  return 0;
}

// vim: ts=2 sw=2
