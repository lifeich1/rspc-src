#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
const int N =1e6+5;
signed main(void){
    ios::sync_with_stdio(false);cin.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		vector<int>a(n+1,0),b(n+1,0);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		vector<int>g(m+1,0);
		vector<vector<int> >f(n+1,vector<int>(4,-1e15));
		for(int i=1;i<=n;i++){
			for(int j=min(i,m);j;j--){
				for(int k=0;k<4;k++) f[i-j][k]=max(f[i-j][k],(k&1?1:-1)*a[i]+(k>>1?1:-1)*b[i]+g[j-1]);
				for(int k=0;k<4;k++) g[j]=max(g[j],(k&1?1:-1)*a[i]+(k>>1?1:-1)*b[i]+f[i-j][(k==0||k==3)?3-k:k]);  	
			}
		}
		cout<<g[m]<<"\n"; 
	}
    return 0;
}

