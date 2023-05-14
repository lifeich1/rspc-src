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
        int64_t ans = 0;
        copy_n(std::istream_iterator<int>(std::cin) , n, a);
        for (int i = 0; i < n; ++i) {
            copy(a+i,a+n,b+i);
            int ll = 0;
            vector<pair<int,int>> ls;
            for (int j = i+1; j < n; ++j) {
                int t = j;
                int tl = n, tr;
                while (t > i&&b[t]<b[t-1]) swap(b[t], b[t-1]), tl = min(tl, t-1), --t, tr = j;
                while(ls.size()) {
                    auto [l, r] = ls.back();
                    if (tl <= r) {
                        ls.pop_back();
                        ll -= r-l;
                        tl = min(l, tl);
                    } else break;
                }
                if (tl < n) {
                    ls.emplace_back(tl, tr);
                    ll += tr-tl;
                }
                ans += ll;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

