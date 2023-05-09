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

int64_t a[8][8], s[8][8], f[8][8][8][8][40];

int64_t sm(int i, int j, int u, int v) {
    --i, --j;
    return s[u][v] - s[i][v] - s[u][j] + s[i][j];
}
int64_t sd(int i, int j, int d1, int d2) {
  return sm(i, j, i + d1, j + d2);
}
int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int h, w, T; cin >> h >> w >> T;
    ++T;
    for (int i = 0; i < h;++i) copy_n(std::istream_iterator<int64_t>(cin), w, a[i+1]+1 );
    vector<int64_t> lbs; lbs.reserve(h * (h+1) * w * (1+w) / 4);
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j) {
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            for (int t1 = 1; t1 <= i; ++t1)
            for (int t2 = 1; t2 <= j; ++t2) lbs .emplace_back (sm(t1, t2, i, j));
        }
    sort(lbs.begin(), lbs.end());
    lbs.erase(unique(lbs.begin(), lbs.end()), lbs.end());
    //TRACELN(cout<<lbs.size()<<':';copy(lbs.begin(), lbs.end(), std::ostream_iterator<int64_t>(cout," ")));
    vector<pair<int,int>> ds;
    for (int i = 1; i <= h; ++i)
      for (int j = 1; j <= w; ++j) ds .emplace_back (i - 1, j - 1);
    auto ans = s[h][w];
    for (auto lb: lbs){
      for (auto [d1, d2] : ds) {
        auto iu = h - d1, ju = w - d2;
        for (int i = 1; i <= iu; ++i)
          for (int j = 1; j <= ju; ++j) fill_n(f[i][j][d1][d2], T+2, -1);
      }
      //TRACELN(cout<<":"<<lb<<"  "<<f[1][1][h - 1][w - 1][T]);
      for (auto [d1, d2] : ds) {
        auto iu = h - d1, ju = w - d2;
        for (int i = 1; i <= iu; ++i)
          for (int j = 1; j <= ju; ++j) {
            auto t = sd(i, j, d1, d2);
            if (t >= lb) f[i][j][d1][d2][1] = t; 
            for (int tt = 2; tt <= T; ++tt) {
              auto &f1 = f[i][j][d1][d2][tt];
              for(int p = 0; p < d1; ++p) {
                for (int k = 1; k < tt; ++k) {
                  auto t = f[i][ j][ p][ d2][k];
                  if (t < lb) continue;
                  auto t2 = f[i + p + 1][j][d1 - p - 1][d2][tt-k];
                  if (t2 < lb) continue;
                  t = max(t, t2);
                  if (f1 < 0 || t < f1) {
                    f1 = t;
                    TRACE(if (i==1&&j==1&&d1==1&&d2==2&&tt==4) {
                        cout<<"--"<<p<<' '<<k<<' '<<t<<endl;
                        });
                  }
                }
              }
              for(int p = 0; p < d2; ++p) {
                for (int k = 1; k < tt; ++k) {
                  auto t = f[i][ j][ d1][ p][k] ;
                  if (t < lb) continue;
                  auto t2 = f[i][j+p+1][d1][d2-p-1][tt-k];
                  if (t2 < lb) continue;
                  t = max(t, t2);
                  if (f1 < 0 || t < f1) {
                    f1 = t;
                    TRACE(if (i==1&&j==1&&d1==1&&d2==2&&tt==4) {
                        cout<<"||"<<p<<' '<<k<<' '<<t<<endl;
                        });
                  }
                }
              }
            }
          }
      }
      auto fm = f[1][1][h - 1][w - 1][T];
      if (fm != -1) {
        ans = min(ans, fm - lb);
        //TRACELN(cout<<ans<<' '<<lb<< ' '<<fm);
        auto sh = [&](auto *k) {
          copy_n(k + 1, T, std::ostream_iterator<int64_t> (cout," "));
        };
        //TRACELN(cout <<' ';sh(f[1][1][1][2]););
        //TRACELN(cout <<' ';sh(f[1][1][1][1]););
        //TRACELN(cout <<' ';sh(f[1][1][1][0]););
        //TRACELN(cout <<' ';sh(f[1][1][0][1]););
        //TRACELN(cout <<' ';sh(f[1][3][1][0]););
        //TRACELN(cout<<' '<<sd(1, 2, 1, 0)<<' '<<f[1][3][1][0][2]<<' '<<f[1][1][1][1][3]<<' '<<f[1][1][1][0][2]<<' '<<f[1][1][0][0][1]);
      }
    }
    cout << ans << endl;
    return 0;
}

// vim: ts=2 sw=2
