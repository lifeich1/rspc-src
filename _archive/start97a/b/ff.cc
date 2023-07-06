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

const int N = 5050;
int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n,k; cin >>n>>k;
        a[0] = 1;
        set<int> m;
        for (int i = 1; i < n; ++i) {
            vector<int> v(m.begin(), m.end());
            for (int q = 0; q < 10; ++q)
            {
                bool ok = true;
                if (a[i-1] == q && k == 1) {
                    continue;
                }
                for (auto s : v) {
                    int t = s - i;
                    if (t < 0) continue;
                    if (i - t >= k) {
                        if (a[t] == q) {
                            ok = false;
                            break;
                        }
                    } else break;
                }
                if (ok) {
                    a[i] = q;
                    break;
                }
            }
            for (auto s : v) {
                int t = s - i;
                if (t < 0 || a[t] != a[i]) {
                    m.erase(s);
                }
            }
            m.emplace(i+i);
            if (a[i-1] == a[i]) m.emplace(i+i-1);
        }
        TRACELN(copy_n(a,n, std::ostream_iterator<int>(std::cout, " ")));
        cout<<accumulate(a,a+n,0)<<endl;
    }
    return 0;
}

