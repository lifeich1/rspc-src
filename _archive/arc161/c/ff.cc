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
vector<int> e[N];
string s,sa;

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    ifstream fin("1.out");

    int tt; cin >> tt; while (tt--) {
        string ous; fin>>ous;
        int n; cin >> n;
        for (int i = 0; i <= n; ++i) e[i].clear();
        for (int i = 1; i < n; ++i) {
            int x, y; cin >> x >> y;
            e[x] .emplace_back (y);
            e[y] .emplace_back (x);
        }
        cin >> s;
        sa.resize(n);
        int M = 1<<n;
        int ans = -1;
        for (int mas = 0; mas < M; ++mas) {
            for (int i = 1; i <= n; ++i){
                int t = 0;
                for (int y : e[i]) t += (mas >> (y-1))&1;
                if (t+t < e[i].size()) sa[i-1] = 'W';
                else sa[i-1] = 'B';
            }
            if (sa == s) {
                ans = mas;
                break;
            }
        }
        if (ans < 0) cout<<"-1\n";
        else {
            for (int i = 1; i <= n ; ++i) {
                int t = 0;
                for (int y : e[i]) t += (ous[y-1]=='B');
                if (t+t<e[i].size()) sa[i-1] = 'W';
                else sa[i-1] = 'B';
            }
            if (sa == s) cout << ous<<endl;
            else 
            {
                for (int i = 0; i < n;++i,ans>>=1) sa[i] = (ans&1 ?'B':'W');
                cout<<sa<<endl;
            }
        }
    }
    return 0;
}

