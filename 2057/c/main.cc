#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    int a1, a2, a3;
    a1 = a2 = a3 = l;
    int k;
    for (k = 1 << 29; k > 0; k >>= 1)
      if (k <= r) {
        int t = r - k;
        t |= (k - 1);
        if (t >= l) {
          a1 = a2 = t;
          a2++;
          a3 = r;
          if (a2 == a3) {
            if (a1 > l) {
              a1--, a2--;
              for (k >>= 1; k > 0; k >>= 1) {
                if (a3 & k)
                  a3 -= k;
              }
            }
          }
          if (a2 != a3)
            break;
        }
      }
    // cout << "== " << k << ',' << a1 << ' ' << a2 << ' ' << a3 << '\n';
    // for (k >>= 1; k > 0; k >>= 1) {
    //   if (a3 & k)
    //     a3 -= k;
    // }
    cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
  }
  return 0;
}
