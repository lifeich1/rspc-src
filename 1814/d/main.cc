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

const int N = 3101;
int fq[N], d[N];
int64_t h[N];
pair<int64_t,int64_t> ff[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n, K;
        cin >> n >> K;
        copy_n(std::istream_iterator<int> (cin), n, fq);
        copy_n(std::istream_iterator<int> (cin), n, d);
        transform(d, d + n, fq, h, multiplies<int64_t>{});
        sort(fq, fq + n);
        int m = unique(fq, fq + n) - fq;
        sort(h, h + n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            TRACELN(cout<<':'<<h[i]);
            transform(fq, fq + m, ff, [&](int f) -> pair<int64_t,int64_t> {
                    int64_t t = h[i];
                    t -= (t % f);
                    if (0 == t) t += f;
                    return {t, t + f};
                    });
            ff[m] = {h[i], h[i]};
            sort(ff, ff + m + 1);
            int64_t mx = ff[m].first, mi2 = h[i];
            for (int j = 0; j <= m; ++j) {
                auto mi = min(mi2, ff[j].first);
                if (mx - mi <= K) {
                    ans = max(ans, (int)(upper_bound(h, h + n, mx) - h) - i);
                }
                    TRACELN(cout << '.';
                            for (int t = 0; t < j; ++t) cout<<ff[t].second<<' ';
                            for(int t=j; t<=m;++t) cout<<ff[t].first<<' ';
                            cout<<" .. "<<mi<<' '<<mx;);
                mx = max(mx, ff[j].second);
                mi2 = min(mi2, ff[j].second);
                mi = mi2;
                if (j < m && ff[j + 1].first < mi) mi = ff[j + 1].first;
                if (mx - mi <= K) {
                    ans = max(ans, (int)(upper_bound(h, h + n, mx) - h) - i);
                }
                    TRACELN(cout << '.';
                            for (int t = 0; t <= j; ++t) cout<<ff[t].second<<' ';
                            for(int t=j+1; t<=m;++t) cout<<ff[t].first<<' ';
                           cout<<" .. "<<mi<<' '<<mx; );
            }
        }
        cout << n-ans << endl;
    }
    return 0;
}

