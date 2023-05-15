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
vector<pair<int,int>> a;

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    vector<int> a1, a2;
    int tt; cin >> tt; while (tt--) {
        int n, s1, s2;
        cin >> n >> s1 >> s2;
        a.clear();
        a.reserve(n);
        a1.clear();
        a1.reserve(n);
        a2.clear();
        a2.reserve(n);
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            a.emplace_back(x, i + 1);
        }
        sort(a.begin(), a.end());
        int64_t t1, t2;
        t1 = s1, t2 = s2;
        for (int i = n; i > 0; --i) {
            auto x = a[i - 1].second;
            if (t1 < t2) a1.push_back(x), t1 += s1;
            else a2.push_back(x), t2 += s2;
        }
        cout << a1.size()<< ' ';
        copy(a1.begin(), a1.end(), std::ostream_iterator<int> (cout, " "));
        cout << endl;
        cout << a2.size()<< ' ';
        copy(a2.begin(), a2.end(), std::ostream_iterator<int> (cout, " "));
        cout << endl;
    }
    return 0;
}

