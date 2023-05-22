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

const int N = 301001;

string tra(string_view s) {
    int n = s.length();
    string o;
        int k = 0;
        for (int i = 0; i < n - 1; ++i)
            if (s[i] == 'a') o+= s[i+1];
        for (int i = 0; i < n - 1; ++i)
            if (s[i] == 'b') o+= s[i+1];
        return o;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    string s;
    int tt; cin >> tt; while (tt--) {
        cin >> s; int n = s.length();
        cout<<s;
        while (--n) {
            auto o = tra(s);
            cout<<' '<<o;
            s =  o;
        }
        cout<<endl;
    }
    return 0;
}

