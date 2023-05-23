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

int c[4][4];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin >> n;
    vector<int> a(n, 0);
    copy_n(std::istream_iterator<int>(std::cin),n,a.begin());
    vector<int> b{a};
    sort(b.begin(), b.end());
    int ans = n;

    for (int i = 0; i < n; ++i) {
        c[a[i]-1][b[i]-1]++;
    }
    auto dd = [&](vector<int*>& v) {
        int t = n;
        for (auto p : v) t = min(t, *p);
        for (auto p : v) *p -= t;
        ans -= t;
    };
    for (int l = 1; l <= 4;++l) {
        int p[] = {0, 1, 2, 3};
        do {
            vector<int*> v;
            for (int i = 0; i < l; ++i) v.push_back(&c[p[i]][p[(i+1)%l]]);
            dd(v);
        } while(next_permutation(p,p+4));
    }
#if defined(RSPC_TRACE_HINT)
    for (int i = 0; i < 4; ++i)
        copy_n(c[i],4, std::ostream_iterator<int>(std::cout, " ")),cout<<endl;
#endif
    cout<<ans<<endl;
    return 0;
}

