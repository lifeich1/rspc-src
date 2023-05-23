#include <bits/stdc++.h>
using namespace std;

int main(void){
	vector<int>p;
	for(int i=0;i<4;i++)p.push_back(i);

	int n;
	cin>>n;

	vector<int>a(n),b;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int j=1;j<=4;j++)for(int i=0;i<n;i++)if(a[i]==j)b.push_back(j);

	vector<vector<int> >c(4,vector<int>(4));
	for(int i=0;i<n;i++)c[a[i]-1][b[i]-1]++;

	int s,ans=0;
	while(true){
		s=0;
		for(int i=0;i<4;i++)for(int j=i+1;j<4;j++)s+=c[p[i]][p[j]];
		ans=max(ans,s);
		if(!next_permutation(p.begin(),p.end()))break;
	}
	cout<<ans<<endl;
	return 0;
}
