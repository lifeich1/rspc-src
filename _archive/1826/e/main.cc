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

const int N = 5013;
int P[N], h[N];
int r[555][N];
int64_t f[N];
int n, m; 

uint64_t bs[2][N][N/64+1];

void se(uint64_t *b, int i) {
    uint64_t t=1;
    t<<=i%64;
    b[i/64]|=t;
}
bool ge(uint64_t *b, int i) {
    uint64_t t=1;
    t<<=i%64;
    return (b[i/64]&t)>0;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    cin >> m >> n;
    copy_n(std::istream_iterator<int> (cin), n, P);
    for (int i = 0; i < m; ++i) copy_n(std::istream_iterator<int> (cin), n, r[i]);
    for (int i = 0; i < n; ++i) h[i] = i;
    auto n_ = n/64+1;
    for (int k = 0; k < m; ++k) {
        int g = k>0?1:0;
        sort(h, h + n, [&](int a, int b) {
                return r[k][a] < r[k][b];
                });
        for (int i = 0, j = 0; i < n; ++i) {
            auto *b = bs[g][h[i]];
            if (i > 0) {
                auto *b0 = bs[g][h[i - 1]];
                copy_n(b0, n_, b);
            } else {
                fill(b, b+n_, 0);
            }
            if (r[k][h[i]] == r[k][h[j]]) continue;
            for (; j < i; ++j) {
                se(b, h[j]);
            }
        }
        if (g) 
            for (int i = 0; i<n;++i) transform(bs[g][i], bs[g][i] + n_, bs[0][i], bs[0][i], bit_and{});
    }
    for (int i = 0; i < n;++i) {
        auto *b = bs[0][h[i]];
        for (int j = 0; j < i; ++j)
            if (ge(b, h[j])) f[i] = max(f[i], f[j]);
        f[i] += P[h[i]];
    }
    cout << *max_element(f, f + n) << endl;
    return 0;
}

