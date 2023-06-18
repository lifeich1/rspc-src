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

    int tt; cin >> tt; while (tt--) {
        string sl,sr; cin >> sl>>sr;
        while (sr.length() > sl.length()) sl = "0" + sl;

        int f0[16];
        int *f = f0, *g = f0+8;
        fill(f, f+8, -1);
        f[3] = 0;
        for (int i = 0; i < sl.length();++i) 
        {
            swap(f, g);
            fill(f, f+8, -1);
            for (int l = 0; l < 10; ++l)
                for (int r = 0; r < 10; ++r) {
                    for (int b = 0; b < 8; ++b) {
                        if (g[b] < 0) continue;
                        if ((b & 1) && l < sl[i]-'0') continue;
                        if ((b & 2) && r > sr[i] -'0') continue;
                        if (!(b & 4) && l > r) continue;
                        int t = b;
                        if ((b & 1) && l > sl[i] - '0') t ^= 1;
                        if ((b & 2) && r < sr[i] - '0') t ^= 2;
                        if (!(b & 4) && l < r) t ^= 4;
                        f[t] = max(f[t], g[b] + abs(l - r));
                    }
                }
        }
        cout<<*max_element(f, f + 8)<<endl;
    }
    return 0;
}

