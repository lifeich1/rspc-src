#include <bits/stdc++.h>

using namespace std;

const long long pw10 = 1e12;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    int n = s.size();
    int cnt0 = 0, cnt1 = count(s.begin(), s.end(), '1');
    long long ans = 1e18;
    if (n == 1) ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      cnt0 += s[i] == '0';
      cnt1 -= s[i] == '1';
      int k = cnt0 + cnt1 + (s[i] == '1') + (s[i + 1] == '0');
      long long cur = (n - k) * (pw10 + 1);
      if (s[i] > s[i + 1]) cur += pw10;
      ans = min(ans, cur); 
    }
    cout << ans << '\n';
  }
}
