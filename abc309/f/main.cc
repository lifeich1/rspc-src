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
int pn[N*60][4],tt = 0;

void ins(int &r, int xl, int xr, int yl, int yr, int x, int y) {
    if (0 == r) {
        r = ++tt;
        fill(pn[r], pn[r]+4, 0);
    }
    if (xl == xr) return;
    int xd = (xl+xr)/2;
    int yd = (yl+yr)/2;
    if (x <= xd) {
        if (y <= yd) ins(pn[r][0], xl,xd, yl,yd, x,y);
        else ins(pn[r][1], xl,xd, yd+1,yr, x,y);
    } else {
        if (y <= yd) ins(pn[r][2], xd+1, xr, yl, yd, x,y);
        else ins(pn[r][3], xd+1,xr, yd+1,yr, x,y);
    }
}

bool findle(int r, int xl, int xr, int yl, int yr, int x, int y) {
    if (r == 0) return false;
    if (xr <= x && yr <= y) return true;
    if (xl == xr) return false;
    int xd = (xl+xr)/2;
    int yd = (yl+yr)/2;
    if (x > xd && y > yd) {
        if (findle(pn[r][3], xd+1,xr, yd+1,yr, x,y)) return true;
    }
    if (x > xd) {
        if (findle(pn[r][2], xd+1, xr, yl, yd, x,y)) return true;
    }
    if (y > yd) {
        if (findle(pn[r][1], xl,xd, yd+1,yr, x,y)) return true;
    }
    return findle(pn[r][0], xl,xd, yl,yd, x,y);
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
            ins(gh, 1,L,1,L, u,v);
        }
        if (y > 1 && z > 1 && findle(gh, 1,L,1,L, y-1,z-1)) {
            cout<<"Yes\n";return 0;
        }
    }
    cout<<"No\n";
    return 0;
}

