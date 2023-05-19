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
int a[N], u[N], b[N];
int ll,rr;

void dfs(int x, int fa, int fa2, int r) {
    if (r != fa2 && x == r && u[r]==1) ++ll,++u[r];
    if (u[x]) return;
    u[x] =1;
    dfs(a[x], x, fa, r);
    if (b[x]) dfs(b[x], x,fa,  r);
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
        fill(u, u + n+1, 0);
        fill(b, b + n+1, 0);
        copy_n(std::istream_iterator<int>(std::cin) ,n,a+1);
        for (int i=1;i<=n;++i) if (a[a[i]] != i) b[a[i]] = i;
        ll=rr=0;
        for (int i = 1 ;i<=n;++i) {
            if (u[i]) continue;
            dfs(i, i, i, i);
            ++rr;
        }
        cout<< ll+(rr>ll?1:0)<<' '<<rr<<endl;
    }
    return 0;
}

