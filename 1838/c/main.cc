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

    int tt; cin >> tt; while (tt--) {
        int n,m; cin>>n>>m;
        bool bl = false;
        for (int i = 2; i < m; ++i)
            if (m % i == 0) {bl = true;
                break;}
        if (bl) {
            int t = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout <<++t<<' ';
                }
                cout<<endl;
            }
        } else {
            for (int i = (n-1) - ((n-1) & 1); i >= 0; i -= 2) {
                int t = i * m;
                for (int j = 0; j < m; ++j) {
                    cout <<++t<<' ';
                }
                cout<<endl;
            }
            for (int i = (n - 1) - (n%2); i >=0; i -= 2) {
                int t = i * m;
                for (int j = 0; j < m; ++j) {
                    cout <<++t<<' ';
                }
                cout<<endl;
            }
        }
    }
    return 0;
}

