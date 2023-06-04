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

const int N = 101001;
int a[N],b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        copy_n(std::istream_iterator<int>(std::cin) ,n,a);
        if (a[n-1]) {
            cout<<"NO\n";continue;
        }
        bool ans = true;
        fill(b, b + n, 0);
        for (int i = n-1,j = n-1,fl = 0; i >= 0; --i) {
            while(i >= 0 && a[i] == fl) --i;
            if (i >= 0) b[j--] = i+1;
            fl ^= 1;
        }
        if (ans) {
            cout<<"YES\n";
            copy_n(b,n,std::ostream_iterator<int>(std::cout, " ") );
            cout<<endl;
        }else cout<<"NO\n";
    }
    return 0;
}

