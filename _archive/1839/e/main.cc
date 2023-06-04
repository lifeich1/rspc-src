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

const int N = 303;
int a[N*N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    vector<int> x;
    int n; cin >> n;
    copy_n(std::istream_iterator<int>(std::cin),n, std::back_inserter(x));
    a[0] = 1;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = s; k >= 0; --k)
            if (a[k] && 0 == a[k+x[i]]) {
                a[k+x[i]] = i+1;
            }
        s += x[i];
    }
    if ((s & 1) == 0 && a[s/2]) {
        set<int> u;
        for (int k = s/2; k > 0; k -= x[a[k]-1]) {
            u.emplace(a[k]-1);
        }
        cout<<"Second\n" << flush;
        int r;
        for (cin>>r; r > 0; cin>>r) {
            if (r == 0) break;
            r--;
            int q = 0;
            auto col = [&](int r) { return u.find(r) == u.end(); };
            auto rc  = col(r);
            for (int j = 0; j < n; ++j)
                if (x[j] > 0 && col(j) != rc) {
                    q = j; break;
                }
            auto d = min(x[r], x[q]);
            x[r] -= d, x[q] -= d;
            cout<<q+1<<endl<<flush;
        }
    } else {
        cout << "First\n" << flush;
        int r;
        do {
            auto q = find_if(x.begin(), x.end(), [](int t) {return t>0; }) - x.begin();
            cout<<q+1<<endl<<flush;
            cin>> r;
            if (r) {
                r--;
                auto d = min(x[r], x[q]);
                x[r] -= d, x[q] -= d;
            }
        } while (r != 0);
    }
    return 0;
}

