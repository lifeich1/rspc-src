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

const int N = 401001;
int a[N],b[N],h[N];
int mb[N],fb[N],ft = 0;

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        copy_n(std::istream_iterator<int>(std::cin),n,a);
        copy_n(std::istream_iterator<int>(std::cin),n,b);
        for (int i = 0; i<n;++i) h[i]=i;
        sort(h, h+n, [&](int x, int y) { return a[x] < a[y]; });
        int64_t ans = 0;
        auto mg = [&](int x) {
            if (x < 0 || x >= N) return 0;
            if (fb[x] == ft) return mb[x];
            return 0;
        };
        auto ma = [&](int x) {
            if (fb[x] != ft) fb[x] = ft, mb[x] = 1;
            else mb[x]++;
        };
        for (int i = 0; i < n; ) {
            ++ft;
            const int64_t ia = a[h[i]];
            auto s = ia * ia;
            if (s > n + n) break; 
            while(i < n && a[h[i]] == ia) {
                ans += mg(s - b[h[i]]);
                ma(b[h[i++]]);
            }
            for (int j = i; j < n; ++j) {
                int ya = a[h[j]], yb = b[h[j]];
                s = ya * ia;
                if (s > n + n) break;
                int eb = s - yb;
                ans += mg(eb);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

