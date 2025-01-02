#include <bits/stdc++.h>
using namespace std;

const int N = 201001;
int a[N];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    int64_t k;
    cin >> n >> k;
    copy_n(std::istream_iterator<int>(std::cin), n, a);
    int p = 0, q = n - 1;
    while (k > 0 && p < q) {
      // for (int i = 0; i < n; ++i)
      //   cout << a[i] << ' ';
      // cout << endl;
      int t = min(a[p], a[q]);
      if (k - t >= t) {
        a[p] -= t;
        a[q] -= t;
        k -= t + t;
      } else {
        int v = k - (k % 2);
        v /= 2;
        a[p] -= v + (k % 2);
        a[q] -= v;
        k = 0;
      }
      if (a[p] == 0)
        ++p;
      if (a[q] == 0)
        --q;
    }
    if (p == q && k >= a[p])
      a[p] = 0;
    cout << count(a, a + n, 0) << endl;
  }
  return 0;
}
