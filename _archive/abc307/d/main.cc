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

    int n; string s; cin >> n>>s;
    vector<int> lh(n, 0), rh(n, 0);
    for (int i = 0, t = 0; i < n; ++i) {
        if (s[i] == ')') {
            lh[i] = t;
            if (t > 0) --t;
        } else if (s[i] == '(') {
            lh[i] = ++t;
        } else lh [i] = t;
    }
    for (int i = n-1, t = 0; i >= 0; --i) {
        if(s[i] == '(') {
            rh[i] = t;
            if (t>0) --t;
        } else if (s[i] == ')') {
            rh[i] = ++t;
        } else rh[i] = t;
    }
    //TRACELN(cout<<s);
    //TRACELN(copy(lh.begin(),lh.end(), std::ostream_iterator<int>(std::cout, " ")));
    //TRACELN(copy(rh.begin(),rh.end(), std::ostream_iterator<int>(std::cout, " ")));
    for (int i = 0; i < n; ++i)
        if (min(lh[i], rh[i]) == 0) cout<<s[i];
    cout<<endl;
    return 0;
}

