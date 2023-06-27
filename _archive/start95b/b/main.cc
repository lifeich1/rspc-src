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

const int N = 101001;
int a[N],b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n, m, H;  cin >>n>>m>>H;
        copy_n(std::istream_iterator<int>(std::cin) ,n,a);
        copy_n(std::istream_iterator<int>(std::cin) ,m,b);
        sort(a,a+n,greater<int>{});
        sort(b,b+m,greater<int>{});
        n = min(n, m);
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            int64_t t = b[i];
            t *= H;
            ans += min(t, int64_t(a[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}

