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
int pa[111], sn[111], de[111];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n;
  cin >> n;
  copy_n(std::istream_iterator<int>(std::cin), n - 1, pa + 2);
  for (int i = 2; i <= n; ++i)
    ++sn[pa[i]], de[i] = de[pa[i]] + 1;
  int sch = 1;
  function<int(vector<int> &)> rp = [](vector<int> &) { return 1; };
  if (*max_element(de, de + n + 1) <= 1) {
    cout << "1\n";
    for (int i = 2; i <= n; ++i)
      cout << "1 ";
    cout << endl;
  } else {
    vector<int> c(n + 1, 0);
    for (int i = n; i >= 2; --i) {
      if (sn[i] == 1)
        c[i] = 1;
      if (c[i])
        c[pa[i]] = 3 - c[i];
    }
    TLN(TA(c, cerr << _ << ' '));
    c[1] = 2;
    for (int i = 2; i <= n; ++i) {
      if (0 == c[i])
        c[i] = 3 - c[pa[i]];
    }
    c[1] = 0;
    TLN(TA(c, cerr << _ << ' '));
    bool ok2 = true;
    for (int i = 2; i <= n; ++i)
      if ((pa[i] != 1 && c[i] == c[pa[i]]) || (sn[i] == 1 && c[i] != 1)) {
        ok2 = false;
        break;
      }

    if (!ok2) {
      sch = 3;
      cout << "3\n";
      for (int i = 2; i <= n; ++i) {
        cout << ((de[i] - 1) % 3 + 1) << " ";
      }
      rp = [](vector<int> &a) -> int {
        if (2 == count(a.begin(), a.end(), 0)) {
          return (max_element(a.begin(), a.end()) - a.begin()) + 1;
        }
        int t = find(a.begin(), a.end(), 0) - a.begin();
        return (t + 1) % 3 + 1;
      };
    } else {
      sch = 2;
      cout << "2\n";
      for (int i = 2; i <= n; ++i)
        cout << c[i] << ' ';
      cout << endl;
      rp = [=](vector<int> &a) {
        if (a[0] == a[1] && a[0] == 1) {
          return 1;
        }
        if (a[0] == 1)
          return 1;
        else
          return 2;
      };
    }
    cout << endl;
  }
  cout << flush;
  while (1) {
    int op;
    cin >> op;
    if (0 != op)
      break;
    vector<int> a(sch, 0);
    copy_n(std::istream_iterator<int>(std::cin), sch, &a[0]);
    cout << rp(a) << endl << flush;
  }
  return 0;
}

// vim: ts=2 sw=2
