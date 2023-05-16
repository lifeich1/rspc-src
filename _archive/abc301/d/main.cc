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

    string s; int64_t n; cin >> s >> n;
    auto mn = [](string_view s) ->int64_t{
        int64_t r = 0;
        for_each(s.begin(), s.end(), [&](char c) {
                r<<=1;
                    if (c=='1') r++;
                });
        return r;
    };
    for_each(s.begin(), s.end(), [&](char &c) {
             if (c == '?') {
                c='1';
              if (mn(s) > n) c = '0';
             }
            });
    auto t = mn(s);
    cout << (t <= n ? t : -1)<<endl;;
    return 0;
}

