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

    int tt; cin >> tt; while (tt--) {
        int q; cin >> q;
        int64_t l = 0, r = -1;
        auto day = [](int64_t h, int64_t a, int64_t b) -> int64_t {
            if (a >= h) return 1;
            return (h - a - 1) / (a - b) + 2;
        };
        auto rv = [&](int64_t d, int64_t a, int64_t b) -> bool {
            auto t1 = (d - 2) * (a - b) + a + 1;
            if (1 == d) t1 = 1;
            auto t2 = (d - 1) * (a - b) + a;
            if (l <= t2 && (r >= t1 || -1 == r)) {
                l = max(l, t1), r = min(t2, r < 0 ? t2 : r);
                return true;
            } else return false;
        };
        int ty; int64_t a, b, n;
        while (q--) {
            cin >> ty;
            if (1 == ty) {
                cin >> a >> b >> n;
                cout << (rv(n, a, b) ? 1 : 0) << ' ';
                TRACE(cout << '(' << l << ' ' << r << ')');
            } else {
                cin >> a >> b;
                if (r < 0) { cout << "-1\n"; continue; }
                const auto t = day(l, a, b);
                const auto t1 = day(r, a, b);
                cout << (t == t1 ? t : -1) << ' ';
                TRACE(cout << '(' << t << ' ' << t1 << ')');
            }
        }
        cout << endl;
    }
    return 0;
}

