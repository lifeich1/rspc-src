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
int a[N], b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif


    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        int64_t ans = 0;
        copy_n(std::istream_iterator<int>(std::cin) , n, a);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int l = j - i + 1;
                copy_n(a+i, l, b);

            }
        }
        cout << ans << endl;
    }
    return 0;
}

