#include <iostream>
#include <algorithm>
#include <vector>
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
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#endif

    int n;
    cin >> n;
    vector<int> a;
    for (; n > 0; n /= 10) a.push_back(n % 10);
    sort(a.begin(), a.end());
    auto q = [](int a, int b) { return a * 10 + b; };
    int l = accumulate(a.begin(), a.end(), 0, q);
    int r = accumulate(a.rbegin(), a.rend(), 0, q);
    cout << r - l << endl;
    return 0;
}

