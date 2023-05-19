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
int a[N], b[N];
pair<int,int> bi[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n, k;
        cin >> n >> k;
        copy_n(std::istream_iterator<int>(std::cin) ,n, a);
        copy_n(std::istream_iterator<int>(std::cin) ,n, b);
        sort(b, b + n);
        for (int i = 0; i < n; ++i) bi[i] = {a[i], i};
        sort(bi, bi + n);
        for (int i = 0; i < n; ++i) a[bi[i].second] = b[i];
        copy_n(a, n, std::ostream_iterator<int>(std::cout, " "));
        cout<<endl;
    }
    return 0;
}

