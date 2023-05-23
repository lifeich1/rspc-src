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


int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int h, w;
    vector<string> ss;
    cin >> h>>w;
    copy_n(std::istream_iterator<string>(cin),h, std::back_inserter (ss));
    auto tr = [&](int x, int y, int d1, int d2) -> pair<string,vector<pair<int,int>>> {
        vector<pair<int,int>> r;
        string s;
        for (int l=0; x >= 0 && x < h && y >= 0&&y<w&&l<5; x+=d1,y+=d2,++l) {
            s += ss[x][y];
            r .emplace_back (x+1, y+1);
        }
        return {s, r};
    };
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w;++j) {
            for (int d1=-1;d1<2;++d1) {
            for (int d2=-1;d2<2;++d2) {
                auto [s, r] = tr(i,j,d1,d2);
                if ("snuke" == s) {
                    for (auto [x,y]:r) {
                        cout<< x<<' '<<y<<endl;
                    }
                    return 0;
                }
            }
            }
        }
    return 0;
}

