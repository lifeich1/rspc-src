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

const int N2 = 4000;
std::vector<int> prs;
int pr[N2];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    for (int i = 2; i < N2; ++i)
        if (!pr[i]) {
            prs.push_back(i);
            for (int k = i * 2; k < N2; k += i) pr[k] = 1;
        }
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        map<int,int> mm;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            for (auto p : prs) {
                while (x % p == 0) {
                    x /= p;
                    mm[p]++;
                }
            }
            if (x > 1) mm[x]++;
        }
        int ans = 0, c3 = 0;
        for (auto & [k, v] : mm) {
            ans += v >> 1;
            c3 += v & 1;
        }
        ans += c3 / 3;
        cout << ans << endl;
    }
    return 0;
}

