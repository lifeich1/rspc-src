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

    int n,q;cin>>n>>q;
    if (n & 1) {
        while(q--) cout << "NO\n";
        return 0;
    }
    string s;
    cin >> s;
    const char r[] = ")(";
    set<int> a;
    vector<int> fl(n,0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == r[i&1]) a.emplace(i);
    }
    while(q--) {
        int x;
        cin >> x;
        --x;
        auto it = a.find(x);
        if (it != a.end()) a.erase(it);
        fl[x] ^= 1;
        if (s[x] == r[x&1^fl[x]]) a.emplace(x);
        TRACELN(copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " ")));
        if (a.size() && ((*a.begin() & 1) == 0 || (*a.rbegin() & 1) == 1)) {
            cout<<"NO\n";
        } else cout<<"YES\n";
    }
    return 0;
}

