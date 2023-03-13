#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000310
int t,n,m,tot,val[N],tmp[N];

struct Reg {int l,r,w;} reg[N];
bool cmp(Reg a,Reg b) {return a.r < b.r;}

int Discretize(int *b,int n) 
{
    sort(b + 1,b + n + 1);
    int len = unique(b + 1,b + n + 1) - b - 1;

    for(int i = 1;i <= n;++i) {
        reg[i].l = lower_bound(b + 1,b + len + 1,reg[i].l) - b;
        reg[i].r = lower_bound(b + 1,b + len + 1,reg[i].r) - b;
    }
    return len;
}
int work()
{
    sort(reg + 1,reg + 1 + tot,cmp);
    //for(int i = 1;i <= tot;++i) cout<<reg[i].l<<"-"<<reg[i].r<<"-"<<reg[i].w<<endl;

    int cnt = 0;
    for(int i = 1;i <= tot;++i) tmp[++cnt] = reg[i].l,tmp[++cnt] = reg[i].r;
    int len = Discretize(tmp,cnt);
    //for(int i = 1;i <= tot;++i) cout<<reg[i].l<<" "<<reg[i].r<<" "<<reg[i].w<<endl;
    vector<int> dp(3 * tot,0),maxx(3 * tot,0);

    int pos = 1,ans = 0;
    for(int i = 1;i <= tot;++i) {

        // for(int i = 0;i <= pos;++i) cout<<maxx[i]<<"  ";
        // cout<<endl;
        // for(int i = 0;i <= pos;++i) cout<<dp[i]<<"  ";
        // cout<<endl;

        while(pos + 1 <= reg[i].r) maxx[pos] = max(dp[pos],maxx[pos - 1]),pos++;
        
        dp[reg[i].r] = max(dp[reg[i].r],maxx[reg[i].l - 1] + reg[i].w + 1);
       // cout<<reg[i].r<<": "<<dp[reg[i].r]<<endl;
        ans = max(ans,dp[reg[i].r]);

    }
    return ans;
}
void cal()
{
    vector<int> maxx(m + 1,0);
    for(int i = 1;i <= m;++i) maxx[i] = max(maxx[i - 1],val[i]);

    stack<int> sk;
    for(int i = m;i >= 1;--i) {
        while(sk.empty() == false && val[sk.top()] <= val[i]) sk.pop();
        if(maxx[i - 1] <= val[i]) reg[++tot] = {val[i],val[m],sk.size()};
        sk.push(i);
    }
}
signed main()
{
    ios::sync_with_stdio(false);

    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i <= n;++i) {
            cin>>m;
            int maxx = 0;
            for(int j = 1;j <= m;++j) cin>>val[j],maxx = max(maxx,val[j]);
            for(int j = 1;j <= m;++j) if(maxx == val[j]) m = j;
            cal();
        }
        cout<<work()<<endl;
        tot = 0;
    }

    return 0;
}
