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

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    map<tuple<int, int, int, int>, int> f;
    f[make_tuple(a, b, c, d)] = (res(a, b, c, d) == 0 ? 1 : 0) + 1;
    vector<tuple<int, int, int, int>> ls;
    ls.emplace_back(a, b, c, d);
    auto touch = [&](int a, int b, int c, int d, int v) {
      if (a < 0 || b < 0 || c < 0 || d < 0)
        return;
      v += (res(a, b, c, d) == 0 ? 1 : 0);
      auto tp = make_tuple(a, b, c, d);
      auto &v1 = f[tp];
      if (v1 < v) {
        v1 = v;
        ls.emplace_back(std::move(tp));
      }
    };
    for (uint32_t i = 0; i < ls.size(); ++i) {
      const auto [a, b, c, d] = ls[i];
      auto v = f[ls[i]];
      // cout << "*" << a << ' ' << b << ' ' << c << ' ' << d << '=' << v <<
      // endl;
      touch(a - 1, b, c, d, v);
      touch(a, b - 1, c, d, v);
      touch(a, b, c - 1, d, v);
      touch(a, b, c, d - 1, v);
    }
    cout << f[make_tuple(0, 0, 0, 0)] - 1 << '\n';
  }
  return 0;
}
