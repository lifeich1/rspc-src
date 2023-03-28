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

const int N = 301001;
int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        copy_n(std::istream_iterator<int> (cin), n, a);
        sort(a, a + n);
        auto mi = a[0], mx = a[n - 1];
        int64_t s = 0, s0 = 0, s1 = 0;
        for (int i = 0, j = lower_bound(a, a + n, 0) - a; i < n; ++i) {
            auto t = s + a[i];
            if (t <= mi && j < n) {
                swap(a[i], a[j++]);
                s += a[i];
            } else s = t;
            if (s < s0) s0 = s;
            if (s > s1) s1 = s;
        }
        if (s1 - s0 < int64_t(mx) - mi) {
            cout << "Yes\n";
            copy_n(a, n, std::ostream_iterator<int> (cout, " "));
            cout << endl;
        } else cout << "NO\n";
    }
    return 0;
}

