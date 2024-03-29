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

typedef A::CalcInMod<998244353> CM;
const int N9 = 4020;
const int N = 2000;
CM pa[N9], invpa[N9], tp[N9], tip[N9];
int c[N9];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    invpa[0] = pa[0] = 1;
    for (int i = 1; i <= N+N; ++i) {
        pa[i] = pa[i - 1] * i;
        invpa[i] = pa[i].mul_inv();
    }

    int n, m, K;
    cin >> n >> m >> K;
    for (int i = 0, x; i < n; ++i) { cin >> x; c[x]++; }
    for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
    CM ans = 0;

    auto Cf = [&](int m, int n) { return pa[n] * invpa[m] * invpa[n - m]; };
    auto Rf = [&](int m, int n) { return (n == m && m == 0) ? 1 : Cf(m, n + m - 1); };
    TRACELN(cout << "--" << Rf(0, 0).v);

    auto vm = CM{m}.mul_inv();
    for (int a = 1; a <= m; ++a) {
        int ml = c[a - 1] - c[0]; // already fill
        int mr = c[m] - c[a - 1];
        if (ml >= K || K + mr > n) {
            if (K + mr > n) {
                ans += 1; // filled is >= a
                TRACELN(cout << ':' << a << " 1");
            }
            continue;
        }
        auto p = vm * (m - a + 1);
        auto ip = vm * (a - 1);
        tip[0] = tp[0] = 1;
        for (int i = 0; i < c[0]; ++i)
            tp[i + 1] = tp[i] * p, tip[i + 1] = tip[i] * ip;
        for (int i = n - K - mr + 1; i <= c[0]; ++i) {
            ans += tp[i] * tip[c[0] - i] * Cf(i, c[0]);
        }
        TRACELN(cout << ',' << a << ' ' << (n - K - mr + 1)
                << ' ' << ans.v);
    }

    cout << ans.v << endl;

    return 0;
}

