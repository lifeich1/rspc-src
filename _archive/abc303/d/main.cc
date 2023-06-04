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

    int x,y,z; cin >> x>>y>>z;
    int64_t a0,a1; a0 = 0; a1 = z;
    string s; cin >> s;
    auto f = [&](char c) {
        if (c == 'a')  {
            a0 += x;
            a1 += y;
        } else {
            a0 += y;
            a1 += x;
        }
        a0 = min(a0, a1 + z);
        a1 = min(a1, a0 + z);
    };
    for_each(s.begin(),s.end(),f);
    cout<<min(a0,a1)<<endl;
    return 0;
}

