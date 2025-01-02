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

const int N = 401001;
char s[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        cin >> s;
        int n = strlen(s);
        for (int i = 0, j = n; i < n; ++i, ++j) s[j] = s[i];
        int ml = 0;
        n *= 2;
        for (int i = 0, l = 0; i < n - 1; ++i)
            if (s[i] == '1') {
                ++l;
                if (l > ml) ml = l;
            } else l = 0;
        n /= 2;
        //if (ml > n) ml = n;
        if (ml == 1) {
            cout << "1\n"; continue;
        }
        ++ml;
        int64_t a = ml / 2;
        a *= ml - a;
        cout << a << endl;
    }
    return 0;
}

