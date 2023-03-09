#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>

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

const int N = 808;
int64_t ps[N][N], mm[N][N], f[N][N], w[N];

struct Ind {
    int x, y, tim;
    Ind() {}
    Ind(int x, int y, int tim)
        : x{x}, y{y}, tim{tim} {}
};
bool operator< (Ind const & a, Ind const & b) {
    return a.tim > b.tim;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt;
    vector<Ind> lis;
    while (tt--) {
        int n, m, P; cin >> n >> m >> P;
        for (int i = 1; i <= n; ++i) {
            cin >> w[i];
            fill(mm[i], mm[i] + n + 2, 0);
            fill(ps[i], ps[i] + n + 2, 0);
            fill(f[i], f[i] + n + 2, -1);
        }
        for (int i = 0, x, y, c; i < m; ++i) {
            cin >> x >> y >> c;
            auto & t = mm[x][y];
            if (0 == t || t > c) t = c;
        }
        ps[1][1] = P;
        f[1][1] = 0;
        lis.resize(0);
        lis.emplace_back(1, 1, 0);
        int ans = -1;
        while (lis.size()) {
            auto ind = lis.front();
            pop_heap(lis.begin(), lis.end());
            lis.pop_back();

            auto x = ind.x;
            auto y = ind.y;
            if (f[x][y] != ind.tim) continue;
            TRACE(cout << '>' << x << ' ' << y << endl);
            for (int i = 1; i <= n; ++i)
                if (mm[x][i] != 0) {
                    auto c = mm[x][i];
                    auto t = f[x][y];
                    auto tp = ps[x][y] - c;
                    if (tp < 0) {
                        auto ta = (-tp - 1) / w[y] + 1;
                        t += ta;
                        tp += ta * w[y];
                    }
                    auto ty = y;
                    if (w[i] > w[y]) ty = i;
                    if (f[i][ty] <= t && f[i][ty] >= 0) continue;
                    f[i][ty] = t;
                    ps[i][ty] = tp;
                    lis.emplace_back(i, ty, t);
                    push_heap(lis.begin(), lis.end());
                    if (n == i && (t < ans || -1 == ans)) {
                        ans = t;
                    }
                    TRACE(cout << i << ' ' << ty << ' ' << t << endl);
                }
        }
        cout << ans << endl;
    }
    return 0;
}

