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


int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    map<int,int> f;
    int tt; cin >> tt; while (tt--) {
        int n, k; cin >> n >> k;
        int tag = n * 1000 + k;
        if (f.count(tag) == 0) {
            int64_t t = 1;
            n = min(n, k);
            while(n--) {
                t = (int64_t(t) * k--) % 1000000007;
            }
            f[tag] = t;
        }
        cout<< f[tag]<<endl;
    }
    return 0;
}

