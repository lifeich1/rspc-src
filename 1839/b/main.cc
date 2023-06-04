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
void taa(int64_t *a, int n, int x, int64_t v) {
    while(x <= n) {
        a[x] += v;
        x += x & (-x);
    }
}
int64_t tas(int64_t *a, int n, int x) {
    int64_t r = 0;
    while(x > 0) {
        r += a[x];
        x -= x&(-x);
    }
    return r;
}
int  h[N],h2[N],u[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    vector<pair<int,int>> a;
    int tt; cin >> tt; while (tt--) {
        int n; cin>>n;
        a.resize(n);
        for (int i = 0; i < n; ++i){ cin >> a[i].first>>a[i].second;
            h2[i]=h[i] = i;
        }
        sort(a.begin(), a.end());
        int q = 0;
        int64_t ans = 0;
        for (int i = 0; i < n;++i) {
            q = 0;
            h[q++] = a[i].second;
            push_heap(h, h + q);
            while (i+1 <n && a[i].first == a[i+1].first) {
                h[q++] = a[++i].second;
                push_heap(h, h + q);
            }
                int k = a[i].first;
                while(k-- && q > 0) {
                    ans += h[0];
                    pop_heap(h, h+q--);
                }
                q = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}

