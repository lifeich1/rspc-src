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

const int N = 1001001;
int nq = 0, pr[N*30],pl[N*30],sz[N*30];
int a[N];

void ins(int &n, int l, int r, int x) {
    if (n == 0) {
        n = ++nq;
        pr[n] = pl[n] = 0;
        sz[n] = 0;
    }
    sz[n] ++;
    if (l == r) return;
    int md = (l+r)>>1;
    if (x <= md) ins(pl[n], l, md, x);
    else ins(pr[n], md+1, r, x);
}


int64_t qry(int n, int l, int r, int k) {
    if (n == 0) return 0;
    if (r <= k) return sz[n];
    int md = (l+r)>>1;
    if (md < k)  return sz[pl[n]]+ qry(pr[n], md+1, r, k);
    return qry(pl[n], l,md,k);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m; cin >>n>>m;
    int t = n*m;
    copy_n( std::istream_iterator<int>(std::cin) ,t, a);
    int64_t ans = 0;
    const int L=0, R = 1000000000;
    int gh = 0;
    for (int i = n-1; i >= 0; --i) {
        int d = n - i - 1;
        int p = i*m;
        sort(a+p,a+p+m);
        int *pa =  a+p;
        for (int j = 0; j < m; ++j, pa++) {
            ans += qry(gh, L,R, *pa);
            ans += int64_t(d) * (j+1);
        }
        pa = a+p;
        for (int j = 0; j < m; ++j, pa++) {
            ins(gh, L,R,*pa);
        }
    }
    cout<<ans<<endl;
    return 0;
}

