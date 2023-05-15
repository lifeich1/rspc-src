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
int a[N], ami_m[N];
int64_t ami_s[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, q; cin >> n >> q;
    copy_n(std::istream_iterator<int> (cin), n ,a );
    sort(a, a + n);
    int64_t t1 = 0; int t2 = a[0];
    for (int i = 0; i < n; ++i) {
        int t = a[i] - i;
        t2 = min(t2, t);
        ami_m[i] = t2;
        t1 += t;
        ami_s[i] = t1;
    }

    while (q--) {
        int64_t k; cin >> k;
        if (k <= n) {
            int64_t t = a[k];
            if (k == n) t = a[0] +k;
            cout << min(ami_m[k-1]+k, t)<<' ';
        } else {
            int d1 = (k - n + 1) / 2;
            int64_t s, mt;
            if ((k-n)&1) { // a.back nop
                mt = a[n-1];
                if (n>1) mt = min(ami_m[n-2]+k,mt);
                s = (n>1?ami_s[n-2]:0)+max(n-1,0)*k+a[n-1];
            } else {
                mt = ami_m[n-1]+k;
                s = ami_s[n-1] + int64_t(n) * k;
            }
            TRACE(cout<< '('<<s << ' '<< mt<<')');
            s -= mt * n;
            if (s < d1) {
                mt -= (d1 - s- 1) / n + 1;
            }
            cout << mt << ' ';
        }
    }
    cout << endl;
    return 0;
}

