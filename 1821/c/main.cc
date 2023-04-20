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
char a[N];
int f[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    int m = 0;
    f[0] = 0;

    int tt; cin >> tt; while (tt--) {
        cin >> a;
        int n = strlen(a);
        while (m < n) {
            ++m;
            f[m] = f[m - ((m + 1) / 2)] + 1;
        }
        vector<int> ca, m0; ca.resize(26, -1), m0.resize(26, 0);
        fill(ca.begin(), ca.end(), 0);
        fill(m0.begin(), m0.end(), 0);
        for (int i = 0; i < n; ++i) {
            int x = a[i] - 'a';
            int l = i - ca[x];
            m0[x] = max(m0[x], l);
            ca[x] = i + 1;
        }
        TRACELN(for (int i = 0; i < 26; ++i) cout << char('a'+i) << m0[i] << ' ';);
        for (int i = 0; i < 26; ++i) {
            int l = n - ca[i];
            m0[i] = max(m0[i], l);
        }
        TRACELN(for (int i = 0; i < 26; ++i) cout << char('a'+i) << m0[i] << ' ';);
        int t = *min_element(m0.begin(), m0.end());
        cout << f[t] << endl;
    }
    return 0;
}

