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

    int n,m; cin >>n>>m;
    vector<int> P,L,D;
    vector<pair<int,int>> ls;
    copy_n(std::istream_iterator<int>(std::cin),n, std::back_inserter(P));
    copy_n(std::istream_iterator<int>(std::cin),m, std::back_inserter(L));
    copy_n(std::istream_iterator<int>(std::cin),m, std::back_inserter(D));
    sort(P.begin(),P.end(),greater<int>{});
    for (int i = 0; i < m; ++i) ls .emplace_back(L[i],D[i]);
    sort(ls.begin(), ls.end(), greater<pair<int,int>>{});
    multiset<int> s;
    int l = 0;
    while (l<m &&ls[l].first > P[0]) ++l;
    for (int k = 0; k < n; ++k) {
        while(k+1<n && P[k]==P[k+1])++k;
        for (;l < m && (ls[l].first <= P[k]&&(k==n-1||P[k+1]<ls[l].first)); ++l) {
            //TRACELN(cout<<l<<' '<<ls[l].first<<' '<<ls[l].second);
            auto v = ls[l].second;
            if (s.size() <= k) {
                //TRACELN(cout<<'a');
                s.emplace(v);
            }
            else {
                if (*s.begin() < v) {
                //TRACELN(cout<<'b');
                    s.erase(s.begin());
                    s.emplace(v);
                }
            }
        }
    }
    int64_t ans = 0;
    for_each(P.begin(), P.end(), [&](int x) { ans += x; });
    for_each(s.begin(), s.end(), [&](int x) { ans -= x; });
    //TRACELN(copy(P.begin(),P.end(), std::ostream_iterator<int>(std::cout, " ")));
    cout<<ans<<endl;
    return 0;
}

