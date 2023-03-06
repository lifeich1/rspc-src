#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <cctype>

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

    string m = "meow";

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s;
        cin >> n >> s;
        for_each(s.begin(), s.end(), [](char & c) { c = tolower(c); });
        s.erase(unique(s.begin(), s.end()), s.end());
        cout << (s == m ? "YES" : "NO") << endl;
    }
    return 0;
}

