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
int A[2][N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        int* a = A[0], *b = A[1];
        copy_n(std::istream_iterator<int>(std::cin),n,a);
        copy_n(std::istream_iterator<int>(std::cin),n,b);
        bool ok = false;
        for (int ii = 0; ii < 5000; ++ii) {
            transform(a,a+n, b, a, [](int i, int j) { return abs(i-j); });
            swap(a, b);
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}

