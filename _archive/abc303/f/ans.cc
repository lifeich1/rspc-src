//@Author: ZI_MA
#include<bits/stdc++.h>
using namespace std;
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PP pair<int,int>
#define all(x) x.begin()+1,x.end()
#define endl '\n'
#define int long long
const int INF=1e16,mod=998244353;
void _init_() {}
void solve() {
    int n, h;
    cin >> n >> h;
    vector<int> t(n + 1), d(n + 1);
    map<int, vector<int>, greater<int>> mp;
    multiset<int> temp;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> d[i];
        mp[t[i]].emplace_back(i);
        temp.insert(d[i] * t[i]);
    }
    vector<int> tt;
    vector<vector<int>> dd;
    int sz = 0;

    for (auto &[tik, vec] : mp) {
        tt.emplace_back(tik);
        dd.emplace_back(vec);
        sz++;
    }

    vector<int> pre(sz), suf(sz);
    for(int i = 0; i < sz; i++) {
        for(auto j : dd[i]) {
            pre[i] = max(pre[i], d[j]);
        }
        if(i != 0) pre[i] = max(pre[i], pre[i - 1]);
    }

    for(int i = sz - 1; i >= 0; i--) {
        for(auto j : dd[i]) {
            suf[i] = max(suf[i], d[j] * t[j]);
        }
        if(i != sz - 1) suf[i] = max(suf[i], suf[i + 1]);
    }
    auto check = [&](int x) -> bool {
        __int128 now = h;
        for (int j = 0; j < sz; j++) {
            const auto &tik = tt[j];
            const auto &vec = dd[j];
            if (j == 0) {
                if (x > tik) {
                    int b = suf[j];
                    if ((now + b - 1) / b <= (x - tik)) return true;
                    now -= (x - tik) * b;
                    x = tik;
                }
            } else {
                if (x > tik) {
                    int a = pre[j - 1];
                    int b = suf[j];
                    int idx = min(x, max(tik, (b + a - 1) / a - 1));

                    if (idx < x) {
                        now -= (__int128)(x + idx + 1) * (x - idx) / 2 * a;
                    }

                    if ((now + b - 1) / b <= (idx - tik)) return true;
                    now -= (idx - tik) * b;
                    x = tik;
                }
            }
        }
        now -= (__int128)(x + 1) * x / 2 * pre[sz - 1];
        return now <= 0;
    };

    int l = -1, r = h;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
signed main() {
    IOS;
    _init_();
    int __=1;
    while(__--) solve();
    return 0;
}