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
int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) 
    {
        int n; cin >> n;
        int a1 = 0, a2 = 0;
        for (int l = 0, i = 0; i < n; ++i) {
            int t; cin >> t;
            if (t) {
                ++l;
                if (a1 < l) a1 = l;
            } else l = 0;
        }
        for (int l = 0, i = 0; i < n; ++i) {
            int t; cin >> t;
            if (t) {
                ++l;
                if (a2 < l) a2 = l;
            } else l = 0;
        }
        if (a1 == a2) {
            cout<<"Draw\n";
        } else {
            cout << (a1<a2?"Addy\n":"Om\n");
        }
    }
    return 0;
}

