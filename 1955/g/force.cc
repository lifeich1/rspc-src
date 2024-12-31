
#include <iostream>
using namespace std;
int x, a, N, M, T, g, i, j, k, A[101][101], B[101][101];
#define r                                                                      \
  for (i = 0; i < N; i++)                                                      \
    for (j = 0; j < M; j++)
#define c cin >>
main() {
  cin >> T;
  while (T--) {
    cin >> N >> M;
    r cin >> A[i][j];
    auto D = [](int d) {
      B[0][0] = ++x;
      r if (B[i][j] == x) B[i + 1][j] = A[i + 1][j] % d ? -1 : x,
                                B[i][j + 1] = A[i][j + 1] % d ? -1 : x;
      if (B[N - 1][M - 1] == x)
        a = max(a, d);
    };
    a = 1, g = A[0][0];
    for (k = 1; k * k <= g; k++)
      if (g % k == 0)
        D(k), D(g / k);
    cout << a << '\n';
  }
}
// #include <bits/stdc++.h>
// using namespace std;
//
// const int N = 111;
// int a[N][N];
// set<int> s[N][N];
//
// int main() {
//   int tt;
//   cin >> tt;
//   while (tt--) {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < n; ++i)
//       for (int j = 0; j < m; ++j)
//         cin >> a[i][j];
//     int v = __gcd(a[0][0], a[n - 1][m - 1]);
//     for (int i = 0; i < n; ++i)
//       for (int j = 0; j < m; ++j)
//         a[i][j] = __gcd(a[i][j], v);
//     for (int i = 0; i < n; ++i)
//       for (int j = 0; j < m; ++j)
//         s[i][j].clear();
//     s[0][0].insert(v);
//     for (int i = 0; i < n; ++i)
//       for (int j = 0; j < m; ++j) {
//         if (i < n - 1)
//           for (int v : s[i][j]) {
//             s[i + 1][j].insert(__gcd(v, a[i + 1][j]));
//           }
//         if (j < m - 1)
//           for (int v : s[i][j]) {
//             s[i][j + 1].insert(__gcd(v, a[i][j + 1]));
//           }
//       }
//     cout << *s[n - 1][m - 1].rbegin() << '\n';
//   }
//   return 0;
// }
