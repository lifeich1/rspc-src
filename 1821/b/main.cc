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
int a[N], b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        copy_n(std::istream_iterator<int> (cin), n, b);
        copy_n(std::istream_iterator<int> (cin), n, a);
        int xl = n, xr = -1;
        for (int i = 0; i < n; ++ i) {
            if (a[i] == b[i]) continue;
            if (xl == n) xl = i;
            xr = i;
        }
        int al = -1, ai = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (j <= xl && xr <= i) {
                int l = i - j;
                if (l > al) al = l, ai = j;
            } 
            if (a[i] > a[i + 1]) j = i + 1;
        }
        ai++;
        cout << ai << ' ' << ai + al << endl;
    }
    return 0;
}

