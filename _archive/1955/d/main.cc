#include <bits/stdc++.h>
using namespace std;

const int N = 201010;

int a[N];
int b[N];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    copy_n(std::istream_iterator<int>(std::cin), n, a);
    copy_n(std::istream_iterator<int>(std::cin), m, b);
    unordered_map<int, int> ca, cb;
    for (int i = 0; i < m; ++i) {
      cb[b[i]]++;
    }
    int cur = 0;
    for (int i = 0; i < m; ++i) {
      int &l = ca[a[i]];
      int r = cb[a[i]];
      if (l++ < r)
        ++cur;
    }
    int ans = 0;
    for (int i = m; i <= n; ++i) {
      // cout << "*" << cur << "\n";
      if (cur >= k)
        ++ans;
      {
        int v = a[i - m];
        int &l = ca[v];
        int r = cb[v];
        if (--l < r)
          --cur;
      }
      {
        int v = a[i];
        int &l = ca[v];
        int r = cb[v];
        if (l++ < r)
          ++cur;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
