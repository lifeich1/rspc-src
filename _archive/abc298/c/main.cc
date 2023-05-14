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
set<int> bx_for_v[N];
multiset<int> v_in_bx[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, Q, op, x, y;
    cin >> n >> Q;
    while (Q--) {
        cin >> op;
        if (1 == op) {
            cin >> x >> y;
            bx_for_v[x].insert(y);
            v_in_bx[y].insert(x);
        } else if (2 == op) {
            cin >> y;
            auto & bx = v_in_bx[y];
            copy(bx.begin(), bx.end(), std::ostream_iterator<int> (cout, " "));
            cout <<endl;
        } else {
            cin >> x;
            auto & bx = bx_for_v[x];
            copy(bx.begin(), bx.end(), std::ostream_iterator<int> (cout, " "));
            cout <<endl;
        }
    }
    return 0;
}

