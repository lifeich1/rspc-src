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

const int N = 201001;
vector<pair<int,int>> e[N];
int f[N], s[N];

int dfs(int r, int fa = 0) {
    vector<int> son;
    s[r] = 1;
    int c[3]={0,0,0};
    for (auto &ee : e[r]) {
        if (ee.first == fa) continue;
        dfs(ee.first, r);
        son .emplace_back (ee.first);
        int t = s[ee.first];
        s[r]+= t;
        if (f[ee.first]) c[t%3]++;
        else return 0;
    }
    if (s[r] <= 3) f[r] = 1;
    else if (s[r] % 3 == 0) {
        f[r] |= c[1] == 2 && c[2] == 0;
        f[r] |= c[2] == 1 && c[1] == 0;
    } else if (s[r] % 3 == 1) {
        f[r] |= c[1] == 0 && c[2] == 0;
    } else { // %=2
        f[r] |= c[1] == 1 && c[2] == 0;
    }
    return f[r];
}
void ans(int r, int fa = 0) 
{
    for (auto &[k,v] : e[r]) {
        if (k == fa) continue;
        ans(k, r);
        if (s[k] % 3 == 0) cout << v << ' ';
    }

}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n;
        cin >> n;
        fill(f,f+n+1,0);
        fill(s,s+n+1,0);
        for (int i = 1; i<=n;++i) {
            e[i].clear();
        }
        for (int i = 1; i<n;++i) {
            int u,v;cin >> u>>v;
            e[u] .emplace_back (v, i);
            e[v] .emplace_back (u, i);
        }
        if (n % 3 == 0&& dfs(1)) {
            cout << (n/3)-1<<endl;
            ans(1);
            cout<<endl;
        } else cout<<"-1\n";
    }
    return 0;
}

