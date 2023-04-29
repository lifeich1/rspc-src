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

const int N = 64;
char a[N][N],b[N][N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) 
            cin >> a[i];
    for (int i = 0; i < n; ++i) 
            cin >> b[i];
    auto chk = [&](int s, int t) {
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if (a[i][j] != b[(i+s)%n][(j+t)%m]) {
                return false;
            }
    return true;
    };

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if (chk(i,j)) {
                TRACELN(cout<<i<<' '<<j);
                cout << "Yes\n"; return 0;
            }
cout << "No\n";
    return 0;
}

