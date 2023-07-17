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

int zcd(int a, int b) {
    if (a == 0) return 0;
    if (0 == b) return 1;
    if (a == b) return 2;
    if (a < b) {
        int t = b / a;
        if (t & 1) {
            t += t / 2+1;
            return t + zcd(b%a, a); 
        } else {
            t += t / 2;
            return t + zcd(a, b % a);
        }
    } else {
        int t = a / b;
        if (t & 1) {
            t += (t+1)/2-1;
            return t + zcd(b, a%b);
        } else {
            t += t/2;
            return t + zcd(a%b, b);
        }
    }
}

const int N = 101001;
int a[N],b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >>n;
        copy_n(std::istream_iterator<int>(std::cin),n,a);
        copy_n(std::istream_iterator<int>(std::cin),n,b);
        bool ok = true;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            if (max(a[i], b[i]) == 0) continue;
            int v = zcd(a[i],b[i]);
            s.emplace(v%3);
        }
        ok = s.size() <= 1;
        cout<< (ok?"YES\n":"NO\n");
    }
    return 0;
}

