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

const int N = 201001;
int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >>n;
        int p1, p2;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            a[x] = i;
        }
        p1 = min(a[1], a[2]);
        p2 = max(a[1], a[2]);
        int l,r;r = l = a[n];
        if (a[n] < p1) {
            r = p1;
        } else if (a[n] > p2) {
            r = p2;
        }

        cout<<l<<' '<<r<<endl;

    }
    return 0;
}

