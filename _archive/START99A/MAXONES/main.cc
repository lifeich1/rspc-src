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

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  vector<int> a;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n < 3 || count(s.begin(), s.end(), '1') == n) {
      cout << s << endl;
      continue;
    }
    a.resize(n);
    TLN(TV(n); TV(s));
    transform(s.begin(), s.end(), a.begin(), [](char c) { return c - '0'; });
    bool ok = true;
    for (int *i = &a[0], *e = i + (n - 2); i != e && ok; ++i) {
      ok = ((i[0] ^ i[1] ^ i[2]) == 0);
      TLN(TV(i); TV(ok));
    }
    if (ok) {
      cout << s << endl;
      continue;
    }
    int t = a[0] * 2 + a.back();
    TLN(TV(t));
    switch (t) {
    case 0:
    case 1:
    case 2:
      fill(s.begin() + 1, s.end() - 1, '1');
      break;
    case 3:
      s[1] = '0';
      fill(s.begin() + 2, s.end() - 1, '1');
      break;
    }
    cout << s << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
