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
typedef A::CalcInMod<1000000007> Cm;
const int N = 505;
int a[N];

Cm fc[N], f[N][N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    for (int i = 1; i < N; ++i) fc[i] = Cm{i}.mul_inv();
    int tt; cin >> tt; while (tt--) {
        int n,K;cin>>n>>K;
        copy_n(std::istream_iterator<int>(std::cin),n,a);
        string s; cin >>s;

        for (int i = 0; i < n;++i)
            for (int j = 0; j < n; ++j) f[i][j].v = 0;
        f[0][n-1].v = 1;

        for (int k = 0; k < K; ++k) {
            if (s[k] == 'L') {
                for (int l = 0; l < n; ++l) {
                    Cm t{0};
                    for (int r = n-1; r >= l; --r) {
                        if (l < r) {
                            Cm t0 = t;
                            t += f[l][r] * fc[r-l];
                            f[l][r] = t0;
                        } else {
                            f[l][r] += t;
                        }
                    }
                }
            } else { // R
                for (int r = 0; r < n; ++r) {
                    Cm t{0};
                    for (int l = 0; l <= r; ++l) {
                        if (l < r) {
                            Cm t0 = t;
                            t += f[l][r] * fc[r-l];
                            f[l][r] = t0;
                        } else {
                            f[l][r] += t;
                        }
                    }
                }
            }
        }
        Cm ans{0};
        for (int l = 0; l < n; ++l) {
            Cm s{0};
            for (int r = l; r < n; ++r) {
                s += a[r];
                ans += s * f[l][r];
                TRACELN(cout<<l<<' '<<r<<":"<<f[l][r].v);
            }
        }
        cout<<ans.v<<endl;
    }
    return 0;
}

