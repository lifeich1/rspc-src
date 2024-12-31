#include <bits/stdc++.h>
using namespace std;

int res(int a, int b, int c, int d) {
  if (a + b + c + d == 0)
    return 1;
  a &= 1;
  b &= 1;
  c &= 1;
  d &= 1;
  return a ^ (b * 2) ^ (c * 3) ^ (d * 4);
}

int calc(int a, int b, int c, int d) {
  if (a < 0 || b < 0 || c < 0 || d < 0)
    return 0;
  if (res(a, b, c, d) != 0)
    return 0;
  int ans = 0;
  ans += a / 2 + b / 2 + c / 2 + d / 2;
  if ((a & 1) + (b & 1) + (c & 1) == 3
      // && a > 1 && b > 1 && c > 1
  )
    ++ans;
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    for (int m = 0; m < 16; ++m) {
      ans = max(ans, calc(a - (m & 1), b - ((m >> 1) & 1), c - ((m >> 2) & 1),
                          d - ((m >> 3) & 1)));
    }
    cout << ans << '\n';
  }
  return 0;
}
