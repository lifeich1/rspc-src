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
        int n; cin >> n;
        int l1, l2, l; l2 = -1;
        cin >> l1;
        l = l1;
        cout<<1;
        while(--n > 0) {
            int t; cin >> t;
            if (l2 < 0) {
                if (t < l) {
                    if (t > l1) {
                        cout<<0;
                        continue;
                    }
                    l2 = t;
                }
                l = t;
                cout <<1;
            } else {
                if (l <= t && t<= l1) {
                    cout<<1;
                    l = t;
                } else {
                    cout<<0;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

