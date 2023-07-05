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
    int L,R; cin>>L>>R;
    vector<int> a;
    copy_n(std::istream_iterator<int>(std::cin),n-2, std::back_inserter(a));
    sort(a.begin(), a.end());
    int64_t ans = -1;
    int ll = min(min(L,R), a.front());
    int rr = max(max(R,L), a.back());

    for (int i = ll; i <= rr; ++i)
        for (int j = i; j <= rr; ++j) {
            vector<int> ov,iv;
            for (int x : a) {
                if (x < i || x > j) iv.push_back(min(abs(x-i), abs(x-j)));
                else ov.push_back(min(abs(x-(i-1)),abs(x-(j+1))));
            }
            int64_t d = abs(i-L)+abs(j-R);
            if (ov.size() > m) {
                sort(ov.begin(),ov.end());
                d += accumulate(ov.begin(), ov.begin()+(ov.size()-m),0);
            } else if (ov.size() < m) {
                sort(iv.begin(),iv.end());
                d += accumulate(iv.begin(), iv.begin()+(m-ov.size()),0);
            }
            if (ans < 0) ans = d;
            else if (ans > d) {
                ans = d;
                TRACELN(cout<<':'<<i<<' '<<j<<' '<<d);
            }
        }
    cout<<ans<<endl;
    return 0;
}

