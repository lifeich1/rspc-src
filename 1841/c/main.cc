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

int64_t g[2][10];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    string s;
    int64_t d[] = {1, 10, 100, 1000, 10000};
    const int64_t MI = -d[4]  * 2010010;
    int tt; cin >> tt; while (tt--) {
        cin >> s;
        int64_t *f = g[0], *f0 = g[1];
        fill(f, f+10, MI);
        f[0] = 0;
        int la = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            swap(f, f0);
            fill(f, f+10, MI);
            int v = s[i] - 'A';
            f[max(v, la)] = f0[la] + d[v] * (v < la ? -1 : 1);
            for (int k = 0; k < 5; ++k) {
                if (f0[k+5] < 0) continue;
                f[max(v, k)+5] = max(f[max(v,k)+5],f0[k+5] + d[v] * (v < k ? -1 : 1));
            }
            for (v = 0; v < 5; ++v) {
                f[max(v, la)+5] = max(f[max(v, la)+5], f0[la] + d[v] * (v < la ? -1 : 1));
            }
            la = max(la, s[i]-'A');
        }
        cout<<*max_element(f, f + 10)<<endl;
    }
    return 0;
}

