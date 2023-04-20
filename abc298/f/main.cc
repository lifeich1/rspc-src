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
int r[N], c[N], x[N];
map<int,int64_t> rs, cs;
pair<int,int> sbr[N];
multiset<int64_t> scs;

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {cin >> r[i]>>c[i]>>x[i];
        rs[r[i]]+=x[i];
        cs[c[i]]+=x[i];
        sbr[i] = {r[i], i};
    }
    for (auto&[c, s] : cs) {
        scs.insert(s);
    }
    sort(sbr, sbr +n);
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && sbr[i].first==sbr[i-1].first) continue;
        auto rr = sbr[i].first;
        int64_t ts = 0;
        for (int k = i; k<n&&sbr[k].first==rr;++k) {
            auto ii =sbr[k].second;
            auto s = cs[c[ii]];
            scs.erase(scs.find(s));
            s=(cs[c[ii]]-=x[ii]);
            scs.insert(s);
            ts += x[ii];
        } 
        ans = max(ans, ts + *scs.rbegin());
        for (int k = i; k<n&&sbr[k].first==rr;++k) {
            auto ii =sbr[k].second;
            auto s = cs[c[ii]];
            scs.erase(scs.find(s));
            s=(cs[c[ii]]+=x[ii]);
            scs.insert(s);
        } 

    }
    cout << ans << endl;
    return 0;
}

