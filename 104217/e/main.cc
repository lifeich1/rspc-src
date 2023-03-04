#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
using namespace std;
#define self_todo_placeholder


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#endif

    int N, Q;
    vector<int> h;
    cin >> N >> Q;
    h.reserve(N);
    for (int i = 0, v; i < N; ++i) cin >> v, h.push_back(v);

    while (Q--) {
        int64_t K, t;
        cin >> K;

        t = 0;
        int ans = N + 1, ansl, ansr;
        for (int i = 0, j = 0; i < N; ++i) {
            t += h[i];
            for (; t > K && j < i; t -= h[j++]);
            if (t == K && i - j < ans) {
                ans = i - j, ansl = j, ansr = i;
            }
        }
        cout << ansl << ' ' << ansr << endl;
    }
    return 0;
}

