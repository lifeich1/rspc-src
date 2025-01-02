#include <bits/stdc++.h>
using namespace std;

// 得到每个塔：范围r时总伤减3^r=g值
// r>12时g必小于0
// for tower: f[mask join r] <- f[mask]+g(tower,r)
// ans=all time max

int n, m, K;
const int N = 55;
int c[N][N];

const int R = 12;
int g[N * N][R + 2];
const int MA = 1 << R;
int f0[2][MA];

void in_tow(int k) {
  int x, y, p;
  cin >> x >> y >> p;
  --x, --y;
  vector<int> d2;
  auto add_d2 = std::back_inserter(d2);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (c[i][j]) {
        auto w = x - i;
        auto h = y - j;
        add_d2 = w * w + h * h;
      }
  sort(d2.begin(), d2.end());
  fill(g[k], g[k] + R + 1, 0);
  for (int i = 1, q = 0, ne = 3; i <= R; ++i) {
    while (q < static_cast<int>(d2.size()) && d2[q] <= i * i)
      ++q;
    g[k][i] = q * p - ne;
    // cout << '=' << q;
    ne *= 3;
  }
  // cout << endl;
  // auto o = ostream_iterator<int>(cout, " ");
  // copy(g[k] + 1, g[k] + R + 1, o);
  // cout << endl;
  // copy(d2.begin(), d2.end(), o);
  // cout << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m >> K;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < m; ++j)
        c[i][j] = (s[j] == '#');
    }
    for (int i = 0; i < K; ++i)
      in_tow(i);
    auto *f = f0[0], *ff = f0[1];
    fill(f, f + MA, 0);
    for (int i = 0; i < K; ++i) {
      copy(f, f + MA, ff);
      swap(f, ff);
      for (int j = 1; j <= R; ++j)
        for (int s0 = 0; s0 < MA; ++s0)
          if (((1 << (j - 1)) & s0) == 0) {
            int s1 = s0 | (1 << (j - 1));
            f[s1] = max(f[s1], ff[s0] + g[i][j]);
          }
    }
    // cout << '*' << max_element(f, f + MA) - f << endl;
    cout << *max_element(f, f + MA) << endl;
  }
  return 0;
}
