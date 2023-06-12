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

bool ispa(int x) {
    int y = 0;
    for (int t = x; t > 0; t /= 10 ) y = y * 10 + t % 10;
    return x == y;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    vector<int> ps;
    for (int t = (1<<15)-1; t>=0; --t) {
        if (ispa(t)) ps .emplace_back (t);
    }
    TRACELN(cout<<ispa(22));
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        unordered_map<int,int> c;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            c[x]++;
        }
        int64_t ans = 0;
        for (auto [k,v] : c) {
            for (auto p : ps) {
                auto j = p ^ k;
                if (j >= k || c.count(j) == 0) continue;
                int64_t t = v;
                t *= c[j];
                ans += t;
                TRACELN(cout<<' '<<j<<' '<<k<<' '<<t<<" :"<<ans);
            }
            int64_t t = v;
            t *= (1 +t);
            ans += t / 2;
        }
        cout<<ans<<endl;
    }
    return 0;
}

