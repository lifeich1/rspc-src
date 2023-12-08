#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 1e6 + 10, MOD = 998244353;
const ULL base = 13331;;

int n, q;
string S;
ULL h[N];

struct Node
{
    int l, r;
    ULL pre, suf;
}tr[N * 4];

void push_up(int u)
{
	int len_pre = tr[u << 1].r - tr[u << 1].l + 1;
	int len_suf = tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1;
	tr[u].pre = tr[u << 1].pre * h[len_suf] + tr[u << 1 | 1].pre;
	tr[u].suf = tr[u << 1 | 1].suf * h[len_pre] + tr[u << 1].suf;
}

void build(int u, int l, int r)
{
    if(l == r)
    {
        tr[u].l = l, tr[u].r = r, tr[u].suf = tr[u].pre = S[l];
        return;
    }
    tr[u].l = l, tr[u].r = r;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void modify(int u, int d, char x)
{
    if(d == tr[u].l && tr[u].r == d)
    {
        tr[u].suf = tr[u].pre = x;
        return;
    }
    
    int mid = tr[u].l + tr[u].r >> 1;
    if(d <= mid) modify(u << 1, d, x);
    else modify(u << 1 | 1, d, x);
    push_up(u);
}

pair<ULL, ULL> query_pre(int u, int l, int r)
{
    if(l <= tr[u].l && tr[u].r <= r) return {tr[u].pre, tr[u].r - tr[u].l + 1};
    
    int mid = tr[u].l + tr[u].r >> 1;
    pair<ULL, ULL> L, R;
    if(l <= mid) L = query_pre(u << 1, l, r);
    if(r > mid) R = query_pre(u << 1 | 1, l, r);
    pair<ULL, ULL> res = {L.first * h[R.second] + R.first, L.second + R.second};
    return res;
}

pair<ULL, ULL> query_suf(int u, int l, int r)
{
    if(l <= tr[u].l && tr[u].r <= r) return {tr[u].suf, tr[u].r - tr[u].l + 1};
    
    int mid = tr[u].l + tr[u].r >> 1;
    pair<ULL, ULL> L, R;
    if(l <= mid) L = query_suf(u << 1, l, r);
    if(r > mid) R = query_suf(u << 1 | 1, l, r);
    pair<ULL, ULL> res = {R.first * h[L.second] + L.first, L.second + R.second};
    return res;
}


void solve()
{
    
    cin >> n >> q;
    cin >> S; S = '#' + S;

	h[0] = 1;
	for(int i = 1;i < N;i ++) h[i] = h[i - 1] * base;
	
	build(1, 1, n);
	
	while (q--)
	{
		int op; cin >> op;
		if(op == 1)
		{
		    int d; 
            char c;
            cin >> d >> c;
            modify(1, d, c);
		}
		else
		{
		    int l, r; cin >> l >> r;
		    if(query_pre(1, l, r).first == query_suf(1, l, r).first) cout << "Yes" << '\n';
		    else cout << "No" << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1; //cin >> T;
    while(T --) solve();
    return 0;
    
}