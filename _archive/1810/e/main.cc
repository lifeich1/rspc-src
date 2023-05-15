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

const int N = 401001;
int a[N], f[N], ls[N];
set<pair<int,int>> se[N];

int & fa(int u) {
    if (f[u] == -1) f[u] = u;
    if (f[u] == u) return f[u];
    auto & r = fa(f[u]);
    f[u] = r;
    return r;
}
void sjoin(int u, int v) {
    if (ls[fa(u)] < ls[fa(v)]) swap(u, v);
    ls[fa(u)] += ls[fa(v)];
    fa(v) = fa(u);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n, m;
        cin >> n >> m;
        copy_n(std::istream_iterator<int> (cin), n, a);
        fill(f, f + n, -1);
        fill(ls, ls + n, 1);
        for (int i = 0; i < n; ++i) se[i].clear();
 TRACE(if (tt == 438)        TRACELN(cout << n<<' '<<m<<endl;copy_n(a, n, std::ostream_iterator<int> (cout," "))););
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            TRACE(if (tt == 438) TRACELN(if(tt==438)cout <<u<<' '<<v););
            u--, v--;
            se[u].emplace(a[v], v);
            se[v].emplace(a[u], u);
        }
        set<pair<int,int>> ss;
        ss.clear();
        for (int i = 0; i < n; ++i) {
            if (a[i] != 0) continue;
            if (ls[fa(i)] > 1) continue;
            ss.swap(se[fa(i)]);
            while (ss.size()) {
                auto [ta, y] = *ss.begin();
                ss.erase(ss.begin());
                TRACELN(cout<<'.'<<y<<' '<<ta<<' '<<i);
                if (fa(y) == fa(i)) continue;
                TRACELN(cout<<':'<<y<<' '<<ta<<' '<<i);
                if (ls[fa(i)] < ta) {
                    ss.emplace(ta, y);
                    break;
                }
                ss.insert(se[fa(y)].begin(), se[fa(y)].end());
                TRACE(cout<<'='<<fa(i)<<' '<<fa(y)<<' ');
                sjoin(i, y);
                TRACELN(cout<<ls[fa(i)]);
            }
            se[fa(i)].swap(ss);
        }
        TRACE(cout << tt << ' ');
        cout << (*max_element(ls, ls + n) == n ? "YES\n": "NO\n");
    }
    return 0;
}

