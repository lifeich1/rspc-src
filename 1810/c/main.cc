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
int cnt[N], bg[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; int64_t C, D, must = 0;
        cin >> n >> C >> D;
        fill(cnt, cnt + n + 1, 0);
        int bb = 0;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            if (x <= n) cnt[x]++;
            else bg[bb++] = x;
        }
        sort(bg, bg + bb);
        must = C * n;
        int64_t ans = C * n + D;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i]) must -= C;
            else must += D;
            if (ans > must) ans = must;
        }
        for (int l = n, i = 0; i < bb; ++i) {
            if (l == bg[i]) continue;
            must -= C;
            must += D * (bg[i] - l - 1);
            l = bg[i];
            if (ans > must) ans = must;
        }
        cout << ans << endl;
    }
    return 0;
}

