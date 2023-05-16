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

    string ss = "atcoder@";
bool cc1(char a, char b) {
    if (a == b) return true;
    if (a == '@') swap(a, b);
    if (b == '@' && ss.find(a) != string::npos) return true;
    return false;
}
bool cc(char a, char b) {
    auto r = cc1(a, b);
    TRACELN(cout << a << ' ' << b << ' ' << r);
    return r;
}

map<int,int> ri() {
    string s; cin >> s;
    map<int,int> m;
    for_each(s.begin(), s.end(), [&](char c) {
            m[c]++;
            });
    return m;
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif


    auto m1 = ri();
    auto m2 = ri();
    string ss = "atcoder";
    int k1 = 0, k2=0;
    for_each(ss.begin(), ss.end(), [&](char c) {
            auto & l = m1[c];auto &r = m2[c];
            if (l < r) {
             k1 += r - l;
            } else {
             k2 += l - r;
            }
            l = r = 0;
            });
    auto &a1 = m1['@'];
    auto &a2 = m2['@'];
    a1 -= k1, a2 -= k2;
    if (a1 < 0 || a2 < 0) {
        cout << "No\n";
        return 0;
    }
    cout << (equal(m1.begin(), m1.end(), m2.begin()) ? "Yes\n" : "No\n");
    return 0;
}

