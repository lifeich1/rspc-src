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

    vector<int> vs;
    int n;
    cin >> n;
    for (int i = 0, v; i < n; ++i) cin >> v, vs.push_back(v);

    for (int T = 1; T < 1001; ++T) {
        int x = (T * vs.front()) % n;
        bool bl = true;
        for (size_t i = 1; i < vs.size(); ++i) {
            int y = (i + T * vs[i]) % n;
            if (x != y) {
                bl = false;
                break;
            }
        }
        if (bl) {
            cout << T << ' ' << x << endl;
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}

