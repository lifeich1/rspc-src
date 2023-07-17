#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = (a); i < ((int)(b)); ++i)
#define per(i, a, b) for(int i = (a) - 1; i >= ((int)(b)); --i)
#define sz(a) ((int)a.size())
const int mod = 998244353, N = 100005;

ll solve(ll a, ll b, ll c, ll d, ll k) {
    auto f = [&](ll x) {return (a + b * x) * (c - d * x);};
    ll res = max(f(0), f(k));
    if (b * c - a * d < 0) return res;
    ll pos1 = (b * c - a * d) / (2 * b * d);
    if (pos1 >= 0 && pos1 <= k) res = max(res, f(pos1));
    pos1++;
    if (pos1 >= 0 && pos1 <= k) res = max(res, f(pos1));
    return res;
}
 
void frank() {
    int s, k; cin >> s >> k;
    ll res = 1ll * s * k;
    if (k == 0) {
        cout << res << "\n";
        return;
    }
    s += s % 10, k--;
    int de = 0; ll ss = s;
    for (int i = 0; i < 4; ++i) ss += ss % 10;
    de = ss - s;
    if (de == 0) {
        res = max(res, 1ll * s * k);
        cout << res << "\n";
        return;
    }
    for (int i = 0; i < 4 && k >= 0; ++i) {
        res = max(res, solve(s, de, k, 4, k / 4));
        s += s % 10, k--;
    }
    cout << res << "\n";
}
 
int main () {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        frank();
    }
}
