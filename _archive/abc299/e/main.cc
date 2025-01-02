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

const int N = 2010;
vector<int> e[N];
int u[N], uu[N], u1[N], P[N], D[N];
int n, K, m;

void bfs(int st, int D, bool chk = false) {
    vector<int> l1, l2;
    l1.push_back(st);
    fill(u, u + n + 2, 0);
    u[st] = 1;
    for (int dd = 0; l1.size() && (dd <= D || !chk); ++dd) {
        if (dd >= D) for_each(l1.begin(), l1.end(), [&](int x) { ++uu[x]; });
        l2.clear();
        for (auto x : l1) {
            for (auto y : e[x]) {
                if (u[y]) continue;
                l2.push_back(y);
                u[y] = 1;
            }
        }
        l1.swap(l2);
    }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

      cin >> n >> m;
    for (int i = 0, x, y; i < m; ++i) {
        cin  >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    cin >> K;
    for (int i = 0, p, d; i < K; ++i) {
        cin >> p >> d;
        bfs(p, d);
        P[i] = p, D[i] = d;
    }
    fill(u1, u1 + n + 2, 0);
    bool ok = false;
    for (int i = 1; i <= n; ++i) {
        if (uu[i] == K) u1[i] = 1, ok = true;
    }
    for (int i = 0; i < K; ++i) {
        fill(uu, uu + n + 2, 0);
        bfs(P[i], D[i], true);
        bool b = false;
        for (int j = 1; j <= n; ++j)
            if (uu[j] && u1[j]) {
                b = true; break;
            }
        if (!b) ok = false;
    }
    TRACELN(copy_n(uu + 1, n, std::ostream_iterator<int> (cout, " ")));
    if (ok) {
        cout << "Yes\n";
        copy(u1 + 1, u1 + n + 1, std::ostream_iterator<int> (cout , ""));
        cout << endl;
    } else cout << "No\n";
    return 0;
}

