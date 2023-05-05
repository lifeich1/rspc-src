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

const int N = 1000000;
int bp[N];
vector<int> pr;

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int64_t n; cin >> n;
    for (int i = 2; i < N; ++i)
        if (!bp[i]) {
            pr.push_back(i);
            if (i > 1000) continue;
            for (int k = i*2; k < N; k+=i) bp[k]=1;
        }

    int ans = 0;
    for (int i = 0; i < pr.size() - 2; ++i) {
        int p1 = i+1;
        int64_t t = n / pr[i] / pr[i] / pr[i+1];
        int p2 = upper_bound(pr.begin(), pr.end(), t) - pr.begin() - 1;
        t = n/pr[i]/pr[i];
        for (; p1 < p2; ++p1) {
            auto t1 = t / pr[p1];
            while(t1/pr[p2]<pr[p2]&&p1<p2) --p2;
            TRACELN(cout<<pr[i]<<' '<<pr[p1]<<' '<<pr[p2]<<';'<<int64_t(pr[i])*pr[i]*pr[p1]*pr[p2]*pr[p2]<<' '<<int64_t(pr[i])*pr[i]*pr[p1]*pr[p1+1]*pr[p1+1]);
            ans += p2 - p1;
        }
    }
    cout << ans << endl;
    return 0;
}

