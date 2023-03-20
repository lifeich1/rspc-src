#include <bits/stdc++.h>

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

const int N = 501001;
bool appear[N];

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

    int cal = 0, recal = 1;
    int n; cin >> n;
    fill(appear, appear + n, false);
    int tt; cin >> tt; while (tt--) {
        int op, x;
        cin >> op;
        switch (op) {
            case 1: {
                        ++cal; break;
                    }
            case 2: {
                        cin >> x;
                        appear[x] = true;
                        break;
                    }
            case 3: {
                        while (appear[recal]) recal++;
                        cout << recal << endl;
                        break;
                    }
        }
    }
    return 0;
}

