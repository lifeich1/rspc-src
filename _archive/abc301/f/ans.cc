#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
#define pnt __builtin_popcount
#define pb push_back
#define couty cout<<"Yes"<<'\n'
#define coutn cout<<"No"<<'\n'
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if(a<b){a=b; return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if(b<a){a=b; return true;}return false;}

// #include <atcoder/all>
// using namespace atcoder;

//const int mod = 1000000007;
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};


int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=s.size();
    vector dp(n+1,vector(27,vector(3,mint(0))));
    dp[0][0][0]=1;
    set<char> st;
    int cnt=0;
    rep(i,n){
        rep(j,27){
          // cout<<"ij"<<i<<" "<<j<<endl;
            if(s[i]=='?'){
                cnt++;
                //小文字を追加
                rep(k,2)dp[i+1][j][k]+=dp[i][j][k]*26;

                //大文字を追加
                dp[i+1][1][1]+=dp[i][j][0]*26;

                dp[i+1][min(j+1,26)][1]+=dp[i][j][1]*(26-j);
                dp[i+1][j][2]+=dp[i][j][1]*j;

                dp[i+1][min(j+1,26)][2]+=dp[i][j][2]*(26-j);
                dp[i+1][j][2]+=dp[i][j][2]*j;
            }else if((s[i]-'A')>=0&&(s[i]-'A')<=25){
                if(st.find(s[i])==st.end()){
                    /*要修正*/
                    mint coef=mint(26-j)/mint(26-st.size());
                    // cout<<"coef"<<coef.x<<endl;
                    // dp[i+1][min(j+1,26)][1]+=dp[i][j][0];    
                    // dp[i+1][min(j+1,26)][1]+=dp[i][j][1];    
                    // dp[i+1][min(j+1,26)][2]+=dp[i][j][2];
                    dp[i+1][min(j+1,26)][1]+=dp[i][j][0]*coef;    
                    dp[i+1][min(j+1,26)][1]+=dp[i][j][1]*coef;    
                    dp[i+1][min(j+1,26)][2]+=dp[i][j][2]*coef;
// 
                    dp[i+1][j][1]+=dp[i][j][0]*(mint(1)-coef);    
                    dp[i+1][j][2]+=dp[i][j][1]*(mint(1)-coef);    
                    dp[i+1][j][2]+=dp[i][j][2]*(mint(1)-coef);


                }else{
                    dp[i+1][j][1]+=dp[i][j][0];
                    dp[i+1][j][2]+=dp[i][j][1];
                    dp[i+1][j][2]+=dp[i][j][2];
                }
                
            }else{
                rep(k,2)dp[i+1][j][k]+=dp[i][j][k];
            }
            // cout<<"dp "<<i+1<<" "<<j<<endl;
            // cout<<dp[i+1][j][0].x<<endl;
            // cout<<dp[i+1][j][1].x<<endl;
            // cout<<dp[i+1][j][2].x<<endl;
        }
        if((s[i]-'A')>=0&&(s[i]-'A')<=25)st.insert(s[i]);
    }
    // cout<<dp[1][1][1].x<<endl;    
    // cout<<dp[2][1][1].x<<endl;
    mint ans=0;
    rep(i,27)ans+=dp[n][i][2];
    // cout<<ans.x<<endl;
    vector dp2(n+1,vector(3,mint(0)));
    rep(i,n){
        rep(j,27)dp2[i+1][0]+=dp[i+1][j][2];
    }
    rep(i,n){
        // cout<<"dp2 "<<dp2[i][0].x<<" "<<dp2[i][1].x<<" "<<dp2[i][2].x<<endl;
        if(s[i]=='?'){
            dp2[i+1][1]+=dp2[i][0]*26;
            dp2[i+1][2]+=dp2[i][1]*26;
            dp2[i+1][1]+=dp2[i][1]*26;
            dp2[i+1][2]+=dp2[i][2]*52;
        }else if((s[i]-'A')>=0&&(s[i]-'A')<=25){
            dp2[i+1][2]+=dp2[i][1];
            dp2[i+1][2]+=dp2[i][2];
        }else{
            dp2[i+1][1]+=dp2[i][0];
            dp2[i+1][1]+=dp2[i][1];
            dp2[i+1][2]+=dp2[i][2];
        }
    }

    // cout<<"dp2 "<<dp2[n][0].x<<" "<<dp2[n][1].x<<" "<<dp2[n][2].x<<endl;
    cnt/=27;
    cout<<(mint(52).pow(cnt)-dp2[n][2]).x<<endl;
}
