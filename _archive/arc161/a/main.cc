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

    vector<int> a,b; int n; cin >> n;a.resize(n);b.resize(n);
    if(n==1) {
        cout<<"Yes\n";
        return 0;
    }
    copy_n(std::istream_iterator<int>(std::cin),n,a.begin());
    sort(a.begin(), a.end());
    for (int i = 0; i +i+1 < n; ++i) b[i+i+1] = a[n-i-1];
    for (int i = 0; i < n; i += 2) b[n-1-i] = a[i>>1];
    bool ans = true;
    for (int i = 1; i < n; i += 2)
        if (b[i] <= b[i-1] || b[i] <= b[i+1]) {
            ans = false;
            break;
        }
    cout<<(ans?"Yes\n":"No\n");
    return 0;
}

