#include <bits/stdc++.h>
using namespace std;

template <class Vec, class Bool, size_t BoolLen>
void filter_primes(int n, Vec &out, span<Bool, BoolLen> marks) {
  fill(marks.data() + 2, marks.data() + n + 1, 1);
  auto append = back_inserter(out);
  for (int i = 2; i * i <= n; ++i) {
    if (marks[i])
      append = i;
    for (int p : out) {
      int t = p * i;
      if (t > n)
        break;
      marks[t] = 0;
      if (i % p == 0)
        break;
    }
  }
}

template <int N, class Vec> void filter_primes(Vec &out) {
  static array<uint8_t, N + 5> marks;
  filter_primes(N, out, span{marks});
}

template <class T, class Primes, class Map>
void factors_by_primes(T x, const Primes &primes, Map &out) {
  auto add = inserter(out, end(out));
  for (auto p : primes) {
    if (p > x)
      break;
    int q = 0;
    while (x % p == 0)
      ++q, x /= p;
    if (q > 0)
      add = make_pair(p, q);
  }
}

// ==================================================

vector<int> primes;
int n, m;
const int N = 111;
int a[N][N];
int f[N][N];

// template <class It> void dfs(It now, It tail, vector<int> &out, int k = 1) {
//   if (now == tail) {
//     out.push_back(k);
//     return;
//   }
//   auto [p, q] = *now;
//   auto it = next(now);
//   for (int i = 0; i <= q; ++i) {
//     dfs(it, tail, out, k);
//     k *= p;
//   }
// }

bool check(int d) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      f[i][j] = (a[i][j] % d == 0 ? 1 : 0);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (f[i][j] && i + j > 0) {
        int h = 0;
        if (i)
          h |= f[i - 1][j];
        if (j)
          h |= f[i][j - 1];
        f[i][j] = h;
      }
  return f[n - 1][m - 1];
}

int main() {
  // primes.reserve(1000);
  // filter_primes<1000000>(primes);

  /// test check most num with divisors
  // int ans = 0, ansdiv = 0;
  // for (int i = 2; i <= 1000000; ++i) {
  //   map<int, int> ps;
  //   factors_by_primes(i, primes, ps);
  //   int k = 1;
  //   for (auto [p, q] : ps)
  //     k *= q + 1;
  //   if (k > ansdiv)
  //     ansdiv = k, ans = i;
  // }
  // cout << ans << ' ' << ansdiv << endl;
  // {
  //   map<int, int> ps;
  //   factors_by_primes(ans, primes, ps);
  //   for (auto [p, q] : ps)
  //     cout << '#' << p << ' ' << q << endl;
  // }
  /// END

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        cin >> a[i][j];
    int v = __gcd(a[0][0], a[n - 1][m - 1]);
    // map<int, int> ps;
    // factors_by_primes(v, primes, ps);
    // vector<int> fas;
    // dfs(ps.begin(), ps.end(), fas);
    // sort(fas.begin(), fas.end());
    int ans = 1;
    if (check(v)) {
      cout << v << '\n';
      continue;
    }
    for (int i = 2; i * i <= v; ++i)
      if (v % i == 0) {
        if (check(i)) {
          ans = max(ans, i);
        }
        if (check(v / i))
          ans = max(ans, v / i);
      }
    cout << ans << '\n';
  }
  return 0;
}
