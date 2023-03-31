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
int xs[N], ys[N], en, a[N], f[N], ls[N];
vector<int> ee[N];

int & fa(int u) {
    if (f[u] == -1) f[u] = u;
    if (f[u] == u) return f[u];
    auto & r = fa(f[u]);
    f[u] = r;
    return r;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        en = 0;
        int n, m;
        cin >> n >> m;
        copy_n(std::istream_iterator<int> (cin), n, a);
        fill(f, f + n, -1);
        fill(ls, ls + n, 0);
        for (int i = 0; i < n; ++i) ee[i].clear();
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v; u--, v--;
            xs[i] = u; ys[i] = v;
            ee[u].push_back(i);
            ee[v].push_back(i);
        }
        set<pair<int,int>> ss;
        auto add = [&](int u, int v) {
            if(ls[v] == 0) {
                for (auto e : ee[v]) {
                    ss.emplace(max(a[xs[e]], a[ys[e]]), e);
                }
                ++ls[v];
            } else v = fa(v);
            TRACELN(cout << "  " << u << ' ' << v << ' ' << ls[u] << ' ' << ls[v]);
            if (ls[v] > ls[u]) swap(u, v);
            ls[u] += ls[v];
            fa(v) = fa(u);
            TRACELN(cout << '=' << u << ' ' << v << "  " << ls[u]<< ' '<<f[fa(v)]);
        };
        for (int i = 0; i < n; ++i) {
            if (0 == a[i]) {
                for (auto e : ee[i]) {
                    ss.emplace(max(a[xs[e]], a[ys[e]]), e);
                }
                ls[i] = 1;
            }
            f[i] = i;
        }
        while (ss.size()) {
            auto [ma, e] = *ss.begin();
            ss.erase(ss.begin());
            int u = xs[e], v = ys[e];
            TRACELN(cout << ':' << u << ' ' << v << ','<<fa(u)<<' ' <<fa(v));
            if (fa(u) == fa(v)) continue;
            if (0 == ls[u]) swap(u, v);
            if (a[v] > ls[fa(u)]) break;
            add(fa(u), v);
        }
        cout << (*max_element(ls, ls + n) == n ? "YES\n" : "NO\n");
    }
    return 0;
}

