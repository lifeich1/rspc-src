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

int n = 1;
#if defined(RSPC_TRACE_HINT)
const int N = 3030;
vector<int> e[N];
int f[N], m[N], qq;
random_device rd;
mt19937 rdmt;
#endif

void init() {
#if defined(RSPC_TRACE_HINT)
  n++;
  rdmt.seed(rd());
  for (int i = 1; i <= n; ++i)
    m[i] = i;
  for (int i = 2; i <= n; ++i) {
    uniform_int_distribution dist{0, i - 1};
    int t = dist(rdmt);
    if (t != 0)
      swap(m[i], m[i - t]);
  }
  for (int i = 0; i <= n; ++i)
    e[i].clear();
#if 0
  n = 6;
  int a[] = {1, 4, 2, 5, 3, 6};
  copy_n(a, n, m + 1);
#endif
  TV(n);
  TI(m + 1, m + n + 1, cerr << _ << ' ');
  cerr << endl;
  qq = 0;
#else
  cin >> n;
#endif
}

void q1(int x) {
#if defined(RSPC_TRACE_HINT)
  ++qq;
  TLN(TV(qq); cerr << "q1 "; TV(x));
  for (int i = 1; i <= n; ++i)
    if (x - i > 0 && x - i != i)
      e[i].emplace_back(x - i);
#else
  cout << "+ " << x << endl << flush;
  int t;
  cin >> t;
  if (1 != t)
    exit(0);
#endif
}

#if defined(RSPC_TRACE_HINT)
void dfs(int r, int v) {
  if (v >= f[r])
    return;
  f[r] = v;
  for (int y : e[r])
    dfs(y, v + 1);
}
#endif

int q2(int x, int y) {
  TLN(cerr << "q2 "; TV(x); TV(y));
  int r = -1;
#if defined(RSPC_TRACE_HINT)
  ++qq;
  TLN(TV(qq); TV(m[x]); TV(m[y]));
  x = m[x];
  y = m[y];
  fill(f, f + n + 1, n + 1);
  dfs(x, 0);
  if (f[y] <= n)
    r = f[y];
#else
  cout << "? " << x << ' ' << y << endl << flush;
  cin >> r;
#endif
  return r;
}

void ans(vector<int> const &v1, vector<int> const &v2) {
  TLN(cerr << __func__ << ' '; TA(v1, cerr << _ << ' ');
      TA(v2, cerr << _ << ' '));
#if defined(RSPC_TRACE_HINT)
  ++qq;
  if (equal(v1.begin(), v1.end(), m + 1) ||
      equal(v2.begin(), v2.end(), m + 1)) {
    cout << "OK\n";
    if (qq > n + n) {
      TLN(TV(qq));
      exit(1);
    }
  } else {
    cout << "WA\n";
    exit(1);
  }
#else
  cout << "! ";
  copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
  copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
  cout << endl << flush;
  int t;
  cin >> t;
  if (t != 1)
    exit(0);
#endif
}

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
    init();
    q1(n + 1);
    q1(n);
    vector<int> d(n, 0);
    for (int i = 1; i < n; ++i)
      d[i] = q2(1, i + 1);
    int ed = max_element(d.begin(), d.end()) - d.begin();
    fill(d.begin(), d.end(), -1);
    d[ed] = 0;
    set<int> s;
    for (int i = 0, k = n - 2; i < n && k > 0; ++i)
      if (i != ed) {
        d[i] = q2(ed + 1, i + 1);
        s.emplace(d[i]);
        --k;
      }
    TLN(TA(d, cerr << _ << ' '));
    for (int i = 0; i < n; ++i)
      if (d[i] < 0) {
        for (int t = 1; t < n; ++t)
          if (s.find(t) == s.end()) {
            d[i] = t;
            break;
          }
        break;
      }
    vector<int> a1(n, 0), a2(n, 0);
    vector<int> b;
    for (int l = 1, r = n; l <= r;) {
      b.emplace_back(r--);
      if (l <= r)
        b.emplace_back(l++);
    }
    TLN(TA(b, cerr << _ << ' '));
    for (int i = 0; i < n; ++i) {
      a1[i] = b[d[i]];
      a2[i] = b[n - 1 - d[i]];
    }
    TLN(TA(d, cerr << _ << ' '));
    ans(a1, a2);
  }
  return 0;
}

// vim: ts=2 sw=2
