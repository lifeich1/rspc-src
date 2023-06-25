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
int x[N],y[N],c[N],h[N];
int pl[N*20],pr[N*20],mi[N*20],ad[N*20], tt = 0;

void st_tou(int &n) {
    if (n == 0) {
        n = ++tt;
        pl[n] = pr[n] = 0;
        mi[n] = 0;
        ad[n] = 0;
    }
}

// addto [x, ...)
void st_add(int &n, int L, int R, int x, int v) {
    st_tou(n);
    if (L >= x) {
        ad[n] += v;
        return;
    }
    int mid = (L+R)/2;
    if (x <= mid) st_add(pl[n], L, mid, x, v);
    st_add(pr[n], mid+1, R, x, v);
    st_tou(pl[n]);
    mi[n] = min(mi[pl[n]] + ad[pl[n]], mi[pr[n]] + ad[pr[n]]);
}

int st_min(int n, int L, int R) {
    if (0 == n) return 0;
    return mi[n] + ad[n];
}

int st_ins(int &n, int L, int R, int x, int v) {
    st_tou(n);
    v -= ad[n];
    if (L == R) {
        mi[n] = v;
        return v;
    }
    int mid = (L+R) / 2;
    if (x <= mid) st_ins(pl[n], L, mid, x, v);
    else st_ins(pr[n], mid+1, R, x, v);
    mi[n] = min(mi[n], v);
    return v;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,K,A; cin >>n>>K>>A;
    int ans = 0;
    for (int i= 0; i<n; ++i) {
        cin>>x[i]>>y[i]>>c[i];
        h[i] =i;
    }
    sort(h,h+n, [&](int l,int r) {
                return y[l] > y[r] || (y[l]==y[r] && x[l] < x[r]);
            });
    int gh = 0;
    // f_x+c{nx+1<=x}
    for (int k = K, p = 0; k >= 0; --k) {
        while(p < n && y[h[p]] >= k) {
            TRACELN(cout<<"ad "<<x[h[p]]+1<<' '<<c[h[p]]);
            st_add(gh, 0, K+1, x[h[p]]+1, c[h[p]]);
            ans += c[h[p]];
            ++p;
        }
        ans = min((K-k)*A, ans);
        ans = min(ans, st_min(gh, 0, K+1) + (K-k)*A);
        TRACELN(cout<<k<<":"<<ans<<" --"<<K-k<<' '<<ans-(K-k)*A<<' '<<st_min(gh, 0, K+1)<<' '<<gh);
        st_ins(gh, 0, K+1, K-k, ans-(K-k)*A);
        TRACELN(cout<<"cm: " << st_min(gh, 0, K+1));
    }
    cout<<ans<<endl;
    return 0;
}

