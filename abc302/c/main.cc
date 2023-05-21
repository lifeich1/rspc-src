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

int c[9][9];
int f[1024][9];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,m; cin >> n>>m;
    vector<string> ss;
    copy_n(std::istream_iterator<std::string>(std::cin) ,n, std::back_inserter(ss));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j) {
            int t = 0;
            for (int k = 0; k < m; ++k) if (ss[i][k] != ss[j][k]) ++t;
            if (t!=1) continue;
            c[i][j] = c[j][i] = 1;
        }
    TRACELN(for (int i=0;i<n;++i) copy_n(c[i],n, std::ostream_iterator<int>(std::cout, " ")),cout<<endl;);
    int M = (1<<n);
    for (int i = 0; i < n; ++i) f[1<<i][i]=1;
    for (int i = 1; i < M; ++i) 
      for (int li = 0; li < n; ++li) if (f[i][li]){
        for (int j = 0; j < n;++j) if (c[li][j]){
            int mj = 1<<j;
            if (i&mj) continue;
            f[i|mj][j] = 1;
        }
    }
    TRACELN(cout<<f[2][1]);
    TRACELN(cout<<f[6][2]);
    TRACELN(cout<<f[7][0]);
    TRACELN(cout<<f[15][3]);
    cout<<(accumulate(f[M-1],f[M-1]+n,0)?"Yes\n":"No\n");
    return 0;
}

