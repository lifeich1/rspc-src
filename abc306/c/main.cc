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
vector<int> a[N];
int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n;
    cin >>n; int n3 = n*3;
    for (int i = 0; i < n3; ++i) {
        int t; cin >> t;
        a[t].emplace_back(i);
    }
    vector<int> h;h.reserve(n);
    for (int i = 1; i <= n; ++i) h.emplace_back(i);
    sort(h.begin(), h.end(), [&](int l, int r) { return a[l][1] < a[r][1]; });
    copy(h.begin(), h.end(), std::ostream_iterator<int>(std::cout, " ") );
    cout<<endl;
    return 0;
}

