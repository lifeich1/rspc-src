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

typedef A::CalcInMod<998244353> Cm;

Cm F[2][512];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin >> n;
    auto * f = F[0];
    auto *g = F[1];
    fill(f+1, f +512, Cm{0});
    f[0] = 1;
    Cm ans = 0;
    while (n--) {
        swap(f, g);
        fill(f, f +512, Cm{0});
        int A; cin >> A;
        Cm ra = Cm{A}.mul_inv();
        for (int m = 0; m < 512; ++m) {
            if (g[m].v == 0) continue;
            const int l = min(10, A);
            for (int i = 1; i <= l; ++i) {
                if (i == 10) {
                    ans += g[m] * ra;
                    continue;
                }
                if ((1<<(10-i-1)) & m) {
                    ans += g[m] * ra;
                    continue;
                }
                int t = m | (1 << (i-1));
                for (int k = 0; k < 10; ++k)
                    if (m & (1<<k)) {
                        int u = k + i;
                        if (u < 10) t |= 1 << u;
                    }
                f[t] += g[m] * ra;
            }
            if (A > 10) {
                auto d = ra * (A - 10);
                f[m] += g[m] * d;
            }
        }
#if defined(RSPC_TRACE_HINT)
        for (int i = 0; i < 512; ++i)
            if (f[i].v) cout<<' '<<i;
        cout<<endl;
#endif
    }
    cout<<ans.v<<endl;
    return 0;
}

