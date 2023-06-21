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

    string s;
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n>>s;
        int c4,c0,cs; c4 = c0 = cs = 0;
        for (char c : s) {
            if (c == '4') ++c4;
            else if ('0' == c) ++c0;
            else ++cs;
        }
        int t0 = 0, t4 = 0, ts = 0;
        const int M = 1000000007;
        if (s[0] == '4') ++ t4;
        else if (s[0] == '0') ++t0;
        else ++ts;
        int64_t a = 0;
        int m0,m1,m2;
        if (cs >= 2) {
            m0 = 1;
            for (int i = 0; i < cs - 2; ++i) m0 = (m0 + m0) % M;
            m2 = m0;
            m1 = (m2 + m2) % M;
            m0 = (m1 + m1) % M;
        } else if (1 == cs) {
            m1 = m2 = 1;
            m0 = 2;
        } else m0 = m1 = m2 = 1;
        auto up = [&](int l, int r, int m, int o) {
            int64_t t = l;
            t = (t * r) % M;
            t = (t * m) % M;
            t = (t * o) % M;
            a = (a + t) % M;
        };
        TRACELN(cout<<'='<<m2<<' '<<m1<<' '<<m0);
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == '4') {
                ++t4;
                continue;
            }
            int r4 = c4 - t4, rs = cs - ts;
            int o = 1;
            if (s[i] == '*') --rs, o = (M+1)/2;
            up(t4, r4, m0,o);
            up(t4, rs, m1,o);
            up(ts, r4, m1,o);
            up(ts, rs, m2,o);

            TRACE(cout<<' '<<a<<'('<<t4<<','<<ts<<','<<r4<<','<<rs<<')');
            if (s[i] == '*') ++ts;
            else ++t0;
        }
        TRACELN();
        cout<<a<<endl;
    }
    return 0;
}

