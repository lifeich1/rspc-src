#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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


int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> a;
        for (int i = 0; i < n * 2 - 2; ++i) {
            string s;
            cin >> s;
            a.emplace_back(std::move(s));
        }
        bool flag = true;
        for (int i = 1; i + i <= n; ++i) {
            size_t i_u = i;
            auto f = [=](string const & s) { return s.length() == i_u; };
            auto p1 = find_if(a.begin(), a.end(), f);
            auto p2 = find_if(p1 + 1, a.end(), f);
            TRACE(cout << p1 - a.begin() << ' ' << p2 - a.begin() << ' ' << a.size() << endl);
            string s2 = *p2;
            reverse(s2.begin(), s2.end());
            if (*p1 != s2) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}

