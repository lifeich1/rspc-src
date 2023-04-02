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

const int N = 101001;
array<char, N> s;

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        cin >> s.data();
        char mi = *min_element(s.begin(), s.begin() + n);
        auto it = find(s.rend() - n, s.rend(), mi);
        for (auto nx = it+1; nx != s.rend(); ++nx, ++it) *it = *nx;
        s[0] = mi;
        copy_n(s.begin(), n, std::ostream_iterator <char>(cout, ""));
        cout << endl;
    }
    return 0;
}

