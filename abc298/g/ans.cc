#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
#define pcount __builtin_popcount
#define couty cout<<"Yes"<<'\n';
#define coutn cout<<"No"<<'\n';
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if(a<b){a=b; return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if(b<a){a=b; return true;}return false;}

// #include <atcoder/all>
// using namespace atcoder;

const ll INF=1e18;

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int h,w,T;
    cin>>h>>w>>T;
    vector s(h,vector(w,0ll));
    rep(i,h)rep(j,w)cin>>s[i][j];
    vector cum(h+1,vector(w+1,0ll));
    rep(i,h)rep(j,w)cum[i+1][j+1]=s[i][j]+cum[i][j+1]+cum[i+1][j]-cum[i][j];
    auto get_area=[&](int a, int b, int c, int d)->ll{
        return cum[c][d]+cum[a][b]-cum[c][b]-cum[a][d];
    };
    ll ans=INF;
    for(int a=0; a<h; a++)for(int c=a+1; c<=h; c++)for(int b=0; b<w; b++)for(int d=b+1; d<=w; d++){
        ll m=get_area(a,b,c,d);
        // cout<<a<<" "<<c<<" "<<b<<" "<<d<<" "<<m<<endl;
        vector dp(h,vector(h+1,vector(w,vector(w+1,vector(T+1,INF)))));
        for(int t=0; t<=T; t++){
            for(int a=0; a<h; a++)for(int c=a+1; c<=h; c++)for(int b=0; b<w; b++)for(int d=b+1; d<=w; d++){
                    if(t==0){dp[a][c][b][d][t]=get_area(a,b,c,d);}
                    for(int i=a+1; i<c; i++)for(int j=0;j<t;j++){
                        chmin(dp[a][c][b][d][t],max(dp[a][i][b][d][j],dp[i][c][b][d][t-1-j]));
                        chmin(dp[a][c][b][d][t],max(dp[i][c][b][d][j],dp[a][i][b][d][t-1-j]));
                    }
                    for(int i=b+1; i<d; i++)for(int j=0;j<t;j++){
                        chmin(dp[a][c][b][d][t],max(dp[a][c][b][i][j],dp[a][c][i][d][t-1-j]));
                        chmin(dp[a][c][b][d][t],max(dp[a][c][i][d][j],dp[a][c][b][i][t-1-j]));
                    }
                    if(dp[a][c][b][d][t]<m)dp[a][c][b][d][t]=INF;
                    // cout<<a<<" "<<c<<" "<<b<<" "<<d<<" t:  "<<t<<" : "<<dp[a][c][b][d][t]<<endl;
                    
            }
        }
        chmin(ans,dp[0][h][0][w][T]-m);
    }
    // rep(i,h+1){
        // rep(j,w+1)cout<<cum[i][j]<<" ";
        // cout<<endl;
    // }
    cout<<ans<<endl;
}
