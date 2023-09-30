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

const int N = 501001;
int mx[N * 4][2], lm[N * 4][2], rm[N * 4][2], fl[N * 4];

void frms(int n, int l, int r, int c) {
  if (l == r)
    return;
  int mid = (l + r) / 2;
  int len[2] = {mid - l + 1, r - mid};
  l = n + n, r = n + n + 1;
  mx[n][c] = max(mx[l][c], mx[r][c]);
  mx[n][c] = max(mx[n][c], rm[l][c] + lm[r][c]);
  if (lm[l][c] == len[0])
    lm[n][c] = len[0] + lm[r][c];
  else
    lm[n][c] = lm[l][c];
  if (rm[r][c] == len[1])
    rm[n][c] = len[1] + rm[l][c];
  else
    rm[n][c] = rm[r][c];
  mx[n][c] = max(mx[n][c], lm[n][c]);
  mx[n][c] = max(mx[n][c], rm[n][c]);
}

void frms(int n, int l, int r) {
  frms(n, l, r, 0);
  frms(n, l, r, 1);
}
void dofl(int n, int l, int r) {
  fl[n] &= 1;
  if (fl[n] == 0)
    return;
  if (fl[n]) {
    swap(mx[n][0], mx[n][1]);
    swap(lm[n][0], lm[n][1]);
    swap(rm[n][0], rm[n][1]);
  }
  fl[n] = 0;
  if (l < r) {
    fl[n + n] ^= 1;
    fl[1 + n + n] ^= 1;
  }
}

void build(int n, int l, int r, string_view s) {
  if (l == r) {
    mx[n][0] = mx[n][1] = 0;
    lm[n][0] = lm[n][1] = 0;
    rm[n][0] = rm[n][1] = 0;
    int t = s[l - 1] - '0';
    mx[n][t] = lm[n][t] = rm[n][t] = 1;
    fl[n] = 0;
    return;
  }
  int mid = (l + r) / 2;
  build(n + n, l, mid, s);
  build(n + n + 1, mid + 1, r, s);
  frms(n, l, r);
}

void flip(int n, int l, int r, int x, int y) {
  dofl(n, l, r);
  if (x <= l && y >= r) {
    fl[n] ^= 1;
    dofl(n, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    flip(n + n, l, mid, x, y);
  if (y > mid)
    flip(n + n + 1, mid + 1, r, x, y);
  frms(n, l, r);
}

tuple<int, int, int> ans(int n, int l, int r, int x, int y) {
  dofl(n, l, r);
  if (x <= l && r <= y) {
    if (l < r) {
      int mid = (l + r) >> 1;
      dofl(n + n, l, mid);
      dofl(1 + n + n, mid + 1, r);
    }
    frms(n, l, r);
    return {mx[n][1], lm[n][1], rm[n][1]};
  }
  int mid = (l + r) >> 1;
  if (y <= mid)
    return ans(n + n, l, mid, x, y);
  if (x > mid)
    return ans(n + n + 1, mid + 1, r, x, y);
  auto [lm, ll, lr] = ans(n + n, l, mid, x, y);
  auto [rm, rl, rr] = ans(n + n + 1, mid + 1, r, x, y);
  int len[2] = {mid + 1 - max(x, l), min(r, y) - mid};
  return {max(max(lm, rm), lr + rl), (ll == len[0] ? ll + rl : ll),
          (rr == len[1] ? rr + lr : rr)};
}

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  build(1, 1, n, s);
  while (m--) {
    int c, l, r;
    cin >> c >> l >> r;
    if (1 == c) {
      flip(1, 1, n, l, r);
    } else {
      auto [mx, _l, _r] = ans(1, 1, n, l, r);
      TLN(TV(_l); TV(_r));
      cout << mx << endl;
    }
    TLN(TV(mx[1][1]); TV(lm[1][1]));
  }
  return 0;
}

// vim: ts=2 sw=2
