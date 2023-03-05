#include <iostream>
#include <vector>
#include <algorithm>
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
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#endif

    int tt;
    cin >> tt;
    vector<string> sk;
    vector<size_t> snp;
    string op, name;
    while (tt--) {
        cin >> op;
        if (op.front() == 'p') {
            cin >> name;
            if (name == "snowcoat") snp.push_back(sk.size());
            else sk.push_back(name);
        } else if (op.front() == 'i') {
            if (snp.empty()) {
                cout << "oopsimcold :(\n";
            } else {
                cout << "winner winner chicken dinner :)\n";
                snp.pop_back();
            }
        } else if (op.front() == 'g') {
            if (!snp.empty() && snp.back() == sk.size()) {
                snp.pop_back();
                cout << "snowcoat\n";
            } else if (sk.empty()) {
                cout << "empty\n";
            } else {
                cout << sk.back() << endl;
                sk.pop_back();
            }
        }
    }
    return 0;
}

