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

int f[505][505];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,m; cin >>n>>m;
    vector<string> c;
    copy_n( std::istream_iterator<std::string>(std::cin),n, std::back_inserter(c));
    map<char,char> kk;
    kk['s'] = 'n';
    kk['n'] = 'u';
    kk['u'] = 'k';
    kk['k'] = 'e';
    kk['e'] = 's';
    vector<pair<int,int>> ls;
    ls.emplace_back(0, 0);
    f[0][0] = 1;
    if (c[0][0] != 's') {
        cout<<"No\n";
        return 0;
    }
    for (int i = 0; i < ls.size() ;++i) {
        auto [x, y] = ls[i];
        auto ok = [&](char c, char nx) {
            return nx == kk[c];
        };
        auto ta = [&](char ch, int i, int j) {
            if (i < 0 || j < 0 || i >= n || j >= m) return;
            if (f[i][j] || !ok(ch, c[i][j])) return;
            ls.emplace_back(i,j);
            f[i][j] = 1;
        };
        char ch = c[x][y];
        ta(ch, x+1,y);
        ta(ch, x-1,y);
        ta(ch, x,y+1);
        ta(ch, x,y-1);
    }
    cout<<(f[n-1][m-1]?"Yes\n":"No\n");
    return 0;
}

