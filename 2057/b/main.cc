#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    map<int, int> c;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      c[x]++;
    }
    vector<int> h;
    for (auto [v, s] : c)
      h.emplace_back(s);
    sort(h.begin(), h.end());
    // copy(h.begin(), h.end(), ostream_iterator<int>(cout, " "));
    // cout << '\n';
    int q = 0;
    int l = h.size();
    while (q < l - 1 && h[q] <= k)
      k -= h[q++];
    cout << (h.size() - q) << '\n';
  }
  return 0;
}
