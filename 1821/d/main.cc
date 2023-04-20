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
int L[N], R[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n, k;
        cin >> n >> k;
        multiset<int> seg;
        copy_n(std::istream_iterator<int> (cin) , n, L);
        copy_n(std::istream_iterator<int> (cin) , n, R);
        int sk = 0;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int l = R[i] - L[i] + 1;
            sk += l;
            seg.insert(l);
            while (sk - *seg.begin() >= k) {
                if (sk >= k) {
                    int t = seg.size() * 2 + (R[i] - (sk - k));
                    if (-1 == ans || t < ans) ans = t;
                }
                sk -= *seg.begin();
                seg.erase(seg.begin());
            }
            if (sk >= k) {
                int t = seg.size() * 2 + (R[i] - (sk - k));
                if (-1 == ans || t < ans) ans = t;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

