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

const int N = 51001;
int n[N], u[N], a[N], p[N], ans[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        const int K = tt + 128;
        int m; cin >> m;
        int mn = 0;
        for (int i = 0; i < m; ++i) {
            cin >> n[i];
            copy_n(std::istream_iterator<int> (cin), n[i], a + mn);
            p[i] = mn;
            mn += n[i];
        }
        bool ok = true;
        for (int i = m - 1; i >= 0; --i) {
            auto & s = (ans[i] = -1);
            for_each(a + p[i], a + p[i] + n[i], [&](int x) {
                        if (K != u[x]) {
                            u[s = x] = K;
                        }
                    });
            if (s < 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            copy_n(ans, m, std::ostream_iterator<int> (cout, " "));
            cout << endl;
        } else cout << "-1\n";
        fill(u, u + mn, 0);
    }
    return 0;
}

