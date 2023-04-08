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

#define TTT 0
int tt, rr, cc;
string epp;

int ask(int x, int y) {
#if TTT
    int a=(tt/cc)+1,b=(tt%cc)+1;
    return max(abs(x-a),abs(y-b));
#else
    cout << "? "<< x<<' '<<y<<endl<<flush;
    int a;
    cin >> a;
    return a;
#endif
}

void getrc(int &r, int &c) {
#if TTT
    r=rr, c=cc;
#else
    cin >> r >> c;
#endif
}

void ans(int x, int y) {
#if TTT
    int a=(tt/cc)+1,b=(tt%cc)+1;
    if (a!=x||y!=b) {
        cout << "WA " << a << ' '<<b<<"  "<<x<<' '<<y<<endl;
    }else{
        //cout<<"ok "<<x<<' '<<y<<endl;
    }
#else
    cout << "! "<<x<<' '<<y<<endl<<flush;
#endif
}

int main() {
#if defined(RSPC_TRACE_BTIME)
    TRACE(cout << "build time: " RSPC_TRACE_BTIME "\n");
#else
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#endif

#if TTT
    rr=1788,cc=1788;
    tt=rr*cc;
#else
    cin >> tt;
#endif
        TRACELN(cout<<tt);
    while (tt--) {
        int r, c;
        getrc(r, c);
        int a1, a2, a3, ax =0, ay = 0;
        a1 = ask(1, 1);
        if (a1 >= c) ax = a1+1;
        else if (a1 >= r) ay = a1+1;
        if (ax||ay) {
            a2 = ask(max(1, ax), max(1, ay));
            if (ax) ay=a2+1; else ax=a2+1;
            ans(ax, ay);
            continue;
        }
        a2 = ask(1, c);
        if (a1+a2+1 != c && a1!=a2) {
            if (a1 < a2) ax=a1+1, ay=c-a2;
            else ax=a2+1,ay=a1+1;
        } else if (a1+a2+1 == c){
            ay=a1+1;
            ax=ask(1, ay) +1;
        }else {
            ax=a1+1;
            ay=ask(ax,1)+1;
        }
        ans(ax, ay);
    }
    return 0;
}

