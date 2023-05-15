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
    int h, dl, dr;
    map<int,int> l;
    int64_t f;
};
vector<no> nos;

int64_t travel(int rt, int th) {
    auto &o = nos[rt];
    for (int i = o.dl; i < o.dr; ++i)
        if (r[i][o.h] >= r[i][th] ) return 0;
    if (o.dr == m) {
        return o.f;
    }
    int64_t ret = 0;
    auto dep = o.dr;
    for (auto [k, v] :o.l) {
        if (k >= r[dep][th]) return ret;
        ret = max(travel(v, th), ret);
    }
    return ret;
}

void insert(int rt, int th) {
    auto & o = nos[rt];
    int sp = -1;
    for (int i = o.dl; i < o.dr; ++i) {
        if (r[i][th] != r[i][o.h]) {
            sp = i; break;
        }
    }
    if (sp >= 0) {
        auto oi = nos.size();
        nos.emplace_back();
        auto ni = nos.size();
        nos.emplace_back();
        auto &od = nos[oi];
        auto &nd = nos[ni];
        od.l.swap(o.l);
        od.h = o.h; od.dl = sp; od.dr = o.dr; od.f = o.f;
        o.dr = sp; o.l[r[sp][o.h]] = oi;
        o.l[r[sp][th]] = ni;
        nd.h = th; nd.dl = sp; nd.dr = m;
        nd.f = f[th];
        return;
    }
    auto &p = o.l[r[o.dr][th]];
    if (p) {
        insert(p, th);
    } else {
        p = nos.size();
        nos.emplace_back();
        auto &nd = nos.back();
        nd.h = th; nd.dl = o.dr; nd.dr = m;
        nd.f = f[th];
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

