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
int c[N], r[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, T; cin >> n >> T;
    copy_n(std::istream_iterator<int> (cin), n, c);
    copy_n(std::istream_iterator<int> (cin), n, r);
    int a1, r1, at, rt;
    a1 = at = 1; r1 = rt = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] == T && r[i] > rt) {
            rt = r[i], at = i;
        }
        if (c[i] == c[0] && r[i] > r1) {
            r1 = r[i], a1 = i;
        }
    }
++a1, ++at;
    if (rt) cout << at; else cout << a1;
    cout << endl;
    return 0;
}

