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

const int N = 101001;
int xs[N], ys[N], hs[N];
int n, m;

inline int64_t x_prod(int64_t u, int64_t v, int64_t x, int64_t y) {
    return -v * x + u * y;
}

bool angl_less(const int i, const int j) {
    return (i == j) ? false : (x_prod(xs[i], ys[i], xs[j], ys[j]) > 0);
}

int64_t ou, ov;

int64_t count_angl_greateroreq(const int64_t u, const int64_t v) {
    const int nn = n + m;
    int64_t ans = 0;
    ou = 0, ov = 1;
    for (int i = 0, j = nn - 1, c2 = m; i < nn && c2 > 0; ++i) {
        if (hs[i] >= n) continue;
        auto x = xs[hs[i]], y = ys[hs[i]];
        while (j >= 0 && (hs[j] < n
                    || x_prod(u, v, xs[hs[j]] + x, ys[hs[j]] + y) < 0)) {
            if (hs[j--] >= n) --c2;
        }
        ans += c2;
        if (c2 > 0) {
            auto tu = x + xs[hs[j]];
            auto tv = y + ys[hs[j]];
            if (x_prod(tu, tv, ou, ov) > 0) ou = tu, ov = tv;
        }
        TRACELN(cout << ':' << i << ' ' << j << ' ' << c2);
    }
    return ans;
}

void tune(int64_t &x, int64_t &y) {
    auto t = max(x, y);
    int t1 = 0;
    for (; t > 0; t >>= 1, ++t1);
    const int G = 45;
    if (t1 > G) x >>= (t1 - G), y >>= (t1 - G);
    else x <<= (G - t1), y <<= (G - t1);
}

void answer(int64_t x, int64_t y) {
    double t = x;
    t *= 100;
    t /= (x + y);
    printf("%.12lf\n", t);
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int64_t k;
    cin >> n >> m>> k;
    int t, *py = ys;
    generate_n(xs, n + m, [&]() { cin >> t >> *(py++); return t; });
    t = 0;
    generate_n(hs, n + m, [&]() { return t++; });
    sort(hs, hs + n + m, angl_less);
    int64_t lu = xs[hs[0]];
    int64_t lv = ys[hs[0]];
    int64_t ru = xs[hs[n+m-1]];
    int64_t rv = ys[hs[n+m-1]];
    tune(lu, lv); tune(ru, rv);
    int cc = 20;
    while (cc--) {
        auto tu = lu + ru, tv = lv + rv;
        tune(tu, tv);
        auto c = count_angl_greateroreq(tu, tv);
        if (k == c) {
            answer(ou, ov);
            break;
        } else if (c < k) lu = tu, lv = tv;
        else ru = tu, rv = tv;
        TRACELN(cout << '.' << (double(tu) / tv) << ' ' << c
                << ' ' << tu << ' ' << tv);
    }
    return 0;
}

