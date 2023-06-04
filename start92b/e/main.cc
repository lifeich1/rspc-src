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

const int N = 501001, M = 1000000007;
int a[N], b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--){
        int n,K; cin>>n>>K;
        copy_n(std::istream_iterator<int>(std::cin),n,a);
        fill(b,b+n,0);
        sort(a,a+n);
        for (int i = 0; i < n; ++i) {
            int l = i < n-1 ? (a[i+1]-a[i]) : K;
            int d = min(K / (i+1), l);
            b[i] += d;
            K -= d * (i+1);
            if (K < i+1) {
                b[K-1]++;
                break;
            }
        }
        auto ad = [](int &x, int y) { x = (x+y) %M; };
        for (int i = n - 1, s = 0; i >= 0; --i) {
            ad(s, b[i]);
            ad(a[i], s);
        }
        TRACELN(copy_n(a,n, std::ostream_iterator<int>(std::cout, " ")));
        int ans = 0;
        auto mu = [](int x,int y)->int{ return int(int64_t(x)*y%M);};
        for (int i = 0,s = 0; i < n;++i) {
            ad(ans,mu(a[i],s));
            ad(s,a[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

