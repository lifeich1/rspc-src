// LUOGU_RID: 123728150
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=204;
int n;
ll ans;
ll x[N],l[N];
vector<ll>arr;

inline bool check(ll pos){
	int p2=lower_bound(x,x+n+2,pos)-x,p1=p2-1,p=1;
	while(p1>=1||p2<=n){
		if(pos-x[p1]<x[p2]-pos){
			if(pos-x[p1]<=l[p])p1--,p++;
			else return 0;
		}
		else{
			if(x[p2]-pos<=l[p])p2++,p++;
			else return 0;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	x[0]=-4e18,x[n+1]=4e18;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)cin>>l[i];
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			arr.push_back(x[i]-l[j]-1);
			arr.push_back(x[i]+l[j]);
		}
	sort(arr.begin(),arr.end());
	ll lst=0;
	for(ll i:arr){
		if(check(i))ans+=i-lst;
		lst=i;
	}
	cout<<ans;
}
/*
发现有效区间只有n^2个
每个区间内虽然决策不一定相同，但是都不会被卡到上界（除了左右端） 
*/