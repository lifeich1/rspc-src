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
int p[N],q[N],a[N],b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int W,H,n;cin>>W>>H>>n;
    for (int i = 0; i <n;++i) cin >>p[i]>>q[i];
    int A,B;
    cin>>A;
    copy_n(std::istream_iterator<int>(std::cin),A, a);
    cin>>B;
    copy_n(std::istream_iterator<int>(std::cin),B, b);
    map<pair<int,int>,int> m;
    for (int i = 0; i < n;++i) {
        int x = upper_bound(a,a+A,p[i])-a;
        int y = upper_bound(b,b+B,q[i])-b;
        TRACELN(cout<< p[i]<<' '<<q[i]<<' '<<x<<' '<<y);
        m[pair<int,int>(x,y)]++;
    }
    int mi, mx;
    mi = mx = m.begin()->second;
    if (m.size() != int64_t(A+1)*(B+1)) {
        TRACELN();
        mi = 0;
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        auto v = it->second;
        if (v < mi) mi = v;
        if (v > mx) mx = v;
    }
    cout<<mi<<' '<<mx<<endl;
    return 0;
}

