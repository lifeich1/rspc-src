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
const int NN = 64 * N;
int a[N], cl[N],cr[N];
int pl[NN],pr[NN],sz[NN],gn,gh;

int ins_cntge(int &n, int l, int r, int x) {
    if (n == 0) {
        n = ++gn;
        sz[n] = pl[n] = pr[n] = 0;
    }
    sz[n]++;
    if (l == r) return 0;
    int md = (l + r) >> 1;
    if (x <= md) return sz[pr[n]] + ins_cntge(pl[n], l, md, x);
    return ins_cntge(pr[n], md+1, r, x);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n,Q; cin >>n>>Q;
        copy_n(std::istream_iterator<int>(std::cin),n,a);
        int L = *min_element(a,a+n);
        int R = *max_element(a,a+n);
        gh = gn = 0;
        for (int i = 0; i < n; ++i) {
            cl[i] = ins_cntge(gh, L, R, a[i]);
        }
        gh = gn = 0;
        for (int i = n-1; i >= 0; --i) {
            cr[i] = ins_cntge(gh, L, R, a[i]);
            if (cl[i] > cr[i]) swap(cl[i], cr[i]);
        }
        TRACELN(copy_n(cl,n, std::ostream_iterator<int>(std::cout, " ") ));
        TRACELN(copy_n(cr,n, std::ostream_iterator<int>(std::cout, " ") ));
        while(Q--) {
            int k,r; cin >>k>>r;
            --k;
            --r;
            if (r >= cl[k]+cr[k]) cout<<"0\n";
            else if (r <= cr[k]-cl[k]) {
                cout<<cr[k]-r<<endl;
            } else {
                r -= cr[k] - cl[k];
                cout<<(cl[k] - (r)/2)<<endl;
            }
        }
    }
    return 0;
}

