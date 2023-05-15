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


typedef A::CalcInMod<998244353> Cm
;
int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n, a1, x, y, m, k;
    cin>>n>>a1>>x>>y>>m>>k;
    int64_t ai = a1;
    Cm sa=ai;
    vector<Cm> f, f0;
    f.emplace_back(a1);
    f.emplace_back(a1);
    f.resize(k+1, Cm{0});
    f0.resize(k+1);
    int64_t c = f[k].v;
    //cout<<f[k].v<<endl;
    for(int i=2;i<=n;++i){
        ai=(ai*x+y)%m;sa += ai; 
        f0.swap(f);
        f[0]=sa;
        f[1]=f0[1]+sa;
        for (int j = 2; j <= k; ++j)
            f[j]=f0[j]+f0[j-1];
        //cout<<f[k].v<<endl;
        c ^= f[k].v*i;
    }
    cout<<c<<endl;
    return 0;
}
 