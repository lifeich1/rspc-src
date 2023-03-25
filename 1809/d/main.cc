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

const int N = 301001;
typedef pair<int,int> ans_t;
char a[N];
int s0[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        cin >> a;
        const int n = strlen(a);
        for (int i = 0; i < n; ++i) s0[i + 1] = s0[i] + (a[i] == '0');
        TRACELN(cout << "--";copy_n(s0, n + 1, std::ostream_iterator<int> (cout, " ")));
        ans_t ans{n - 1, 0};
        for (int i = 0; i < n; ++i) {
            const int t = i - s0[i] + s0[n] - s0[i + 1];
            if (i + 1 < n && a[i] > a[i + 1]) {
                ans = min(ans_t(t, -1), ans);
            } else ans = min(ans, ans_t(t, 0));
            //TRACELN(cout << '.' << ans.first << ' ' << ans.second);
        }

        if (ans.first == 0) cout << "0\n";
        else cout << ans.first << setw(12) << right << setfill('0') << (ans.first + ans.second) << endl;
        fill(s0, s0 + n + 1, 0);
    }
    return 0;
}

