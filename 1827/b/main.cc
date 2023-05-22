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

const int N = 301001;
int a[N], h[N], X[N], K[N],Y[N], h2[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin>>n;
        copy_n(std::istream_iterator<int>(std::cin),n,a);
        int l = -1;
        for (int i = 0; i < n;++i) {
            while(l>=0&&a[h[l]]>a[i]) l--;
            K[i] = l>=0?h[l]:-1;
            h[++l] = i;
        }
        TRACELN(cout<<"K";copy_n(K, n, std::ostream_iterator<int>(std::cout, " ") ));
        l = -1;
        for (int i = n-1; i >=0;--i) {
            while(l>=0&&a[h[l]]>a[i]) l--;
            Y[i] = l>=0?h[l]:n;
            h[++l] = i;
        }
        fill(X,X+n,-1);
        l = -1; int l2 = -1;
        for (int i = n-1;i>=0;--i) {
            while(l2>=0&&a[h2[l2]]<a[i]) X[h2[l2--]] = i;
            while (l>=0&&a[h[l]]>a[i]) h2[++l2] = h[l--];
            h[++l] = i;
        }
        int64_t ans = 0;
        for (int i = 0; i < n;++i) {
            ans += int64_t(i) * (n - i);
            int k = K[i];
            int x = X[i];
            int y = Y[i];
            //TRACELN(cout<<":"<<setw(4)<<x<<' '<<setw(4)<<k<<' '<<setw(4)<<i<<' '<<setw(4)<<y);
            ans -= int64_t(k-x) * (y-i);
        }
        cout<<ans<<endl;
    }
    return 0;
}

