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
vector<int> sg[N];
int rh[N], A[N];

void add(int n, int x, int v) {
    for (; x <= n; x += x&(-x)) A[x] += v;
}
int psm(int n, int x) {
    int r = 0;
    for (; x > 0; x -= x&(-x)) r += A[x];
    return r;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,m,Q; cin >>n>>m>>Q;
    string s; cin >>s;
    for (int i = 0; i < m; ++i) {
        int u,v ; cin >>u>>v;
        sg[u] .emplace_back(i+1);
        sg[v+1].emplace_back(-(i+1));
    }
    vector<pair<int,int>> h; h.reserve(n);
    set<int> tg;
    for (int i = 1; i <= n; ++i) {
        for (int x : sg[i]) {
            if (x > 0) tg.emplace(x);
            else tg.erase(tg.find(-x));
        }
        if (tg.size()) {
            h.emplace_back(*tg.begin(), i);
        }
    }
    fill(rh, rh+n+1, -1);
    sort(h.begin(), h.end());
    for (int i = 0; i < h.size(); ++i) {
        int x = h[i].second;
        rh[x] = i+1;
        if (s[x-1] == '0') add(n, i+1, 1);
    }
    int c1 = count(s.begin(),s.end(),'1');
    while (Q--) {
        int p; cin >>p;
        int d;
        if (s[p-1] == '0') {
            ++c1;
            d = -1;
            s[p-1] = '1';
        } else {
            --c1;
            d = 1;
            s[p-1] = '0';
        }
        if (rh[p] >= 0) {
            add(n, rh[p], d);
        }
        cout<<psm(n, c1)<<endl;
    }
    return 0;
}

