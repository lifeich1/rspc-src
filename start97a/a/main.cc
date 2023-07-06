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
int64_t h[N];
int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n, Q; cin >>n>>Q;
        copy_n(std::istream_iterator<int>(std::cin),n,a);
        sort(a,a+n);
        for (int i = 0; i < n-2; ++i) {
            h[i] = int64_t(n-i-1) * (n-i-2)/2; 
            if (i) h[i]+=h[i-1];
        }
        TRACELN(cout<<'|';copy(h,h+n-2, std::ostream_iterator<int64_t>(std::cout, " ")));
        while(Q--) {
            int64_t k; cin >>k;
            cout<< a[lower_bound(h,h+n-2, k) - h]<<endl;
        }
    }
    return 0;
}

