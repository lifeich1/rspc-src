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

void shb(int64_t t) {
    int64_t k =  int64_t(1)<<(64-__builtin_clzll(t)-1);
    for (; k > 0; k >>= 1)
        cout << (k&t?1:0);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int64_t n; int Q; cin>>n>>Q;
        while (Q--) {
            int64_t l,r;cin>>l>>r;
            int64_t ans = 0;
            for (auto t = l; t <= r; ++t) {
                int64_t u = n|t, v = 0;
                for (int64_t s = 1; s <= n; ++s) {
                    auto x = s ^ t;
                    u = min(u, x);
                    v = max(v, x);
                }
                if (v-u == n-1) {
                    TRACELN(cout<<' '<<t<<' '; shb(t));
                    ++ans;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

