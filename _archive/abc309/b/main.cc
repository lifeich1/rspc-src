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

    int n; vector<string> s; cin>>n;
    for (int i = 0; i < n; ++i) {
        string t;  cin>>t;
        s.emplace_back(t);
    }
    char p0 = s[0][0];
    for (int i = 1; i < n; ++i) {
        s[i-1][0] = s[i][0];
    }
    for (int i = 1; i < n; ++i) {
        s[n-1][i-1] = s[n-1][i];
    }
    for (int i = n-1; i > 0; --i) {
        s[i][n-1] = s[i-1][n-1];
    }
    for (int i = n-1; i > 0; --i) {
        s[0][i] = s[0][i-1];
    }
    s[0][1] = p0;
    copy_n(s.begin(),n, std::ostream_iterator<std::string>(std::cout, "\n"));
    return 0;
}

