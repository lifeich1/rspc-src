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

const int N = 601001;
int x[N], y[N], f[N];

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
    int n, m;
    cin >> n;
    copy_n(std::istream_iterator<int>(std::cin), n, x);
    copy_n(std::istream_iterator<int>(std::cin), n, y);
    cin >> m;
    copy_n(std::istream_iterator<int>(std::cin), m, x + n);
    copy_n(std::istream_iterator<int>(std::cin), m, y + n);
    fill(f, f + n + m, 2);
    int x11 = *max_element(x, x + n);
    int x12 = *max_element(x + n, x + n + m);
    vector<int> ls;
    for (int i = 0; i < n; ++i)
      if (y[i] >= x12) {
        f[i] = 1;
        ls.emplace_back(i);
      }
    for (int i = n; i < n + m; ++i)
      if (y[i] >= x11) {
        f[i] = 1;
        ls.emplace_back(i);
      }
    set<pair<int, int>> sxl[3], sxr[3], syl[3], syr[3];
    for (int i = 0; i < n; ++i) {
      sxl[f[i]].emplace(x[i], i);
      syl[f[i]].emplace(y[i], i);
    }
    for (int i = n; i < n + m; ++i) {
      sxr[f[i]].emplace(x[i], i);
      syr[f[i]].emplace(y[i], i);
    }
    auto pus = [&](int u, int v) {
      f[u] = v;
      if (u < n) {
        sxl[v].emplace(x[u], u);
        syl[v].emplace(y[u], u);
      } else {
        sxr[v].emplace(x[u], u);
        syr[v].emplace(y[u], u);
      }
    };
    for (unsigned p = 0; p < ls.size(); ++p) {
      int u = ls[p];
      if (1 == f[u]) {
        if (u < n) {
          while (syr[2].size() && syr[2].begin()->first < x[u]) {
            auto t = syr[2].begin()->second;
            syr[2].erase(syr[2].begin());
            if (2 == f[t]) {
              pus(t, 0);
            }
          }
        } else {
          while (syl[2].size() && syl[2].begin()->first < x[u]) {
            auto t = syl[2].begin()->second;
            syl[2].erase(syl[2].begin());
            if (2 == f[t]) {
              pus(t, 0);
            }
          }
        }
      } else { // f[u] == 0, lose
        if (u < n) {
          int bt = -1;
          if (sxl[1].size())
            bt = sxl[1].rbegin()->first;
          while (sxl[2].size() && f[sxl[2].rbegin()->second] != 2) {
            auto it = sxl[2].end();
            sxl[2].erase(--it);
          }
          if (sxl[2].size())
            bt = max(bt, sxl[2].rbegin()->first);
          while (syr[2].size() && syr[2].rbegin()->first >= bt) {
            auto it = syr[2].end();
            --it;
            auto t = it->second;
            syr[2].erase(it);
            if (2 == f[t]) {
              pus(t, 1);
            }
          }
        } else {
          int bt = -1;
          if (sxr[1].size())
            bt = sxr[1].rbegin()->first;
          while (sxr[2].size() && f[sxr[2].rbegin()->second] != 2) {
            auto it = sxr[2].end();
            sxr[2].erase(--it);
          }
          if (sxr[2].size())
            bt = max(bt, sxr[2].rbegin()->first);
          while (syl[2].size() && syl[2].rbegin()->first >= bt) {
            auto it = syl[2].end();
            --it;
            auto t = it->second;
            syl[2].erase(it);
            if (2 == f[t]) {
              pus(t, 1);
            }
          }
        }
      }
    }
    cout << count(f, f + n, 1) << ' ' << count(f, f + n, 2) << ' '
         << count(f, f + n, 0) << endl;
  }
  return 0;
}

// vim: ts=2 sw=2
