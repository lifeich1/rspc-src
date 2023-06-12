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

const int N = 101001;
int f[N];
vector<int> e[N];
int p[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n,m,K;  cin >> n>>m>>K;
        fill(f,f+n+1, 0);
        for(int i = 0; i <= n; ++i) e[i].clear();
        copy_n(std::istream_iterator<int>(std::cin),K,p);
        for (int i = 0; i < K; ++i) {
            int d; cin >> d;
            f[p[i]] = max(f[p[i]], d);
        }
        for (int i = 0; i < m; ++i) {
            int x,y; cin >> x>> y;
            e[x] .emplace_back(y);
            e[y] .emplace_back(x);
        }
        set<pair<int,int>> h;
        for (int i = 1; i <= n; ++i) if (f[i]) h.emplace(f[i], i);
        while(h.size()) {
            auto [v, x] = *h.rbegin();
            auto it = h.end();
            h.erase(--it);
            if (f[x] != v) continue;
            if (v <= 1) break;
            --v;
            for (auto y : e[x]) {
                if (f[y] < v) {
                    f[y] = v;
                    h.emplace(v, y);
                }
            }
        }
        cout<< (any_of(f+1,f+1+n, [](int v) {return v == 0; })? "NO\n" : "YES\n");
    }
    return 0;
}

