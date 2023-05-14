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

void ta_a(int * a, int n, int x, int d = 1) {
    for (;x <= n; x += x&(-x)) a[x] += d;
}
int ta_s(int *a, int n, int x) {
    int ret = 0;
    for (; x > 0; x -= x & (-x)) ret += a[x];
    return ret;
}
const int N = 7101;
int a[N], s[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, K; cin >> n >> K;
    copy_n(std::istream_iterator<int>(std::cin) ,  n, a+1);
    int L = 1, R;
    for (; L <= n; ++L) {
        int m = L+(n - L) * (n - L+1) / 2;
        int bf = a[L] - ta_s(s, n, a[L]);
        //TRACELN(cout<<"L " << L <<  ' '<<bf<<' '<<m<<' '<<K);
        if (K < bf || K >= bf + m)  {
            if (K >= bf + m) K -= m;
            vector<int> vs(a + L + 1, a + n +1);
            sort(vs.begin(), vs.end());
            auto v = vs[K-1];
            R = find(a+L+1, a+n+1, v) - a;
            //TRACELN(cout<<K<<" vs:";copy(vs.begin(), vs.end(), std::ostream_iterator<int>(std::cout, " ")));
            break;
        }
        K -= bf - 1;
        ta_a(s, n, a[L]);
    }
    reverse(a+L, a+R+1);
    TRACELN(cout<<L<<' '<< R);
    copy_n(a +1, n, std::ostream_iterator<int>(std::cout, " ") );
    cout << endl;
    return 0;
}

