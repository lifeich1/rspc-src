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

const int M = 1000000;
bool pr[M];
vector<int> P;

int64_t gcd(int64_t a, int64_t b) 
{
    if (a < b) swap(a, b);
    while (b > 0) {
        a %= b;
        if (a < b) swap(a, b);
    }
    return a;
}
int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    pr[0] = pr[1] = false;
    fill(pr + 2, pr + M, true);
    for (int i = 2; i < 1000; ++i)
        if (pr[i]) {
            for (int t = i + i; t < M; t += i) pr[t] = false;
        }
    for_each(pr + 2, pr + M, [&](bool & b) {
                if (b) P.push_back(&b - pr);
            });
    vector<int64_t> pp;

    int64_t a, b, ans = 0;
    cin >> a >> b;
    if (a > b) swap(a, b);
    auto t = gcd(a, b);
    TRACELN(cout<<','<<t);
    a /= t, b /= t;
    b -= a;
    t = b;
    if (b > 1)
    for (auto p : P)
        if (t % p == 0) {
            while (t % p == 0) t /= p;
            pp.push_back(p);
        }
    if (t > 1) pp.push_back(t);
    TRACELN(copy(pp.begin(), pp.end(), std::ostream_iterator<int64_t> (cout," ")));
    while (a > 1) {
        int64_t d = a;
        for (auto p : pp) {
            if (p > a) break;
            auto t1 = a % p;
            if (t1 < d) {
                d = t1;
                if (1 == d) break;
            }
        }
        TRACELN(cout<<'.'<<a<<' '<<b<<' '<<d);
        ans += d;
        a -= d;
        t = gcd(a, b);
        a /= t; b /= t;
        pp.erase(remove_if(pp.begin(), pp.end(), [&](int64_t t) { return b % t != 0;}),pp.end());
    }
    ans += (a > 0)?1:0;
    cout << ans << endl;

    return 0;
}

