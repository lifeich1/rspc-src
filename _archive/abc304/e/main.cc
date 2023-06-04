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
int fa_[N],sz[N];

int& fa(int x) {
    if (fa_[x] == x) return fa_[x];
    auto & r = fa(fa_[x]);
    fa_[x] = r;
    return r;
}
void uni(int x, int y) {
    x = fa(x), y = fa(y);
    if (x == y) return ;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    fa(y) = x;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,m;cin>>n>>m;
    fill(sz, sz+n+1, 1);
    for (int i = 1; i <= n; ++i) fa_[i] = i;
    for (int i = 0; i < m;++i) {
        int x,y;cin>> x>>y;
        uni(x, y);
    }
    set<pair<int,int>> bd;
    int K;cin>>K;
    for (int i=0;i< K;++i) {
        int x,y;cin>> x>>y;
        bd.emplace(fa(x), fa(y));
        bd.emplace(fa(y), fa(x));
    }
    int Q;
    cin>>Q;
    while(Q--) {
        int x,y;cin>>x>>y;
        x = fa(x), y = fa(y);
        if (bd.find({x, y}) != bd.end()) {
            cout<<"No\n";
        } else{
            cout<<"Yes\n";
        }
    }
    return 0;
}

