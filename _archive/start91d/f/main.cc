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
int a[N],c[N],h[N],b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n, q; cin >> n>>q;
        copy_n(std::istream_iterator<int>(std::cin),n,a+1);
        fill(c, c + n + 2, 0);
        sort(a + 1,a+1+n);
        while(q--) {
            int l,r;cin>>l>>r;
            c[l]++, c[r+1]--;
        }
        for (int i = 2; i <= n; ++i) c[i] += c[i-1], h[i] = i;
        h[1] = 1;
        sort(h+1,h+n+1,[&](int x,int y) { return c[x] < c[y]; });
        int64_t ans = 0;
        for (int i = 1; i <=n;++i) b[h[i]] = a[i], ans += int64_t(a[i]) * c[h[i]];
        cout<<ans<<endl;
        copy_n(b+1,n, std::ostream_iterator<int>(std::cout, " "));
        cout<<endl;
    }
    return 0;
}

