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
int64_t a[N],b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n,K; cin >> n >> K;
        copy_n(std::istream_iterator<int64_t>(std::cin),n,a);
        if (K > n) {
            cout << "0\n"; continue;
        }
        sort(a,a+n);
        b[0] = a[0];
        for (int i = 1; i < n; ++i) b[i] = b[i-1] + a[i];
        int64_t l = a[0], r = b[n-1] / K;
        auto chk = [&](int64_t x) {
            int k = upper_bound(a,a+n,x) - a;
            int64_t s = b[k-1] + x * (n - k);
            return s >= K * x;
        };
        while (l<r) {
            auto t = (l+r + 1) / 2; 
            if (chk(t)) l = t;
            else r = t - 1;
        }
        cout<<l<<endl;
    }
    return 0;
}

