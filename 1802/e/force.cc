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

const int N = 201001;
int f[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<int>> alb;
        int mm = 0;
        for (int i = 0; i < n; ++i) {
            alb.emplace_back();
            int l; cin >> l;
            alb.back().reserve(l);
            for (int j = 0, x; j < l; ++j) {
                cin >> x;
                alb.back().emplace_back(x);
            }
            mm = max(mm, *max_element(alb.back().begin(), alb.back().end()));
        }
        for (bool flag = true; flag; ) {
            flag = false;
            for (auto const & v : alb) {
                int mx = 0;
                int cur = 0;
                for (auto x : v) {
                    if (mx < x) {
                        mx = x; ++ cur;
                        int t = 1 + *max_element(f, f + x);
                        if (t > cur) cur = t;
                    }
                }
                if (f[mx] < cur) f[mx] = cur, flag = true;
            }
        }
        cout << *max_element(f, f + mm + 1) << endl;
        fill(f, f+mm+1, 0);
    }
    return 0;
}

