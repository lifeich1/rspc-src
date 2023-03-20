#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
using namespace std;
#define self_todo_placeholder

const int N = 101001;
pair<int,int> c[N+N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m; cin >> n >> m;
    int flag = 1, cnt = 0;
    auto fi = [&]() -> pair<int,int> {
        int x; cin >> x;
        cnt += flag;
        return {x, cnt};
    };
    generate_n(c, n, fi);
    flag = -1, cnt = 0;
    generate_n(c + n, m, fi);
    sort(c, c + n + m);

    for (int i = 0; i < n + m; ++i)
        if (c[i].second > 0) cout << (i + 1) << ' ';
    cout << endl;
    for (int i = 0; i < n + m; ++i)
        if (c[i].second < 0) cout << (i + 1) << ' ';
    cout << endl;

    return 0;
}

