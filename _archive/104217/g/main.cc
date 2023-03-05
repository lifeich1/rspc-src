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
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int N, M;
    cin >> N >> M;

    vector<int> a;
    {
        int t = M, m0 = M;
        if (M > 100) {
            for (; t > 0; t >>= 2, m0 >>= 1);
        }
        for (int i = 2; i <= m0; ++i)
            if (M % i == 0) {
                while (M % i == 0) M /= i;
                a.push_back(i);
            }
    }

    M = 1 << a.size();

    while (N--) {
        int64_t n;
        cin >> n;

        int64_t ans = n, step = n;
        bool l_up = true;
        for (bool wa = true; wa; ) {
            int64_t cnt = ans;
            for (int mask = 1; mask < M; ++mask) {
                bool pos = true;
                int64_t mul = 1;
                for (size_t i = 0; i < a.size(); ++i) {
                    int t = 1 << i;
                    if (t & mask) {
                        pos = !pos;
                        mul *= a[i];
                    }
                }
                int64_t t = ans / mul;
                cnt += pos ? t : -t;
            }
            if (cnt == n) {
                bool bl = true;
                for (size_t i = 0; i < a.size(); ++i)
                    if (ans % a[i] == 0) {
                        bl = false;
                        break;
                    }
                if (bl) {
                    cout << ans << ' ';
                    break;
                }
            }
            bool up = cnt < n;
            if (up && l_up) step <<= 1;
            else if (up != l_up) {
                step = max(step >> 1, static_cast<int64_t>(1));
            }
            ans += up ? step : -step;
        }
    }
    cout << endl;

    return 0;
}

