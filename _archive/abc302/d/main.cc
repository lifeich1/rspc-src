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

    int64_t n,m,d;cin>>n>>m>>d;
    copy_n(std::istream_iterator<int64_t>(std::cin) ,n,a);
    copy_n(std::istream_iterator<int64_t>(std::cin) ,m,b);
    sort(a,a+n);
    sort(b,b+m);
    int64_t ans = -1;
    for_each(a,a+n,[&](auto x) {
            auto *p = upper_bound(b,b+m,x+d);
            auto y = *(--p);
            if (abs(x-y) <= d) ans=max(ans,x+y);
            });
    cout<<ans<<endl;
    return 0;
}

