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

int a[1010],l[2010],r[2010];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin >>n;
    for (int i= 0; i < n;++i) cin>>a[i];
    int m = 0; 
    auto dod = [&](int i,int j) {
        //TRACELN(cout<<"@"<<i<<' '<<j);
        l[m] = i, r[m] = j, ++m;
        int t0 = a[i-1], t1 = a[i];
        for (int k = i; k - 2 >= j; --k) a[k] = a[k-2];
        a[j] = t0; a[j+1] = t1;
    };
    for (int i = 1; i <= n; ++i) {
        int p = find(a,a+n,i) - a;
        if (p == i - 1) continue;
        if (i >= n-1) {
            cout<<"No\n";
            return 0;
        }
        if (p == n - 1) {
            dod(p, i-1);
            p = find(a,a+n,i) - a;
        }
        dod(p + 1, i - 1);
        //TRACELN(copy_n(a,n, std::ostream_iterator<int>(std::cout, " ")));
    }
    cout<<"Yes\n"<<m<<endl;
    for (int i = 0; i < m; ++i) cout<<l[i]<<' '<<r[i]<<endl;
    return 0;
}

