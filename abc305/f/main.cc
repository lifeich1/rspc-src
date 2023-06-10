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

const int N = 111;
int f[N][N], u[N];

int n,m;

vector<int>& ge(int x) {
    if (x != 0) cout<< x<< endl<<flush;
    static vector<int> t;
    if (x == n) return t;
    int n;
    cin >> n;
    if (n < 0) exit(0);
    t.resize(n); copy_n(std::istream_iterator<int>(std::cin) ,n,t.begin());
    return t;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    cin >>n>>m;
    auto upd = [&](int x, const auto & e) {
        for (int y : e) f[x][y] = f[y][x] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (f[i][j] > f[i][x] + f[x][j])
                    f[i][j] = f[i][x] + f[x][j];
    };
    for (int i = 1; i <= n; ++i)
    {
        fill(f[i], f[i] + n + 1, n*3);
        f[i][i] = 0;
    }
    vector<int> *e = &ge(0);
    upd(1, *e);
    u[1] = 1;
    for (int x = 1; x != n;) {
        int d = n, nx = 1, tg;
        for (int i = 1; i <= n; ++i)
            if (u[i] == 0 && f[x][i] <= d) {
                d = f[x][i];
                tg = i;
            }
        if (f[x][tg] == 1) {
            nx = tg;
        } else {
            for (int y : *e) {
                if (f[y][tg] == d-1) {
                    nx = y;break;
                }
            }
        }
        upd(nx, ge(nx));
        u[nx] = 1;
        x = nx;
    }
    return 0;
}

