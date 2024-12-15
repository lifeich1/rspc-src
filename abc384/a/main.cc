#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  char c1, c2;
  string s;
  cin >> n >> c1 >> c2 >> s;
  for (auto &c : s) {
    if (c != c1)
      c = c2;
  }
  cout << s << "\n";
  return 0;
}
