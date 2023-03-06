#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <map>
#include <unordered_map>

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

string hashup(const char * s, int n) {
    string a = "000000000000000000000000000";
    a[26] = ((n & 1) ? 'o' : 'e');
    for_each(s, s + n, [&](char const & c) {
                char & d = a[c - 'a'];
                d = (d == '1') ? '2' : '1';
            });
    return a;
}

bool flap(string const & s, string & d, const int zp) {
    if (s[zp] != '0') return false;
    d.resize(27, '0');
    d[26] = (s[26] == 'o') ? 'e' : 'o';
    for (int i = 0; i < 26; ++i) {
        if (zp == i) d[i] = '0';
        else if (s[i] == '0') d[i] = '1';
        else if (s[i] == '1') d[i] = 'e';
        else if (s[i] == '2') d[i] = '1';
    }
    return true;
}

char st[5001010];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    unordered_map<string, int> cnt;
    int n;
    cin >> n;
    int64_t ans = 0;
    for (int ii = 0; ii < n; ++ii) {
        cin >> st;
        const int l = strlen(st);
        string h = hashup(st, l);
        string f;
        for (int zp = 0; zp < 26; ++zp) {
            if (flap(h, f, zp)) {
                auto it = cnt.find(f);
                if (it != cnt.end()) ans += it->second;
            }
        }
        f = h;
        for_each(f.begin(), f.end(),
                [](char & c) { if (c == '0' || c == '2') c = 'e'; });
        for (int zp = 0; zp < 26; ++zp) {
            if (h[zp] == '0') {
                f[zp] = '0';
                cnt[f] ++;
                f[zp] = 'e';
            }
        }
    }
    cout << ans << endl;

    return 0;
}

