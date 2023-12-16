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

int a[8][8], b[8][8];

int main() {
#if defined(RSPC_TRACE_BTIME)
  TRACE(cerr << "build time: " RSPC_TRACE_BTIME "\n");
#else
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#endif

  int H, W;
  cin >> H >> W;
  map<int, int> ca, cb;
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j) {
      cin >> a[i][j];
      ca[a[i][j]]++;
    }
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j) {
      cin >> b[i][j];
      cb[b[i][j]]++;
    }
  if (ca.size() != cb.size() || !equal(ca.begin(), ca.end(), cb.begin())) {
    cout << "-1\n";
    return 0;
  }
  vector<int> hs;
  for (auto [k, _] : ca)
    hs.emplace_back(k);
  sort(hs.begin(), hs.end());
  for (int i = 0; i < hs.size(); ++i)
    ca[hs[i]] = i;
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j) {
      a[i][j] = ca[a[i][j]];
      b[i][j] = ca[b[i][j]];
    }
  vector<int> st;
  for (int i = 0; i < H; ++i) {
    int t = 0;
    for (int j = 0; j < W; ++j) {
      t = (t << 5) + a[i][j];
    }
    st.emplace_back(t);
  }
  for (int i = 0; i < H; ++i) {
    int t = 0;
    for (int j = 0; j < W; ++j) {
      t = (t << 5) + b[i][j];
    }
    st.emplace_back(t);
  }
  if (equal(st.begin(), st.begin() + H, st.begin() + H)) {
    cout << "0\n";
    return 0;
  }
  auto swcl = [&](vector<int> &v, int i) {
    for (int k = H; k < v.size(); ++k) {
      int t1 = v[k] & ((1 << (i * 5 + 5)) - (1 << (i * 5)));
      int t2 = v[k] & ((1 << (i * 5 + 10)) - (1 << (i * 5 + 5)));
      v[k] ^= t1 ^ t2;
      v[k] ^= (t1 << 5) ^ (t2 >> 5);
    }
  };
  map<vector<int>, int> f;
  vector<pair<vector<int>, int>> ls = {{st, 1}};
  auto upa = [&](auto &&v, int k) {
    auto &t = f[v];
    if (0 == t) {
      ls.emplace_back(v, k);
      t = k;
    } else
      return false;
    return (equal(v.begin(), v.begin() + H, v.begin() + H));
  };
  f[st] = 1;
  for (int p = 0; p < ls.size(); ++p) {
    const auto x = ls[p].first;
    const auto v = ls[p].second;

    for (int i = 1; i < H; ++i) {
      vector<int> y(x);
      swap(y[i], y[i - 1]);
      if (upa(std::move(y), v + 1)) {
        cout << v << endl;
        return 0;
      }
    }
    for (int i = 1; i < W; ++i) {
      vector<int> y(x);
      swcl(y, i - 1);
      if (upa(std::move(y), v + 1)) {
        cout << v << endl;
        return 0;
      }
    }
  }
  cout << "-1\n";
  return 0;
}

// vim: ts=2 sw=2
