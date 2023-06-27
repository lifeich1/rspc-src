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
const int N = 501001;
int ip[N],hz[N], pp[N];
Cm f[N],rhz[N];
vector<int> ps;
int tf[1<<15];
int ccc=0,cc2=0;

int copc(int x, int y, int mo = 1) {
    vector<int> p;
    for (auto t : ps) {
        if (x < t*t) break;
        //if (mo % t == 0) continue;
        if (x % t == 0) {
            p .emplace_back(t);
            x /=t;
            while(x%t==0) x/=t;
        }
        ++cc2;
    }
    if (x > 1) p.emplace_back(x);
    const int M = 1<<p.size();
    int a = y;
    for (int i = 1; i < M; ++i) {
        int k = __builtin_ctz(i);
        if (i==(i&(-i))) {
            tf[i] = p[k];
        } else tf[i] = p[k] * tf[i-(i&(-i))];
        int d = y / tf[i];
        if (__builtin_popcount(i) & 1) a -= d;
        else a += d;
    }
    ccc+= M;
    return a;
}

void factor(int x, int* v, int*vn) {
    static int p[32], c[32], rp[32], i[32];
    int tt = 0;
    for (auto t : ps) {
        if (x % t == 0) {
            p[tt] = t;
            c[tt] = 1;
            tt++;
            for (x/=t; x % t == 0; c[tt-1]++, x/=t);
        }
        if (x <= t*t) break;
    }
    if (x>1) {
        p[tt] = x; c[tt++] = 1;
    }
    i[0] = 1;
    fill(i+1,i+tt,0);
    int kk = p[0];
    for (int i = 0; i < tt; ++i) {
        rp[i] = p[i];
        for (int j = 0; j < c[i];++j) rp[i] *= p[i];
    }
    *vn=0;
    TRACELN(cout<<'f'<<tt);
    while(i[tt-1] <= c[tt-1]) {
        v[(*vn)++] = kk;
        TRACE(cout<<' '<<kk);

        ++i[0];
        kk *= p[0];
        for (int k = 0; k < tt-1; ++k) {
            if (i[k] > c[k]) {
                i[k] =0;
                kk /= rp[k];
                i[k+1] ++;
                kk *= p[k+1];
            } else break;
        }
    }
    TRACELN(cout<<"::"<<*vn);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int n; cin >>n;
    for (int i = 2; i <=n; ++i)
        if (0==ip[i]) {
            //TRACE(cout<<' '<<i);
            ps .emplace_back(i);
            if (i > 1000) continue;
            for (int j = i+i; j<=n; j+=i) ip[j] =1;
        }
    //TRACELN();
    const Cm rn = Cm{n}.mul_inv();
    f[1] = 0;
    array<int, 200> c;
    int cn;
    int cnt=0;
    for (int i = 2; i <= n; ++i) {
        factor(i, c.data(), &cn);
        f[i] = 1;
        TRACELN(cout<<"c"<<i<<' '<<copc(i,n)<<' '<<cn);
        for (int u = 0; u < cn; ++u) {
            int k = c[u];
            if (k < i) {
                ++cnt;
                TRACE(cout<<' '<<k);
                f[i] += f[k] * rn * copc(i/k,n/k);
            }
        }
        TRACELN();
        f[i] *= (Cm{1}-(rn*(n/i))).mul_inv();
    }
    TRACELN(cout<<"cnt:"<<cnt<<' '<<ccc<<' '<<cc2);
    for (int i = 1; i <= n; ++i)
        cout<<f[i].v<<' ';
    cout<<endl;
    return 0;
}

