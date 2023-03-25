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
int64_t l[N];
int v[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int64_t L, t1;
    int n, m; cin >> L >> n >> m;
    int *pv = v;
    generate_n(l, n + m, [&]() { cin >> *(pv++) >> t1; return t1; });
    int64_t p1, p2, ans;
    p1 = p2 = ans = 0;
    for (int i1 = 0, i2 = n; p1 < L && p2 < L; ) {
        if (v[i1] == v[i2]) {
            auto ll = max(p1, p2);
            auto rr = min(p1 + l[i1], p2 + l[i2]);
            if (ll <= rr) {
                ans += rr - ll;
                TRACELN(cout << '.' << ll << ' ' << rr
                        << ' ' << v[i1] << ' ' << p1 << ' ' << p2
                        << ' ' << ans);
            }
        }
        if (p1 + l[i1] < p2 + l[i2]) {
            p1 += l[i1++];
        } else {
            p2 += l[i2++];
        }
    }
    cout << ans << endl;
    return 0;
}

