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

    int n; cin >>n;
    unordered_map<string,int> ss;
    for (int i = 0; i < n; ++i) {
        string s; cin >>s;
        ss[s] = i+1;
        reverse(s.begin(), s.end());
        ss[s] = i+1;
    }
    vector<int> a;
    a.reserve(ss.size());
    transform(ss.begin(), ss.end(), std::back_inserter(a), [](auto kv) { return kv.second; });
    sort(a.begin(),a.end());
    cout<<(unique(a.begin(),a.end())-a.begin())<<endl;
    //TRACELN(copy(ss.begin(), ss.end(), std::ostream_iterator<std::string>(std::cout, " ")));
    return 0;
}

