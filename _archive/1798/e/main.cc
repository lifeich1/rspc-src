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

const int N = 301001;
int a[N], f0[N], f1[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        copy_n(std::istream_iterator<int> (cin), n, a);
        f1[n] = f0[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            auto t = i + a[i] + 1;
            if (t <= n && f0[t] >= 0) f0[i] = f0[t] + 1;
            else f0[i] = -1;
            f1[i] = max(f1[i + 1], f0[i]);
        }
        for (int i = 0, _n = n - 1; i < _n; ++i) {
            if (f0[i + 1] == a[i]) cout << 0;
            else if (f0[i + 1] > 0 || (f1[i + 1] + 1 >= a[i])){
                cout << 1;
            } else cout << 2;
            cout << ' ';
        }
        cout << endl;
    }
    return 0;
}

