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

vector<int> g1(int *h, int *w) {
    cin >> *h>>*w;
    vector<int> v;
    v.resize(*h);
    for (int i = 0; i < *h; ++i) {
        string s; cin >>s;
        auto &t = v[i];
        t = 0;
        for (int i = 0; i < s.length(); ++i)
            t = t * 2 + (s[i] == '#' ? 1 : 0);
    }
    while (*h > 0 && v[0] == 0) {
        v.erase(v.begin());
        --*h;
    }
    while (*w > 0) {
        bool b = true;
        for (auto t : v)
            if ((t & 1) == 1) {
                b = false;
                break;
            }
        if (!b) break;
        for (auto & t : v) t >>= 1;
        --*w;
    }
    return v;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int ha,wa,hb,wb,hx,wx;
    auto a = g1(&ha, &wa);
    auto b = g1(&hb, &wb);
    auto x = g1(&hx, &wx);
    auto g = [](vector<int> const & v, int h, int dx, int dy) {
        h -= dx;
        if (h < 0 || h >= v.size()) return 0;
        return v[h] << dy;
    };
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j) {
            bool ans = true;
            for (int k = 0; k < 20; ++k) {
                int ma = g(a, k, i/10, i%10);
                int mb = g(b, k, j/10, j%10);
                int mx = g(x, k, 0,0);
                ma |= mb;
                if (ma != mx) {
                    ans = false;
                    break;
                }
            }
            if (ans ) {
                cout<<"Yes\n";
                return 0;
            }
        }
    cout<<"No\n";
    return 0;
}

