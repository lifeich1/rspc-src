#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

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


struct Gold {
    int x, y, t, v;
    Gold() {}
    Gold(int x, int y, int t, int v): x{x}, y{y}, t{t}, v{v} {}

    bool reach(int ox, int oy, int ot) const {
        int64_t l = t - ot;
        l *= l;
        int64_t x2 = x - ox, y2 = y - oy;
        x2 *= x2, y2 *= y2;
        return l >= x2 + y2;
    }

    bool reach(Gold const & a) const {
        return reach(a.x, a.y, a.t);
    }

    bool reach0() const {
        return reach(0, 0, 0);
    }
};
bool operator< (Gold const & a, Gold const & b) {
    return a.t < b.t;
}

int64_t f[5101];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int N;
    vector<Gold> a;
    cin >> N;
    a.reserve(N);
    for (int i = 0, x, y, t, v; i < N; ++i) {
        cin >> x >> y >> t >> v;
        a.emplace_back(x, y, t, v);
    }
    TRACE(cout << "begin calc\n");
    sort(a.begin(), a.end());
    fill(f, f + N, -1);

    TRACE(cout << "begin calc\n");
    for (int i = 0; i < N; ++i) {
        if (!a[i].reach0()) continue;
        int64_t t = 0;
        for (int j = 0; j < i; ++j)
            if (f[j] > t && a[j].reach(a[i])) {
                t = f[j];
            }
        f[i] = t + a[i].v;
    }
    cout << max(static_cast<int64_t>(0), *max_element(f, f + N)) << endl;

    return 0;
}

