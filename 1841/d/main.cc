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
const int N = 2048;
int a[N],b[N];
void ta_s(int n, int x, int v) {
    for (; x <= n; x += (-x) &x) a[x] = max(a[x], v);
}
int ta_g(int n, int x) {
    int t = 0;
    for(; x > 0; x -= (-x)&x) t = max(t, a[x]);
    return t;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        vector<pair<int,int>> s;
        for (int i = 0; i < n; ++i) {
            int l,r; cin >> l >> r;
            s.emplace_back(l, r);
        }
        sort(s.begin(), s.end());
        fill(a, a + n + 1, 0);
        int ans = 0;
        int mx = s[0].second;
        for (int i = 1; i < n; ++i) {
            mx = max(mx, s[i].second);
            if (s[i].first == s[i-1].first) b[i] = b[i-1];
            else b[i] = i;
        }

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (s[j].second >= s[i].first) {
                    int t = ta_g(n, b[j]) + 2;
                    ta_s(n, upper_bound(s.begin(), s.end(), pair<int,int>{max(s[i].second, s[j].second), mx}) - s.begin(), t);
                    TRACELN(cout<<"|"<<s[i].first<<' '<<s[i].second<<' '<<s[j].first<<' '<<s[j].second<<" "<<t);
                    ans = max(ans, t);
                }
        cout<<n - ans<<endl;
    }
    return 0;
}

