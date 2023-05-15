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

const int N = 22;
const int M = 1 << 20;
int c[N][N], neib[N], f[M];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) fill(c[i], c[i] + n + 1, 0);
    for (int i = 0; i < n; ++i) c[i][i] = 1, f[1 << i] = 1 << i;
    fill(neib, neib + n, 0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        c[x][y] = c[y][x] = 1;
        neib[x] |= 1 << y;
        neib[y] |= 1 << x;
    }
    const int mm = (1 << n);
    for (int mask = 1; mask < mm; ++mask) {
        if (0 == f[mask]) continue;
        auto cov = mask;
        for (int i = __builtin_ctz(mask); i < n; ++i) {
            const auto p = 1 << i;
            if (p & mask) cov |= neib[i];
            else if (neib[i] & f[mask]) f[p | mask] |= p;
        }
        TRACE(cout << ',' << mask << ' ' << f[mask] << endl);
        if (cov + 1 == mm) {
            auto t = mask;
            vector<int> ring;
            int v = -1;
            const int h = __builtin_ctz(t);
            for (int i = 0; i < n; ++i)
                if ((f[t] & (1 << i)) && c[i][h] && i != h) {
                    v = i; break;
                }
            if (v < 0) continue;
            TRACE(cout << '^' << v << ' ' << t << ' ' << h << endl);
            while (t) {
                ring.emplace_back(v);
                t &= ~(1 << v);
                if (t) {
                    const auto ma = f[t];
                    for (int i = 0; i < n; ++i)
                        if (((1 << i) & ma) && c[i][v] && ((1 << i) == t || i != h)) {
                            v = i; break;
                        }
                    TRACE(cout << '^' << v << ' ' << t << endl);
                } else break;
            }
            TRACE(cout << ".." << c[5][11] << c[11][5] << endl);
            cout << "YES\n";
            vector<int> ans;
            ans.resize(n);
            for (size_t i = 0; i < ring.size() - 1; ++i) ans[ring[i]] = ring[i + 1];
            ans[ring.back()] = ring.front();
            if (ring.size() == 1) ans[ring.front()] = __builtin_ctz(neib[ring.front()]);
            for (int i = 0; i < n; ++i)
                if (0 == ((1 << i) & mask)) ans[i] = __builtin_ctz(neib[i] & mask);
            for (auto & v : ans) v++;
            copy(ans.begin(), ans.end(), std::ostream_iterator<int> (cout, " "));
            cout << endl;
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}

