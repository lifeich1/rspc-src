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

    int yn[256];
    fill(yn, yn+256, 0);
    yn['a'] = yn['e'] = yn['i'] = yn['o'] = yn['u'] = 1;
    int tt; cin >> tt; while (tt--) {
        const int M = 1000000007;
        int n, K; cin >> n>>K;
        int64_t a = 1;
        for (int i = 0, c = 0, lc = 0; i < n; ++i) {
            char ch; cin >> ch;
            if (yn[int(ch)]) {
                ++c;
                if (c > K) {
                    a = (a * lc) % M;
                    c = 1;
                } if (c == K) {
                    lc = 1;
                }
            } else {
                if (c == K) {
                    ++lc;
                }
            }
        }
        cout<<a<<endl;
    }
    return 0;
}

