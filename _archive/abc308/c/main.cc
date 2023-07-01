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
int64_t a[N],b[N],h[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n ;cin >>n;
    for (int i = 1; i <= n; ++i) {
        cin >>a[i]>>b[i];
        b[i]+=a[i];
        h[i-1] = i;
    }
    sort(h,h+n, [&](int64_t l, int64_t r) {
                auto u = b[r]*a[l], v = b[l]*a[r];
                return u>v || (u==v&& l<r);
            });
    copy_n(h,n, std::ostream_iterator<int64_t>(std::cout, " "));
    cout<<endl;
    return 0;
}

