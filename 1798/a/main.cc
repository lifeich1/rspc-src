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

int a[128];
int b[128];

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
        copy_n(std::istream_iterator<int> (cin), n, b);
        int ma = a[n - 1];
        int mb = b[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > ma || b[i] > mb) swap(a[i], b[i]);
        }
        cout << ((*max_element(a, a + n) <= ma
                && *max_element(b, b + n) <= mb)
                ? "YES\n" : "NO\n");
    }
    return 0;
}

