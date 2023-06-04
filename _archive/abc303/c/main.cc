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


int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n,m,H,K;cin>>n>>m>>H>>K;
    string s;cin>>s;
    set<pair<int,int>> it;
    while(m--) {
        int x,y;cin>>x>>y;
        it.emplace(x, y);
    }
    int x,y; x = y = 0;
    bool ans = true;
    auto f = [&](char c) {
        if (!ans) return;
        switch(c) {
            case 'R': x+=1;break;
            case 'L': x-=1;break;
            case 'U': y+=1;break;
            case 'D': y-=1;break;
        }
        auto i = it.find(pair<int,int>{x,y});
        --H;
        if (H < 0) ans = false;
        if (i != it.end() && H < K)  {
            it.erase(i);
            H = K;
        }
        TRACELN(cout<<':'<<x<<' '<<y<<' '<<H);
    };
    for_each(s.begin(), s.end(), f);
    cout<<(ans?"Yes\n":"No\n");
    return 0;
}

