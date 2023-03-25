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
#define TRACE_V(V, END) TRACE(cout << '.' << #V << '=' << (V) << (END);)
using namespace std;
#define self_todo_placeholder

const int N = 101001;
int xs[N], ys[N];
double ts[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m; int64_t K;
    cin >> n >> m >> K;
    for (int i = 0; i < n + m; ++i) {
        cin >> xs[i] >> ys[i];
    }
    // water : sugar
    double l = *max_element(xs, xs + n + m);
    l = 1.0 / l;
    double r = *max_element(ys, ys + n + m);
#if defined(RSPC_TRACE_BTIME)
    const int II = 10;
#else
    const int II = 100;
#endif
    for (int ii = 0; ii < II; ++ii) {
        double d = (l + r) * 0.5;
        transform(xs, xs + n + m, ys, ts,
                [&](int x, int y) -> double { return y - d * x; });
        sort(ts, ts + n);
        auto c = accumulate(ts + n, ts + n + m, int64_t(0),
                [&](int64_t s, double o) -> int64_t { return s + (upper_bound(ts, ts + n, -o) - ts); });
        if (c >= K) r = d;
        else l = d;
        TRACE_V(l, ' ');
        TRACE_V(r, ' ');
        TRACE_V(c, endl);
    }
    cout << setprecision(12) << (100.0 / (1 + l)) << endl;

    return 0;
}

