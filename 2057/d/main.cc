#include <bits/stdc++.h>
using namespace std;

const int N = 201001;
const int N4 = N * 4;

struct A {
  int mx[N4], mi[N4], ans[N4];

  void ins(int n, int l, int r, int k, int v) {
    if (l == r) {
      mx[n] = mi[n] = v;
      ans[n] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    if (k <= mid)
      ins(n + n, l, mid, k, v);
    else
      ins(n + n + 1, mid + 1, r, k, v);
    ans[n] = max(ans[n + n], ans[n + n + 1]);
    ans[n] = max(ans[n], mx[n + n + 1] - mi[n + n]);
    mi[n] = min(mi[n + n], mi[n + n + 1]);
    mx[n] = max(mx[n + n], mx[n + n + 1]);
  }

  void rst(int n) {
    fill(ans, ans + n * 4 + 10, 0);
    fill(mi, mi + n * 4 + 10, 0);
    fill(mx, mx + n * 4 + 10, 0);
  }
};

A a1, a2;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    a1.rst(n);
    a2.rst(n);
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      a1.ins(1, 1, n, i, x - i);
      int r = n - i + 1;
      a2.ins(1, 1, n, r, x - r);
    }
    cout << max(a1.ans[1], a2.ans[1]) << '\n';
    while (q--) {
      int k, v;
      cin >> k >> v;
      a1.ins(1, 1, n, k, v - k);
      int j = n - k + 1;
      a2.ins(1, 1, n, j, v - j);
      cout << max(a1.ans[1], a2.ans[1]) << '\n';
    }
  }
  return 0;
}
