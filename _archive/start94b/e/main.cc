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

const int N = 1001001;
int a[N];
int64_t s[N];
int rc[N],cc[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n,m; cin >> n>>m;
        copy_n(std::istream_iterator<int>(std::cin),n*m, a);
        fill(s,s+n*m, 0);
        for (int K = (1<<29); K > 0; K>>=1) {
            int c1 = 0;
            fill(rc,rc+n, 0);
            fill(cc,cc+m,0);
            for (int i = 0, p = 0; i < n; ++i)
                for (int j = 0; j < m; ++j,++p)  {
                    if (a[p] & K) {
                        ++c1;
                        rc[i]++;
                        cc[j]++;
                    }
                }
            for (int i = 0, p = 0; i < n; ++i)
                for (int j = 0; j < m; ++j,++p)  {
                    if (a[p]&K) {
                        int t = n*m-c1;
                        t -= n - cc[j];
                        t -= m - rc[i];
                        s[p] += int64_t(K) * t;
                    } else {
                        int t = c1 - cc[j] - rc[i];
                        s[p] += int64_t(K) * t;
                    }
                }
        }
        cout<<*max_element(s,s+n*m)<<endl;
    }
    return 0;
}

