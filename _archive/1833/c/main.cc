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
int a[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        copy_n(std::istream_iterator<int>(std::cin) ,n,a);
        int mo = *max_element(a, a + n);
        int me = mo;
        for_each(a, a + n, [&](int x){
                if (x & 1) mo = min(mo, x);
                else me = min(me, x);
                });
        bool bl[2] = {true,true};
        for (int i = 0; i < n && bl; ++i) {
            bool tb[2] = {false,false};
            tb[a[i] & 1] |= true;
            if (a[i] > mo) tb[(a[i] - mo) & 1] |= true;
            if (a[i] > me) tb[(a[i] - me) & 1] |= true;
            bl[0] &= tb[0];
            bl[1] &= tb[1];
        }
        cout << (bl[0] || bl[1] ? "YES\n" : "NO\n");
    }
    return 0;
}

