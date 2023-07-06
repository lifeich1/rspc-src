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

    int tt; cin >> tt; while (tt--) {
        int64_t n; int Q; cin >>n>>Q;
        while(n != (n&(-n))) n -= n&(-n);
        n <<= 1;
        //int64_t m = n + (n-1);
        while (Q--) {
            int64_t l,r;cin>>l>>r;
            auto f = [&](int64_t u) -> int64_t {
                return u / n + (u + 1) / n;
            };
            cout<< f(r)-f(l-1)<<endl;
        }
    }
    return 0;
}

