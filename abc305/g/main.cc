#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
#define TRACELN(...) TRACE(__VA_ARGS__; cout << endl)
#define TRACE_VEC(VEC, ITEM, ...) TRACE(cout << #VEC << "= "; for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
using namespace std;
#define self_todo_placeholder

pair<int,int> br() {
    string s;cin >>s;
    int t1,t2;
    t2 = t1 = 0;
    for_each(s.begin(), s.end(), [&](char ch) { t1=(t1<<1)+1, t2=t2*2+(ch=='b'); });
    return {t1,t2};
}

bool cont(int m1, int s1, int m2, int s2) {
    for(; m1 <= m2; m1<<=1,s1<<=1) {
        if ((s2 & m1) == s1) return false;
    }
    return true;
}
const int M = 998244353;

    int no[64],tr[64][64],f[64][64];
    int64_t tmp[64][64];
void mul(int a[64][64], int b[64][64]) {
    for (int i = 0; i < 64; ++i)
        for (int j = 0; j < 64; ++j) {
            tmp[i][j] = 0;
            for(int k = 0; k < 64;++k) {
                int64_t t = a[i][k];
                t *= b[k][j];
                tmp[i][j] = (tmp[i][j] + t) % M;
            }
        }
    for (int i = 0; i < 64;++i)
        copy_n(tmp[i], 64, a[i]);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int64_t n; int m; cin >>n>>m;
    vector<pair<int,int>> ss;
    while(m--) ss .emplace_back(br());
    if (n <= 6) {
        int ans = 0;
        m = (1<<n)-1;
        for (int i = 0; i < (1<<n);++i) {
            bool bl = true;
            for (auto [m1,s1] : ss) {
                if (!cont(m1,s1, m,i)) {
                    bl = false;
                    break;
                }
            }
            if (bl) ++ans;
        }
        cout<<ans<<endl;
        return 0;
    }
    for (int i = 0; i < 64;++i) {
        for (auto [m1, s1] : ss)
            if (!cont(m1,s1,63, i)) {
                no[i] = 1;
                break;
            }
    }
    for (int i = 0; i < 64;++i) if (!no[i])
        for (int ch = 0; ch < 2; ++ch) {
            int y = (i*2+ch) & 63;
            if (!no[y]) tr[i][y] = 1;
        }
    n -= 6;
    for (int i = 0; i < 64; ++i) f[i][i] = 1;
    for (int64_t k = 1; k <= n; k <<= 1) {
        if (n & k) mul(f, tr);
        mul(tr, tr);
    }
    int64_t ans = 0;
    for (int i = 0; i < 64;++i)
        for (int j = 0; j < 64;++j)
            ans += f[i][j];
    cout<<(ans%M)<<endl;
    return 0;
}

