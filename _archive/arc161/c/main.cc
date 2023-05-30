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

const int N = 201001;
vector<int> e[N];
int f[N][2][2]; // i, i_c, fa_c
string s,sa;

void dfs(int r, int fa) {
    for (int y : e[r]) {
        if (fa != y) {
            dfs(y, r);
        }
    }
    auto * g = f[r];
    g[0][0] = g[0][1] = g[1][0] = g[1][1] = 0;
    int m = e[r].size();
    if (s[r-1] == 'B')  // 1
    {
        int t0 = 0, t1 = 0;
        bool b0 = true, b1 = true;
        for (int y : e[r]) if (y != fa){
            if (f[y][1][0])  {
                t0 ++;
            } else if (!f[y][0][0]) {
                b0 = false;
            }
            if (f[y][1][1]) {
                t1++;
            }else if (!f[y][0][1]) {
                b1 = false;
            }
        }
        if (b0) {
            g[0][1] = (t0 +t0+ 2) > m;
            g[0][0] = (t0+t0) > m;
        }
        if (b1) {
            g[1][1] = (t1+t1+2)>m;
            g[1][0] = (t1+t1)>m;
        }
    } else {
        int t0 = 0, t1 = 0;
        bool b0 = true, b1 = true;
        for (int y : e[r]) if(y!= fa){
            if (f[y][0][0]) {
            } else if (f[y][1][0]) {
                ++t0;
            } else b0 = false;
            if (f[y][0][1]) {
            } else if (f[y][1][1]) {
                ++t1;
            } else b1 = false;
        }
        if (b0) {
            g[0][1] = (t0+t0+2) < m;
            g[0][0] = (t0+t0) < m;
        }
        if (b1) {
            g[1][1] = (t1+t1+2) < m;
            g[1][0] = (t1+t1) < m;
        }
    }
    TRACELN(cout<<':'<<r<<' '<<g[0][0]<<g[0][1]<<g[1][0]<<g[1][1]<<' '<<m);
}

void show(int r, int fa, int ic, int fc) {
    sa[r-1] = ic ? 'B' : 'W';
    if (s[r-1] == 'B') {
        for (int y : e[r]) if (y != fa){
            if (f[y][1][ic]) show(y, r, 1, ic);
            else show(y, r, 0, ic);
        }
    } else {
        for (int y : e[r]) if (y != fa){
            if (f[y][0][ic]) show(y, r, 0, ic);
            else show(y, r, 1, ic);
        }
    }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        for (int i = 0; i <= n; ++i) e[i].clear();
        for (int i = 1; i < n; ++i) {
            int x, y; cin >> x >> y;
            e[x] .emplace_back (y);
            e[y] .emplace_back (x);
        }
        cin >> s;
        dfs(1, 1);
        int ax = -1;
        for (int i = 0; i < 2; ++i)
             if (f[1][i][0]) {
                ax = i;
                break;
            }
        if (ax == -1) {
            cout<< "-1\n";
        } else {
            sa.resize(n);
            show(1, 1, ax, 0);
            cout<< sa<<endl;
        }
    }
    return 0;
}

