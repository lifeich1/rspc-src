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

const int N = 128;
char a[N][N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto sh = [&](int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) return false;
        return a[i][j] == '#';
    };
    vector<int> s;s.resize(min(n, m), 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (!sh(i, j)) continue;
            for (int k = 1; k <= n; ++k) {
                auto b= (sh(i+k,j+k))&&sh(i-k,j+k)&&sh(i+k,j-k)&&sh(i-k,j-k);
                if (!b) {
                    if (k > 1) ++s[k-2];
                    break;
                }
            }
        }
    copy(s.begin(), s.end(), std::ostream_iterator<int> (cout, " "));
    cout << endl;
    return 0;
}

