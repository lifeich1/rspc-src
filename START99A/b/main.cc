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


int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    vector<int> a;
    int tt; cin >> tt; while (tt--) {
        vector<int> f(9,-1),g(9,-1);
        int n; cin >>n;
        a.clear();
        a.reserve(n);
        copy_n(std::istream_iterator<int>(std::cin),n, std::back_inserter(a));
        for_each(a.begin(),a.end(),[](int&x) { x%=3; });
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                f[((a[0]+a[1]+i+j)%3)*3 + (a[1]+j)%3] = i+j;
            }
        auto upd = [&](int s, int t, int d) {
            int v = g[s] + d;
            if (f[t] < 0 || f[t] > v) f[t] = v;
        };
        for (int i = 2; i < n; ++i) {
            f.swap(g);
            fill(f.begin(),f.end(), -1);
            for (int _p = 0; _p < 9; ++_p) if (g[_p] >= 0) {
                int u = _p / 3, v = _p % 3;
                int t = (3-u) % 3;
                v = (v + t) % 3;
                int d = (t - a[i] + 3) % 3;
                upd(_p, v*3+t, d);
            }
        }
        sort(f.begin(),f.end());
        cout<< *lower_bound(f.begin(),f.end(), 0)<<endl;
    }
    return 0;
}

