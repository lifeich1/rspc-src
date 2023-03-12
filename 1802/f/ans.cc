#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define f first
#define s second
#define pb push_back
#define ld long double
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vec vector

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
const ld eps = 1e-6;
const int mod = 1e9 + 7;
const int oo = 2e9;
const ll OO = 2e18;
const int N = 800 + 10;
int n, m, p, w[N];
vec<pii> g[N];
pii dp[N][N];

struct state
{
    int v;
    int mx;
    int shows;
    int reminder;
};

bool cmp(const pii &a, const pii &b)
{
    if (a.f == b.f) return a.s > b.s;
    return a.f < b.f;
}

struct state_cmp
{
    bool operator() (const state &a, const state &b) const
    {
        if (a.shows == b.shows)
        {
            if (a.reminder == b.reminder)
            {
                if (a.v == b.v) return a.mx < b.mx;
                return a.v < b.v;
            }
            return a.reminder > b.reminder;
        }
        return a.shows < b.shows;
    }
};

void solve()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        for (int j = 1; j <= n; j++)
            dp[i][j] = {OO, -OO};
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, s;
        cin >> u >> v >> s;
        g[u].pb({v, s});
    }
    set<state, state_cmp> setik;
    dp[1][1] = {0, p};
    setik.insert({1, 1, 0, p});
    while (!setik.empty())
    {
        state cur = *setik.begin(); setik.erase(setik.begin());
        if (make_pair(cur.shows, cur.reminder) != dp[cur.v][cur.mx]) continue;
        for (auto &to : g[cur.v])
        {
            int need = max(0ll, (to.s - dp[cur.v][cur.mx].s + w[cur.mx] - 1)) / w[cur.mx];
            pii P = {dp[cur.v][cur.mx].f + need, dp[cur.v][cur.mx].s + need * w[cur.mx] - to.s};
            int nmx;
            if (w[cur.mx] > w[to.f]) nmx = cur.mx;
            else nmx = to.f;
            if (cmp(P, dp[to.f][nmx]))
            {
                dp[to.f][nmx] = P;
                setik.insert({to.f, nmx, P.f, P.s});
            }
        }
    }
    int ans = OO;
    for (int j = 1; j <= n; j++) ans = min(ans, dp[n][j].f);
    cout << (ans == OO ? -1 : ans) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
