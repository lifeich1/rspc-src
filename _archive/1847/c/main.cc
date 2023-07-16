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

int s[8][128];

int fg = 0;
void ins(int x) {
    for (int i = 7; i >= 0; --i, x >>= 1)
        s[i][x] = fg;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif


    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        ++fg;
        ins(0);
        int l = 0;
        int ans = 0;
        for (int i = 0; i < n;++i) {
            int x; cin>>x; l ^= x;
            ins(l);
            int p = 0;
            for (int i = 0; i < 8; ++i) {
                int b = (l >> (7-i))&1;
                p <<= 1;
                p |= b ^ 1;
                if (s[i][p] != fg) p ^= 1;
            }
            ans = max(ans, p ^ l);
        }
        cout<<ans<<endl;
    }
    return 0;
}

