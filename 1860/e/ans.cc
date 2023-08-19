#include <bits/stdc++.h>
#define For(x, y, z) for (int x = y, x##__ = z; x <= x##__; x++)
#define Forij For(i, 0, 25) For(j, 0, 25) if (!p[i][j].empty())
#define mod 998244353
#define int long long
#define N 50004
#define ADD(x, y)                                                              \
  if (dis[i][j][x] == -1)                                                      \
  dis[i][j][x] = dis[i][j][y] + 1, q.push(x)
using namespace std;
vector<int> p[26][26];
string s;
bool vis[26][26];
int n, m, dis[26][26][N];
void solve() {
  cin >> s;
  n = s.length();
  For(i, 0, n - 2) p[s[i] - 'a'][s[i + 1] - 'a'].push_back(i);
  memset(dis, -1, sizeof dis);
  Forij {
    memset(vis, 0, sizeof vis);
    vis[i][j] = true;
    queue<int> q;
    for (int k : p[i][j])
      dis[i][j][k] = 0, q.push(k);
    while (!q.empty()) {
      int k = q.front();
      q.pop();
      if (k)
        ADD(k - 1, k);
      if (k < n - 2)
        ADD(k + 1, k);
      int x = s[k] - 'a', y = s[k + 1] - 'a';
      if (!vis[x][y]) {
        vis[x][y] = true;
        for (int z : p[x][y])
          ADD(z, k);
      }
    }
  }
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    int ans = abs(x - y);
    Forij ans = min(ans, dis[i][j][x - 1] + dis[i][j][y - 1] + 1);
    cout << ans << '\n';
  }
}
signed main() {
  cin.tie(0)->sync_with_stdio(false);
  cout.tie(0);
  int qwq = 1;
  //	cin>>qwq;
  while (qwq--)
    solve();
  return 0;
}
