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
    CalcInMod():v{0} {}
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
    template<class Stream>
        Stream& operator<< (Stream & stm) const { stm << v; return stm; }
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

const int N = 301001;
char s[N];
typedef A::CalcInMod<998244353> Cm;
Cm suflo[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    cin >> s;
    int n = strlen(s);
    array<Cm, 29> f1, f2, dv; // no A, A distinct, AA no a, AAa 
    Cm *f = f1.data(), *f0 = f2.data();
    f[0] = 1;
    dv[1] = 1;
    for (int i = 2; i <= 26; ++i) dv[i] = Cm{i}.mul_inv();
    set<int> A;
    for (int i = 0; i < n; ++i) {
        swap(f, f0);
        if (s[i] == '?') {
            transform(f0, f0 + 29, f, [](const auto &v) { return v * 26; }); // 0-26, 28: append a; 27: append A
            f[28] += f0[27] * 26; // AA . a
            for (int k = 0; k <= 26 - A.size(); ++k) {
                int rk = k + A.size();
                f[27] += f0[k] * rk;
                f[k+1] += f0[k] * (26 - rk);
            }
        } else if (isupper(s[i])) {
            bool dis = A.insert(s[i]).second;
            TRACELN(cout<<'A');
            f[28] = 0; // DDoS
            if (dis) {
                f[27] = f0[27];
                f[0] = 0;
                fill(f + 1, f + 27, Cm{0});
                int dd = 26 - A.size() + 1;
                for (int k = 0; k <= dd; ++k) {
                    f[27] += f0[k] * k * dv[dd];
                    f[k] += f0[k] * (dd - k) * dv[dd];
                }
            } else {
                f[27] = accumulate(f0, f0 + 28, Cm{0});
                fill(f, f + 27, Cm{0});
            }
        } else {
            f[28] = f0[28] + f0[27];
            f[27] = 0;
            copy_n(f0, 27, f);
        }
        TRACELN(for (int q = 0; q < 29; ++q) cout << f[q].v << ' ';);
    }
    TRACELN(for (int i = 0; i < 29; ++i) cout << f[i].v << ' ';);
    cout << accumulate(f, f + 29, Cm{0}).v << endl;
    return 0;
}

