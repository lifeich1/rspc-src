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
int a[N],b[N],n;

int getsl(int x) {
    int i = lower_bound(a,a+n, x)-a;
    int t = b[i];
    if ((i & 1) == 0) t -= a[i] - x;
    return t;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    cin >> n;
    copy_n(std::istream_iterator<int>(std::cin),n,a);
    b[0] = 0;
    for (int i = 2; i < n;i+=2)
        b[i - 1] = b[i - 2], b[i] = b[i - 1] + (a[i] - a[i-1]);
    int q; cin >> q;
    while(q--) {
        int l,r;cin>>l>>r;
        cout<<getsl(r)-getsl(l)<<endl;
    }
    return 0;
}

