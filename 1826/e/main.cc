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

struct no {
    map<int,int> l;
    int64_t a;
};
vector<no> nos;

int64_t travel(int rt, int th, int dep=1) {
    if (dep == m) {
        return nos[rt].a;
    }
    int64_t ret = 0;
    for (auto [k, v] :nos[rt].l) {
        if (k >= r[dep][th]) return ret;
        ret = max(travel(v, th, dep + 1), ret);
    }
    return ret;
}

void insert(int rt, int th, int dep=1) {
    if (dep == m) nos[rt].a = max(nos[rt].a, f[th]);
    else {
        auto &l = nos[rt].l;
        auto &p = l[r[dep][th]];
        if (p == 0) {
            p = nos.size();
            nos.emplace_back();
        }
        insert(p, th, dep+1);
    }
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    cin >> m >> n;
    nos.reserve(n * m);
    copy_n(std::istream_iterator<int> (cin), n, P);
    for (int i = 0; i < m; ++i) copy_n(std::istream_iterator<int> (cin), n, r[i]);
    for (int i = 0; i < n; ++i) h[i] = i;
    sort(h, h + n, [&](int a, int b) {
                return r[0][a] < r[0][b];
            });
    nos.resize(1);
    for (int i = 0, j = 0; i < n; ++i) {
        while (r[0][h[j]] < r[0][h[i]]) insert(0, h[j++]);
        f[h[i]] = travel(0, h[i]) + P[h[i]];
    }
    cout << *max_element(f, f + n) << endl;
    return 0;
}

