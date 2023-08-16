#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define SZ(v) ((int)v.size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
template<typename T1,typename T2>void chkmin(T1 &x,T2 y){if(x>y)x=y;}
template<typename T1,typename T2>void chkmax(T1 &x,T2 y){if(x<y)x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1<<23
char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
#ifdef LOCAL
inline char getc(){return getchar();}
inline void putc(char c){putchar(c);}
#else
inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
inline void putc(char x){*p3++=x;}
#endif
template<typename T>void read(T &x){
	x=0;char c=getc();T neg=0;
	while(!isdigit(c))neg|=(c=='-'),c=getc();
	while(isdigit(c))x=x*10+(c-'0'),c=getc();
	if(neg)x=-x;
}
template<typename T>void recursive_print(T x){if(!x)return;recursive_print(x/10);putc(x%10^48);}
template<typename T>void print(T x){if(!x)putc('0');if(x<0)putc('-'),x=-x;recursive_print(x);}
template<typename T>void print(T x,char c){print(x);putc(c);}
void readstr(char *s){char c=getc();while(c<=32||c>=127)c=getc();while(c>32&&c<127)s[0]=c,s++,c=getc();(*s)=0;}
void printstr(string s){for(int i=0;i<s.size();i++)putc(s[i]);}
void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++)putc(s[i]);}
void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
#endif
const int MAXN=1e6;
int qu,a[MAXN+5],t[MAXN+5],len;
void add(int x,int v){for(int i=x;i<=MAXN;i+=(i&(-i)))t[i]+=v;}
int query(int x){int ret=0;for(int i=x;i;i&=(i-1))ret+=t[i];return ret;}
stack<tuple<int,int,int,int,int> >stk;
set<int>st[MAXN+5];
int main(){
	scanf("%d",&qu);
	for(int i=1;i<=MAXN+1;i++)st[0].insert(i);add(1,1);
	for(int i=1;i<=MAXN;i++)st[i].insert(MAXN+1);
	for(int _=1;_<=qu;_++){
		static char opt[5];scanf("%s",opt+1);
		if(opt[1]=='+'){
			int x;scanf("%d",&x);++len;bool flg=0;
			int p1=*st[a[len]].begin();
			st[a[len]].erase(st[a[len]].find(len));
			int p2=*st[a[len]].begin();
			add(p1,-1);add(p2,1);
			stk.push(mt(_,1,a[len],p1,p2));
			a[len]=x;
			p1=*st[a[len]].begin();
			st[a[len]].insert(len);
			p2=*st[a[len]].begin();
			add(p1,-1);add(p2,1);
			stk.push(mt(_,2,a[len],p1,p2));
		}else if(opt[1]=='-'){
			int k;scanf("%d",&k);
			stk.push(mt(_,3,k,0,0));len-=k;
		}else if(opt[1]=='!'){
			int tim=get<0>(stk.top());
			while(!stk.empty()&&get<0>(stk.top())==tim){
				tuple<int,int,int,int,int>t=stk.top();stk.pop();
				if(get<1>(t)==1){
					int x=get<2>(t),y=get<3>(t),z=get<4>(t);
					add(z,-1);add(y,1);st[x].insert(len);a[len]=x;
					--len;
				}else if(get<1>(t)==2){
					int x=get<2>(t),y=get<3>(t),z=get<4>(t);
					add(z,-1);add(y,1);st[x].erase(st[x].find(len));
				}else len+=get<2>(t);
			}
		}else printf("%d\n",query(len)),fflush(stdout);
	}
	return 0;
}