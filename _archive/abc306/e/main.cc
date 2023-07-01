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

const int N = 501001;
int nq = 0, pl[N*30],pr[N*30],sz[N*30], ar[N];
int64_t sm[N*30];

void ins(int &n, int l, int r, int x) {
    if (n == 0) {
        n = ++nq;
        pr[n] = pl[n] = 0;
        sz[n] = 0;
        sm[n] = 0;
    }
    sz[n] ++;
    sm[n] += x;
    if (l == r) return;
    int md = (l+r)>>1;
    if (x <= md) ins(pl[n], l, md, x);
    else ins(pr[n], md+1, r, x);
}

void clr(int n, int l, int r, int x) {
    sz[n]--, sm[n] -=x;
    if(l==r) return;
    int md = (l+r)>>1;
    if (x <= md) clr(pl[n], l,md, x);
    else clr(pr[n],md+1,r,x);
}

int64_t qry(int n, int l, int r, int k) {
    if (sz[n] <= k) return sm[n];
    if (l == r) return int64_t(min(k,sz[n])) * l;
    int64_t a = 0;
    int md = (l+r)>>1;
    if (sz[pr[n]]) {
        a += qry(pr[n], md+1,r, min(k,sz[pr[n]]));
        k -= sz[pr[n]];
    }
    if (k > 0) a += qry(pl[n], l, md, k);
    return a;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    const int L=0, R = 1000000000;
    int n, K, Q; cin >>n>>K>>Q;
    int gh = 0;
    for (int i = 0; i < n; ++i) ins(gh, L,R, 0);
    fill(ar, ar +n+1, 0);
    while(Q--) {
        int x,y; cin >>x>>y;
        clr(gh,L,R,ar[x]);
        ar[x] = y;
        ins(gh, L,R, y);
        cout<<qry(gh,L,R,K)<<endl;
    }
    return 0;
}

