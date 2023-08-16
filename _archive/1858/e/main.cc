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

const int M = 1000000;
const int K = 20;
int32_t pn[M * K + K][2], gt = 0, sz[M * K], h[M + K], htt = 0, sh[M + K];
char ops[M + 1001];
int32_t optt = 0, opk[M + 1001];
int hl[M + 1001];

int tins(int o, int d, int x) {
  int n = ++gt;
  pn[n][0] = pn[o][0];
  pn[n][1] = pn[o][1];
  if (0 == d) {
    pn[n][x & 1] = 1;
    sz[n] = pn[n][0] + pn[n][1];
    return n;
  }
  if (0 == (x & (1 << d)))
    pn[n][0] = tins(pn[o][0], d - 1, x);
  else
    pn[n][1] = tins(pn[o][1], d - 1, x);
  sz[n] = sz[pn[n][0]] + sz[pn[n][1]];
  return n;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  int dep = 0;
  while (tt--) {
    char &op = ops[++optt];
    cin >> op;
    if ('+' == op) {
      int x;
      cin >> x;
      h[++htt] = tins(h[sh[dep]], 19, x);
      hl[htt] = sh[++dep];
      sh[dep] = htt;
    } else if ('?' == op) {
      cout << sz[h[sh[dep]]] << endl << flush;
    } else if ('-' == op) {
      int &k = opk[optt];
      cin >> k;
      dep -= k;
    } else if ('!' == op) {
      --optt;
      while (ops[optt] != '+' && ops[optt] != '-')
        --optt;
      if (ops[optt] == '+') {
        sh[dep] = hl[sh[dep]];
        --dep;
      } else {
        dep += opk[optt];
      }
      --optt;
    }
  }
  TLN(TV(htt); TV(gt); TV(sh[dep]); TV(sz[h[sh[dep]]]));
  return 0;
}

// vim: ts=2 sw=2
