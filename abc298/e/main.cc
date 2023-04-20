#include <cstdint>
#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc


namespace A {

template <class T>
inline constexpr T qpow_in_mod(T base, T ind, T m) {
    T res = 1;
    for (T bi = base; ind > 0; ind >>= 1, bi = (bi * bi) % m)
        if (ind & 1) res = (res * bi) % m;
    return res;
}

template <int64_t M, class T = int64_t>
class CalcInMod {
public:
    typedef T data_t;

    T v;

    CalcInMod() {}
    CalcInMod(int v): v{static_cast<T>(v)} {}
    CalcInMod(T v): v{v} {}

    int as_i() { return static_cast<int>(v); }

    using type = CalcInMod<M, T>;

    inline static T add(T a, T b) { return (a + b) % M; }
    inline static T sub(T a, T b) { return (a - b + M) % M; }
    inline static T mul(T a, T b) { return (a * b) % M; }
    inline static T qpow(T base, T ind) {
        T res = 1;
        for (T bi = base; ind > 0; ind >>= 1, bi = mul(bi, bi))
            if (ind & 1) res = mul(res, bi);
        return res;
    }

    inline type operator+ (type const & a) const { return {(a.v + v) % M}; }
    inline type operator- (type const & a) const { return {(v - a.v + M) % M}; }
    inline type operator* (type const & a) const { return {(a.v * v) % M}; }
    inline type & operator+= (type const & a) { *this = *this + a; return *this; }
    inline type & operator-= (type const & a) { *this = *this - a; return *this; }
    inline type & operator*= (type const & a) { *this = *this * a; return *this; }
    inline type mul_inv() const { return {qpow(M - 2)}; }
    inline type qpow(T ind) const { return {qpow(v, ind)}; }

    inline bool operator== (type const & a) const { return v == a.v; }
    inline bool operator< (type const & a) const { return v < a.v; }
};
}
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc: calc_in_mod

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
#define TRACELN(...) TRACE(__VA_ARGS__; cout << endl)
#define TRACE_VEC(VEC, ITEM, ...) TRACE(cout << #VEC << "= "; for_each((VEC).begin(), (VEC).end(), [&](ITEM _i) { __VA_ARGS__; }))
using namespace std;
#define self_todo_placeholder

typedef A::CalcInMod<998244353> cm;
cm f[2][111][111];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, A, B, P, Q;
    cin >> n >> A>>B>>P>>Q;
    f[0][A][B] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            for (int k = 0; k < 2; ++k) {
                auto v = f[k][i][j];
                if (v.v==0) continue;
                auto l = k==0?P:Q;
                v *= cm{l}.mul_inv();
                for (int d = 1; d <= l; ++d) {
                    auto ti = i, tj=j;
                    if (k==0) ti=min(ti+d,n);
                    else tj=min(tj+d,n);
                    f[k^1][ti][tj] += v;
                }
            }
    cm ans = 0;
    for (int i = 1; i < n; ++i) ans += f[1][n][i];
    cout << ans.v << endl;
    return 0;
}

