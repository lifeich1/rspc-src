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

const int N = 101001;
int l[N],r[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n, m; cin >>n>>m;
        int lr = m, rl = 0, sl = m;
        for (int i = 0; i < n; ++i) {
            cin >>l[i]>>r[i];
            sl = min(sl, r[i]-l[i]+1);
            lr = min(lr, r[i]);
            rl = max(rl, l[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int t = sl;
            t = min(t, max(lr+1, l[i]) - l[i]);
            t = min(t, r[i] - max(r[i], rl-1));
            ans = max(ans, r[i]-l[i]+1-t);
        }
        cout<<ans*2<<endl;
    }
    return 0;
}

