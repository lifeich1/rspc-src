#include <bits/stdc++.h>

// Placeholder for upcoming un-std algorithm, by rspc
// End placeholder for upcoming un-std algorithm, by rspc
// Scheme by rspc:

#if defined(RSPC_TRACE_HINT)
#define TRACE(...)                                                             \
  do {                                                                         \
    __VA_ARGS__;                                                               \
  } while (0)
#else
#define TRACE(...) (void)0
#endif
#define TLN(...) TRACE(__VA_ARGS__; cerr << endl)
#define TA(VEC, ...)                                                           \
  TRACE(cerr << #VEC << "= ";                                                  \
        for_each((VEC).begin(), (VEC).end(), [&](auto _) { __VA_ARGS__; }))
#define TI(HEAD, TAIL, ...)                                                    \
  TRACE(cerr << "[" #HEAD "," #TAIL ") = ";                                    \
        for_each((HEAD), (TAIL), [&](auto _) { __VA_ARGS__; }))
#define TV(EXPR) TRACE(cerr << #EXPR " = " << (EXPR) << ' ')
using namespace std;
#define self_todo_placeholder

const int N = 201001;
int mk[19][N];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a, b;
    a.reserve(n);
    b.reserve(n);
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(a));
    copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(b));
    bool ok = true;
    for (int i = 0; i < n; ++i)
      ok &= a[i] <= b[i];
    if (!ok) {
      cout << "NO\n";
      continue;
    }

    for (int i = 0; i < n; ++i)
      mk[0][i] = a[i];
    for (int k = 1; (1 << k) <= n; ++k) {
      for (int i = 0, j = 1 << (k - 1), T = n - (1 << k); i <= T; ++i, ++j)
        mk[k][i] = max(mk[k - 1][i], mk[k - 1][j]);
    }

    auto rmx = [&](int l, int r) {
      if (r < l)
        swap(l, r);
      int k = 31 - __builtin_clz(static_cast<uint32_t>(r - l + 1));
      return max(mk[k][l], mk[k][r - (1 << k) + 1]);
    };

    vector<pair<int, int>> hb, ha;
    for (int i = 0; i < n; ++i) {
      ha.emplace_back(a[i], i);
      hb.emplace_back(b[i], i);
    }
    sort(hb.begin(), hb.end());
    sort(ha.begin(), ha.end());
    int u = 0;
    vector<int> ls;
    set<int> ud;
    auto in_ud = [&](int l, int r) {
      if (r < l)
        swap(l, r);
      auto it = ud.upper_bound(l);
      return it != ud.end() && *it < r;
    };
    for (int p = 0, q = 0; p < n; p = q) {
      while (q < n && hb[q].first == hb[p].first)
        q++;
      const auto lv = hb[p].first;
      while (u < n && ha[u].first < lv)
        ++u;
      if (u >= n || ha[u].first != lv) {
        ok = false;
        break;
      }
      ls.clear();
      while (u < n && ha[u].first == lv) {
        ls.emplace_back(ha[u++].second);
      }
      for (int i = p, j = 0; i < q; ++i) {
        const auto x = hb[i].second;
        while (j + 1 < ls.size() && ls[j + 1] <= x)
          ++j;
        if (ls[j] == x)
          continue;
        if (!in_ud(ls[j], x) && rmx(ls[j], x) == lv)
          continue;
        if (j + 1 == ls.size() || in_ud(x, ls[j + 1]) ||
            rmx(x, ls[j + 1]) > lv) {
          ok = false;
          break;
        }
      }
      if (!ok)
        break;

      for (int i = p; i < q; ++i)
        ud.emplace(hb[i].second);
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}

// vim: ts=2 sw=2
