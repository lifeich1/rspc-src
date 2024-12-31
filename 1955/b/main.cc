#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, c, d;
    cin >> n >> c >> d;
    multiset<int> s;
    for (int i = n * n; i > 0; --i) {
      int x;
      cin >> x;
      s.emplace(x);
    }
    int a1 = *s.begin();
    bool ans = true;
    for (int i = 0; i < n && ans; ++i)
      for (int j = 0; j < n; ++j) {
        int t = a1 + i * c + j * d;
        auto it = s.find(t);
        if (it == s.end())
          ans = false;
        else
          s.erase(it);
      }
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}
