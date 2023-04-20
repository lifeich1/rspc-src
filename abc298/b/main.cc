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

int n;
int a[111][111], b[111][111], c[111][111];

void rotat() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            c[i][j] = a[n-j-1][i];
    for (int i = 0; i < n; ++i)
        copy(c[i], c[i] + n, a[i]);
}
bool chk() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!b[i][j] && a[i][j]) return false;
    return true;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

 cin >> n;
    for (int i = 0; i < n; ++i) copy_n(std::istream_iterator<int> (cin), n, a[i]);
    for (int i = 0; i < n; ++i) copy_n(std::istream_iterator<int> (cin), n, b[i]);
    bool ans = false;
    for (int i = 0; i < 4 && !ans; ++i) {
        ans = chk();
        TRACELN(for (int k = 0; k < n; ++k) TRACELN(copy_n(a[k], n, std::ostream_iterator<int> (cout, " "))););
        rotat();
    }
    cout << (ans ? "Yes\n" : "No\n");
    return 0;
}

