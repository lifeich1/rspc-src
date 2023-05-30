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

const int N = 201001;
int a[N],b[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        copy_n(std::istream_iterator<int>(std::cin),n,a);
        copy_n(std::istream_iterator<int>(std::cin),n,b);
        map<int,map<int,int>> bc4a;
        for (int i = 0; i < n; ++i) {
            bc4a[a[i]][b[i]]++;
        }
        int64_t ans = 0;
        auto va = [](const auto & m, int x) {
            if (m.count(x) == 0) return 0;
            return m.at(x);
        };
        for (const auto& [ia, bc] : bc4a) {
            int s = ia * ia;
            if (s > n + n) break;
            auto l = bc.begin(); auto r = bc.rbegin();
            for (; l != bc.end() && r != bc.rend(); ) {
                if (l->first > r->first) break;
                const auto v = l->first + r->first;
                if (v > s) {
                    ++r; continue;
                }
                if (v == s) {
                    if (l->first != r->first) {
                        ans += int64_t(l->second) * r->second;
                    } else {
                        int64_t t = l->second;
                        ans += t * (t - 1) / 2;
                    }
                    TRACELN(cout<<"a "<<ia<<' '<<l->first<<' '<<l->second
                            <<' '<<r->first<<' '<<r->second<<"  "<<ans);
                }
                ++l;
            }
            for (auto it = bc4a.upper_bound(ia); it != bc4a.end(); ++it) {
                const auto & [ja, jb] = *it;
                s = ja * ia;
                if (s > n + n) break;
                auto l = bc.begin(); auto r = jb.rbegin();
                for (; l != bc.end() && r != jb.rend(); ) {
                    const auto v = l->first + r->first;
                    if (v > s) {
                        ++r; continue;
                    }
                    if (v == s) {
                        ans += int64_t(l->second) * r->second;
                        TRACELN(cout<<"b "<<ia<<' '<<ja<<' '<<l->first<<' '<<l->second
                                <<' '<<r->first<<' '<<r->second<<"  "<<ans);
                    } ++l;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

