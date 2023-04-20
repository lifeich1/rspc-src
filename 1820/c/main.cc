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
int a[N];

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
        map<int,int> cnt;
        for_each(a, a + n, [&](int v) { cnt[v]++; });
        int mex = 0;
        for (const auto & [v, c] : cnt) {
            if (v != mex || 0 == c) break;
            mex = v + 1;
        }
        bool ans = false;
        for (int i = 0, j = 0, d = 0; i < n; ++i) {
            while ((cnt[mex+1] > 0 || i >= j) && j < n) {
                TRACELN(cout<<"-- "<< i<<' ' <<j);
                int v = a[j++];
                if (cnt[v]-- == 1 && v < mex) ++d;
            }
            if (cnt[mex+1] > 0) break;
            if (0 == d) {
                TRACELN(cout<<'.'<< i<<' ' <<j);
                ans = true; break;
            }
            if (1 == ++cnt[a[i]] && a[i] < mex) --d;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}

