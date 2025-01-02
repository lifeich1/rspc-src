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

    int n; string s; cin >> n >> s;
    bool lk = false;
    int a = -1, k = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o') ++k;
        else {
            a = max(a, k);
            lk = true;k = 0;
        }
        TRACE(cout << ' ' << k);
    }
    TRACELN();
    if (lk) a = max(a, k);
    if (a == 0) a = -1;
    cout << a << endl;
    return 0;
}

