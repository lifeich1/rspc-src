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
char a[N], b[N];

int di(int n) {
    int ret = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i]) ++ret;
    return ret;
}
int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n >> a>>b;
        int r1 = di(n); // 1, 4
        if (r1 == 0) {
            cout<<"0\n";continue;
        }
        reverse(b, b + n);
        int r2 = di(n); // 2, 3
        r1 = r1 * 2 - 1;
        r2 = max(r2 * 2 - 1, 0);
        while(r1%4 != 1 && r1 %4 != 0) ++r1;
        while(r2%4 != 2 && r2 %4 != 3) ++r2;
        cout<<min(r1, r2)<<endl;
    }
    return 0;
}

