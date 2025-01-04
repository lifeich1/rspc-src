#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    cout << (1 + max(a, b)) << '\n';
  }
  return 0;
}
