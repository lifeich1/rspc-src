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

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int64_t n, a , x, y, m, k;
    cin >> n >> a >> x >> y >> m >> k;

    auto fa = [](int64_t x)->Cm {
        if (x <= 1) return 1;
        Cm ret = 1;
        for (int64_t i = 2; i <= x;++i) ret*= i;
        return ret;
    };
    auto C = [&](int64_t n, int64_t m)->Cm {
        if (n < m) return 0;
        return fa(n) * (fa(m)*fa(n-m)).mul_inv();
    };
    vector<int64_t> aa;
    auto an = a;
    generate_n(std::back_inserter (aa), n, [&]() {
             auto ret = an;
             an = (an * x + y) % m;
             return ret;
            });
    TRACELN(copy(aa.begin(), aa.end(), std::ostream_iterator<int64_t> (cout, " " )));
    int64_t ans = 0;
    for (int64_t i = 1; i <= n; ++i) {
        Cm b = 0;
        for (int j = 1; j <= i; ++j) {
            TRACE(cout << C(i - j+1, k).v << '*'<<aa[j-1]<<' ');
            b += C(i - j+1, k)*aa[j-1];
        }
        ans ^= b.v * i;
        TRACELN(cout<<"s="<<b.v<<'*'<<i<<'='<<b.v*i<<", a:"<<ans);
    }
    cout << ans << endl;
    return 0;
}

