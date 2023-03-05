#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
using namespace std;
#define self_todo_placeholder


template <class T, int64_t M>
class CalcInMod {
public:

    T qpow(T base, T ind) {
        T ans = 1;
        for (T bi = base; ind > 0; ind >>= 1, bi = (bi * bi) % M) {
            if (ind & 1) {
                ans = (ans * bi) % M;
            }
        }
        return ans;
    }

    T mul(T a, T b) { return (a * b) % M; }
    T mul_inv(T a) { return a == 1 ? 1 : qpow(a, M - 2); }
    T div(T a, T b) { return mul(a, mul_inv(b)); }
    T add(T a, T b) { return (a + b) % M; }
    T sub(T a, T b) { return (a - b + M) % M; }

};


bool prim[1001001];
array<int64_t, 2345> f0, f1;

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif
    const int64_t M = 998244353;
    CalcInMod<int64_t, M> ca;

    int n;
    cin >> n;
    const auto dn = n * 2;
    vector<int> a;
    a.reserve(dn);
    for (int i = 0, v; i < dn; ++i) cin >> v, a.push_back(v);

    sort(a.begin(), a.end());
    prim[1] = false;
    fill(prim + 2, prim + a.back() + 1, true);
    for (int b = 2; b < 1000; ++b)
        if (prim[b]) {
            for (int t = b << 1; t <= a.back(); t += b) prim[t] = false;
        }

    vector<int64_t> permu;
    permu.push_back(1);
    for (int i = 1; i <= dn; ++i) permu.push_back(ca.mul(permu.back(), i));
    vector<int64_t> permu_mul_inv;
    transform(permu.begin(), permu.end(), back_inserter(permu_mul_inv),
            [&](int64_t x) { return ca.mul_inv(x); });

    auto is_prim = [&](int const & x) { return prim[x]; };
    //int64_t apri = std::count_if(a.begin(), a.end(), is_prim);
    //int64_t apri_no = a.size() - apri;

    map<int,int> ps, cs;
    for (auto x : a) {
        if (is_prim(x)) ps[x]++;
        else cs[x]++;
    }
    if (ps.size() < static_cast<size_t>(n)) {
        cout << "0\n";
        return 0;
    }

    int64_t ans = permu[n];
    for (auto const & [k, v] : cs) {
        ans = ca.mul(ans, permu_mul_inv[v]);
    }

    int64_t *f = f0.data();
    int64_t *g = f1.data();
    fill(f, f + n + 1, 0);
    f[0] = 1;
    for (auto const & [k, v] : ps) {
        swap(f, g);
        f[0] = ca.mul(g[0], permu_mul_inv[v]);
        for (int i = 1; i <= n; ++i) {
            f[i] = ca.add(ca.mul(permu_mul_inv[v], g[i]),
                    ca.mul(permu_mul_inv[v - 1], g[i - 1]));
        }
    }

    ans = ca.mul(ans, f[n]);
    cout << ans << endl;

    return 0;
}

