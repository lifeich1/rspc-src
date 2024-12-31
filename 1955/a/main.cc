#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = n * a;
    while (n > 1) {
      int t = ans - a - a + b;
      if (t < ans)
        ans = t, n -= 2;
      else
        break;
    }
    cout << ans << endl;
  }
  return 0;
}
