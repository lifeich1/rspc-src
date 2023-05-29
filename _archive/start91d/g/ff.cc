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

#if 0
    int tt; cin >> tt; while (tt--) {
        int l,r,ans =0;
        cin >> l >> r;
#else
    for (int l = 1; l < 1000; ++l)
        for (int r = l; r < 1000; ++r) {
            int ans=0;
#endif
        int i0 = r+r+1, i1 = l+l-1;
        for (int i = l+l; i <= r+r; ++i) {
            bool bl = false;
            for (int a = max(l,i-r); a <= r&&a <= i-l; ++a) {
                if ((a^(i-a))==i) {
                    bl = true;
                    if (i0>i) i0=i;
                    if (i1<i) i1=i;
break;
                }
                }
            if (bl) {
                TRACE(cout<<' '<<i);
                ++ans;
            }
        }
        TRACELN();
        cout << ans<<endl;
        if (ans != max(0, i1-i0+1)) {
            cout<<"HERE\n"<<l<<' '<<r<<' '<<i0<<' '<<i1<<endl;
            return 1;
        }
    }
    return 0;
}

