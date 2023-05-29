// Problem: B - Split and Insert
// Contest: AtCoder - AtCoder Grand Contest 062
// URL: https://atcoder.jp/contests/agc062/tasks/agc062_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<ll, ll> pii;

const int maxn = 110;

ll n, m, a[maxn], b[maxn], c[maxn], f[maxn][maxn][maxn];

void solve() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%lld", &b[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		c[a[i]] = i;
	}
	mems(f, 0x3f);
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			bool flag = 1;
			for (int k = i; k < j; ++k) {
				if (c[k] > c[k + 1]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				f[m + 1][i][j] = 0;
			}
		}
	}
	for (int k = m; k; --k) {
		for (int p = 1; p <= n; ++p) {
			for (int i = 1, j = p; j <= n; ++i, ++j) {
				f[k][i][j] = f[k + 1][i][j];
				for (int x = i; x < j; ++x) {
					f[k][i][j] = min(f[k][i][j], f[k + 1][i][x] + f[k + 1][x + 1][j] + b[k] * (j - x));
				}
			}
		}
	}
	printf("%lld\n", f[1][1][n] > 1e18 ? -1LL : f[1][1][n]);
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
