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
vector<int> e[N];
int f[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,m,K;
    cin>>n>>m>>K;
    for (int i = 0; i<m;++i) {
        int u,v; cin >> u>>v;
        e[u] .emplace_back(v);
        e[v] .emplace_back(u);
    }
    set<pair<int,int>> l;
    for (int i = 0; i < K; ++i)
    {
        int p, h; cin >> p>>h;
        f[p] = h+1;
        l.emplace(h+1, p);
    }
    while(l.size()) {
        auto [h,p] = *l.rbegin();
        {
            auto it = l.end();
            l.erase(--it);
        }
        if (h-- <= 1) break;
        for (int y : e[p]) {
            auto & a = f[y];
            if (a < h) {
                a = h;
                l.emplace(a, y);
            }
        }
    }
    vector<int> a;
    a.reserve(n);
    for (int i = 1; i <= n; ++i)
        if (f[i]) a .emplace_back(i);
    cout<<a.size()<<endl;
    copy(a.begin(),a.end(), std::ostream_iterator<int>(std::cout, " ") );
    cout<<endl;
    return 0;
}

