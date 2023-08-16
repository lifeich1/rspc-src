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

const int N = 101001;
char ops[N];
int opk[N], on;
vector<int> opr[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  vector<int> a;
  while (tt--) {
    char &op = ops[++on];
    cin >> op;
    int &k = opk[on];
    if ('+' == op) {
      cin >> k;
      a.emplace_back(k);
    } else if ('-' == op) {
      cin >> k;
      opr[on].clear();
      while (k--) {
        opr[on].emplace_back(a.back());
        a.pop_back();
      }
    } else if ('?' == op) {
      vector<int> v(a);
      sort(v.begin(), v.end());
      int t = unique(v.begin(), v.end()) - v.begin();
      cout << t << endl;
    } else if ('!' == op) {
      --on;
      while (ops[on] != '+' && ops[on] != '-')
        --on;
      if (ops[on] == '+') {
        a.pop_back();
      } else {
        auto &v = opr[on];
        copy(v.rbegin(), v.rend(), std::back_inserter(a));
      }
      --on;
    }
    TLN(cerr << ": "; TA(a, cerr << _ << ' '));
  }
  return 0;
}

// vim: ts=2 sw=2
