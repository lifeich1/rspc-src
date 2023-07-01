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
int r[N][3];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin >>n;
    vector<int> a;copy_n(std::istream_iterator<int>(std::cin),n, std::back_inserter(a));
    string s; cin >>s;
    int64_t ans = 0;
    for (int i = n-1; i >= 0; --i) {
        copy_n(r[i+1],3, r[i]);
        if (s[i] == 'X') r[i][a[i]]++;
    }
    auto mex = [&](int i,int j, int k) {
        int a[3] = {i,j,k};
        sort(a,a+3);
        int l = unique(a,a+3)-a;
        for (int i = 0; i < l; ++i)
            if (a[i] != i) return i;
        return l;
    };
    int c[3] = {0,0,0};
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'M') {
            c[a[i]]++;
        } else if (s[i] == 'E') {
            for (int u = 0; u < 3; ++u)
                for (int v = 0; v < 3; ++v) {
                    int64_t e = mex(u,v,a[i]);
                    e *= c[u];
                    e *= r[i][v];
                    ans += e;
                }
        }
    }
    cout<<ans<<endl;
    return 0;
}

