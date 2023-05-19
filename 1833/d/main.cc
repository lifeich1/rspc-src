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

const int N = 2010;
int a[N];

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
        int r = max_element(a + 1, a + n) - a - 1;
        int l = r;
        if (r ==n-2 && a[0] > a[max(n-2,0)]) {
            l = n-1,r=n-1;
        } else {
            while (l > 0 && a[l - 1] > a[0]) -- l;
        }
        TRACELN(cout<<':'<<l<<' '<<r);
        copy(a + r + 1, a + n, std::ostream_iterator<int>(std::cout, " ") );
        reverse(a + l, a + r + 1);
        copy(a + l, a + r + 1, std::ostream_iterator<int>(std::cout, " ") );
        copy(a, a + l, std::ostream_iterator<int>(std::cout, " "));
        cout<<endl;
    }
    return 0;
}

