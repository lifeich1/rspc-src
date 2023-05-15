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
int a[N], s[N], p[N], pr[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, q;
    cin >> n >> q;
    copy_n(std::istream_iterator<int> (cin), n, a+1);
    for (int i = 1; i <=n ;++i) {
        if (i>1&&a[i]<=a[i-1]) p[i] = p[i-1];
        else p[i] = i, s[i]=1;
    }
    for (int i = n; i > 0; --i) {
        if (i < n&&a[i]>=a[i+1]) pr[i] = pr[i+1];
        else pr[i]=i, s[i]=1;
    }
    for (int i = 2; i <= n; ++i) s[i]+=s[i-1];
    while(q--) {
        int l, r; cin >> l>> r;
        cout << (s[r]-s[l-1]+(p[l]!=l&&pr[l]!=l)+(p[r]!=r&&pr[r]!=r&&l!=r))<<endl;
    }
    return 0;
}

