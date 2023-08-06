#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ld eps = 1e-8;
const int INF = 0x3f3f3f3f, mod = 998244353;

#ifndef ONLINE_JUDGE
#define debug(...)
//#include<debug>
#else
#define debug(...)
#endif

const int P = 998244353;
int i2 = 499122177, i6 = 166374059;

struct Data {
  Data() { f = g = h = 0; }

  ll f, g, h;
}; // 三个函数打包

Data calc(ll n, ll a, ll b, ll c) {
  ll ac = a / c, bc = b / c, m = (a * n + b) / c, n1 = n + 1, n21 = n * 2 + 1;
  // ac %= P,bc %= P;
  Data d;
  if (a == 0) { // 迭代到最底层
    d.f = bc * n1 % P;
    d.g = bc * n % P * n1 % P * i2 % P;
    d.h = bc * bc % P * n1 % P;
    return d;
  }
  if (a >= c || b >= c) { // 取模
    d.f = n * n1 % P * i2 % P * ac % P + bc * n1 % P;
    d.g = ac * n % P * n1 % P * n21 % P * i6 % P + bc * n % P * n1 % P * i2 % P;
    d.h = ac * ac % P * n % P * n1 % P * n21 % P * i6 % P +
          bc * bc % P * n1 % P + ac * bc % P * n % P * n1 % P;
    d.f %= P, d.g %= P, d.h %= P;

    Data e = calc(n, a % c, b % c, c); // 迭代

    d.h += e.h + 2 * bc % P * e.f % P + 2 * ac % P * e.g % P;
    d.g += e.g, d.f += e.f;
    d.f %= P, d.g %= P, d.h %= P;
    return d;
  }
  Data e = calc(m - 1, c, c - b - 1, a);
  d.f = n * m % P - e.f, d.f = (d.f % P + P) % P;
  d.g = m * n % P * n1 % P - e.h - e.f, d.g = (d.g * i2 % P + P) % P;
  d.h = n * m % P * (m + 1) % P - 2 * e.g - 2 * e.f - d.f;
  d.h = (d.h % P + P) % P;
  return d;
}

const int N = 200005;
int a[N];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  sort(a + 1, a + n + 1);

  int res = (a[1] + 1) % mod;
  ll t = 1ll * a[1] * n;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1])
      continue;
    int mi = a[i] - a[i - 1];
    int num = n - i + 1;
    ll ans = calc(mi, num, t, n).f;
    ans = (ans - (t / n) % mod + mi + mod) % mod;
    res = (res + ans) % mod;
    t += 1ll * mi * num;
  }
  printf("%d\n", res);
}
