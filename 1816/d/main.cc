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

const int N = 1010;
int n;

#if defined(RSPC_TRACE_HINT)
int a[N], c[N][N];
#endif

void lclinit() {
#if defined(RSPC_TRACE_HINT)
    a[1] = 1;
    for (int i = 2; i <=n;++i) {
        int t = (rand() % n) + 1;
        a[i ] = i;
        if (t < i) swap(a[i], a[t]);
    }
    for (int i = 1; i <= n;++i)
        fill(c[i], c[i]+n+1,0);
#else
        cin >> n;
#endif
}

void op1(int x) {
#if defined(RSPC_TRACE_HINT)
    for (int i = 1; i <= n; ++i)
    {
        auto j = x - i;
        if (j >= 1 && j <= n) c[i][j] = 1;
    }
#else
    cout<<"+ " << x<<endl;cout.flush();
#endif
}

int op2(int x, int y) {
#if defined(RSPC_TRACE_HINT)
    map<int,int> f;
    f[x] = 0;
    vector<int> l = {x};
    for (int i = 0; i < l.size(); ++i) {
        int p = l[i];
        int v = f[p]+1;
        for (int t = 1; t <= n; ++t) if (c[p][t]) {
            if (t == y) return v;
            if (f.find(t) != f.end()) continue;
            f[t] = v;
            l.emplace_back(t);
        }
    }
    return -1;
#else
    cout<<"? " << x<<' '<<y<<endl;cout.flush();
    int r;
    cin >> r;
    if (r == -2) exit(0);
    return r;
#endif
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        lclinit();
        // TODO
    }
    return 0;
}

