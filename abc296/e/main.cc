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
int nx[N], u[N];
int ans = 0;

void dfs(int x) {
    const int y = nx[x];
    if (u[y] != 0) {
        if (u[y] > 0) ans += u[x] - u[y] + 1;
    } else {
        u[y] = u[x] + 1;
        dfs(y);
    }
    u[x] = -1;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin >> n;
    copy_n(std::istream_iterator<int> (cin), n, nx);
    for_each(nx, nx + n, [](int &x) { --x; });
    for (int i = 0; i < n; ++i)
        if (0 == u[i]) {
            u[i] = 1; dfs(i);
        }
    cout << ans << endl;
    return 0;
}

