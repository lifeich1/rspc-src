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
int a[N],b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin>>n;copy_n(std::istream_iterator<int>(std::cin) ,n,a);
    copy_n(a,n,b);
    sort(b,b+n);
    vector<int> st(16,0);
    for (int i = 0; i < n; ++i) st[(a[i]-1)<<2|(b[i]-1)]++;
    set<pair<int,vector<int>>> lis;
    set<vector<int>> uu;
    lis.emplace(0,st);
    uu.emplace(st);
    int ans = -1;
    while(lis.size()) {
        auto [vv,s] = *lis.begin();
        lis.erase(lis.begin());
        TRACELN(cout<<setw(4)<<vv;for(int i=0;i<16;++i)cout<<(i>0&&(i&3)==0?"\n    ":"")<<' '<<s[i];);
        int t = 0;
        for (int i = 0; i < 4;++i) t+= s[i<<2|i];
        if (t==n) {ans=vv; break;}
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) if (i!=k&&j!=i){
                int u = i<<2|k, v = j<<2|i;
                //TRACELN(cout<<">"<<u<<' '<<v);
                int d = min(s[u],s[v]);
                if (d>0) {
                    auto ns = s;
                    ns[u]-=d, ns[v]-=d;
                    ns[i<<2|i]+=d, ns[j<<2|k] += d;

        //TRACELN(cout<<setw(5)<<vv+d;for(int i=0;i<16;++i)cout<<(i>0&&(i&3)==0?"\n    ":"")<<' '<<ns[i];);
                    if (uu.emplace(ns).second)
                        lis.emplace(vv+d,ns);
                }
            }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

