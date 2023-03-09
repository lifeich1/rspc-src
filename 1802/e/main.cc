#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...) do { __VA_ARGS__; } while (0)
#else
#define TRACE(...) (void)0
#endif
using namespace std;
#define self_todo_placeholder

const int N = 200101;
int al[N], ap[N], a[N], ta[N], taclr[N], taclr_f;
pair<int,int> h[N];

void ta_put_max(int *a, int n, int x, int y) {
    for (; x <= n; x += (x & -x)) {
        if (a[x] < y || taclr[x] != taclr_f) a[x] = y, taclr[x] = taclr_f;
        else break;
    }
}

int ta_max(int *a, int n, int x) {
    int res = 0;
    for (; x > 0; x -= (x & -x)) {
        if (res < a[x] && taclr[x] == taclr_f) res = a[x];
    }
    return res;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int amx = 0;
        for (int i = 0, kk = 0; i < n; ++i) {
            ap[i] = kk;
            auto & m = al[i];
            cin >> m;
            int mx = 0;
            for (int j = 0; j < m; ++j) {
                auto & x = a[kk++];
                cin >> x;
                if (x > mx) mx = x;
            }
            if (amx < mx) amx = mx;
            h[i] = {mx, i};
        }
        sort(h, h + n);
        ++taclr_f;
        for (int i = 0; i < n; ++i) {
            auto hi = h[i].second;
            auto ed = al[hi] + ap[hi];
            int mx = 0, cur = 0;
            for (int k = ap[hi]; k < ed; ++k) {
                if (a[k] > mx) {
                    mx = a[k], cur++;
                    int t = 1 + ta_max(ta, amx, a[k] - 1);
                    if (cur < t) cur = t;
                }
            }
            ta_put_max(ta, amx, mx, cur);
        }
        cout << ta_max(ta, amx, amx) << endl;
    }
    return 0;
}

