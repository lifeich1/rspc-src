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
int64_t a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >>n;
        copy_n(std::istream_iterator<int64_t>(std::cin), n, a);
        auto mx = *max_element(a,a+n);
        while((mx&(-mx)) != mx) mx -= mx & (-mx);
        TRACELN(cout<<"mx="<<mx);
        int ans = count_if(a,a+n, [&](int64_t x) {return (x & mx)>0;});
        cout<<(ans+1)/2<<endl;
    }
    return 0;
}

