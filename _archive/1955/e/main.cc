#include <bits/stdc++.h>
using namespace std;

const int N = 5050;
char s[N];
int a[N], c[N];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i)
      c[i] = s[i] - '0';
    int k = n;
    while (k > 1) {
      fill(a, a + n, 0);
      int d = 0;
      for (int i = 0, j = n - k; i <= j; ++i) {
        d ^= a[i];
        int v = d ^ c[i];
        if (0 == v) {
          d ^= 1;
          a[i + k] ^= 1;
        }
      }
      bool ok = true;
      for (int i = n - k + 1; i < n; ++i) {
        d ^= a[i];
        int v = d ^ c[i];
        if (0 == v) {
          ok = false;
          break;
        }
      }
      if (ok)
        break;
      --k;
    }
    // cout << k << '\n';
    cout << k << endl;
  }
  return 0;
}
