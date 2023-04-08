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

int64_t gcd(int64_t a, int64_t b) 
{
    if (a < b) swap(a, b);
    while (b > 0) {
        a %= b;
        if (a < b) swap(a, b);
    }
    return a;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int64_t a, b, ans = 0;
    cin >> a >> b;
    while (a > 0 && b > 0) {
        ans++;
        auto t = gcd(a, b);
        a -= t, b -= t;
    }
    cout << ans << endl;
    return 0;
}

