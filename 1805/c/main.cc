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
int64_t K[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n, m; cin >> n >> m;
        copy_n(std::istream_iterator<int64_t> (cin), n, K);
        sort(K, K + n);
        auto ok = [](int64_t k, int64_t b, int64_t ac4) { return (k - b) * (k - b) < ac4; };
        auto pr = [](int64_t k) { cout << "YES\n" << k << endl; };
        for (int _i = 0; _i < m; ++_i) {
            int64_t a, b, tc;
            cin >> a >> b >> tc;
            a*= tc * 4;
            auto i = lower_bound(K, K + n, b) - K;
            if (i < n && ok(K[i], b, a)) pr(K[i]);
            else if (i > 0 && ok(K[i-1], b, a)) pr(K[i-1]);
            else cout << "NO\n";
        }
        cout << endl;
    }
    return 0;
}

