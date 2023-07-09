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
int pl[N*30],pr[N*30],mi[N*30],tt = 0;

void ins(int &n, int l, int r, int x, int y) {
    if (0 == n) {
        n = ++tt;
        pr[n] = pl[n] = 0;
        mi[n] = y;
    } else mi[n] = min(mi[n], y);
    if (l == r) return;
    int mid = (l+r) /2;
    if (x <= mid) ins(pl[n], l, mid, x, y);
    else ins(pr[n], mid+1, r, x,y);
}

bool isle(int n, int l, int r, int x, int y) {
    if (n == 0) return false;
    if (r <= x) return mi[n] <= y;
    int mid = (l+r)/2;
    if (x > mid && isle(pr[n], mid+1, r, x, y)) return true;
    return isle(pl[n], l, mid, x,y);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    const int L = 1000000000;
    int gh = 0;
    int n; cin >>n;
    vector<tuple<int,int,int>> a;
    a.reserve(n);
    for(int i = 0; i < n; ++i) {
        int t[3];
        cin >>t[0]>>t[1]>>t[2];
        sort(t,t+3);
        a .emplace_back(t[2],t[1],t[0]);
    }
    sort(a.begin(),a.end());
    int i = 0;
    for (auto [x,y,z]: a) {
        while (i < n && get<0>(a[i]) < x) {
            auto [t,u,v] = a[i++];
            ins(gh, 1,L, u,v);
        }
        if (y > 1 && z > 1 && isle(gh, 1,L, y-1,z-1)) {
            cout<<"Yes\n";return 0;
        }
    }
    cout<<"No\n";
    return 0;
}

