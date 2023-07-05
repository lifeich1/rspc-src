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


int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif


    int n,m; cin >>n>>m;
    int L,R; cin>>L>>R;
    vector<int> a;
    copy_n(std::istream_iterator<int>(std::cin),n-2, std::back_inserter(a));
    sort(a.begin(), a.end());
    int ans = -1;
    for (int i = 0; i < n-1-m; ++i) {
        int y = i + m - 1;
        int d = 0;
        if (a[i] < L) d += abs(a[i]-L);
        if (a[y] > R) d += abs(a[y]-R);
        if (ans < 0 || ans > d) ans = d; 
    }
    cout<<ans<<endl;
    return 0;
}

