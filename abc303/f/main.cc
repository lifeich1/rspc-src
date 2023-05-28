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

    int n; int64_t H; cin >> n>>H;
    vector<pair<int64_t,int64_t>> s;s.reserve(n);
    for (int i = 0; i<n;++i) {
        int64_t t,d;
        cin >> t>>d;
        s.emplace_back(d, t);
    }
    sort(s.begin(), s.end());
    vector<tuple<int64_t,int64_t,int64_t>> u;
    {
        auto [d,t] = s.back();
        u.emplace_back(d,t,0);
    }
    auto ti = [&](auto pp) {
        int64_t d = pp.first, t = pp.second;
        auto [d0, t0, a0] = u.back();
        if (t <= t0) return;
        if (t * d <= t0 * d0) return;
        int64_t a = t0 * d0 / d + 1;
        u.emplace_back(d,t,a);
    };
    for_each(s.rbegin(), s.rend(), ti);
    int64_t tt = 0, now = 0;
    int i = 0;
    for (;now <= H && i < u.size();++i) {
        auto [d,t,a] = u[i];
        TRACELN(cout<<"#"<<d<<' '<<t<<' '<<a<<' '<<now<<' '<<tt);
        int64_t nt = t - 1;
        if (tt < nt) {
            auto tb = H - now;
            tb = (tb - 1) / d + 1;
            auto tmp = (nt - tt) * (nt + tt + 1) / 2 * d;
            if (2 * (tb - 1) / (nt - tt) + 1 <= (nt + tt + 1)) {
                auto ca = [&](int64_t q) {
                    return (q - tt) * (q + tt + 1) / 2;
                };
                int64_t l,r;
                auto lm = (H - now - 1) / d + 1;
                for (l = tt + 1, r = nt; l < r; ) {
                    auto m = (l + r) / 2;
                    if (ca(m) < lm) l = m + 1;
                    else r = m;
                }
                tt = l;
                break;
            } else now += tmp;
            tt = nt;
        }
        if (now >= H) break;
        nt = (i+1<u.size() ? get<2>(u[i+1])-1 : H);
        if (tt < nt) {
            auto qt = (H - now - 1) / (d * t) + 1;
            if (qt + tt <= nt) {
                tt += qt; break;
            } else {
                now += (nt - tt) * d * t;
            }
            tt = nt;
        }
    }
    cout<<tt<<endl;
    return 0;
}

