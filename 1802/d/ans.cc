/*#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,popcnt,bmi,bmi2,abm")*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ld long double
#define fr first
#define sc second
#define pll pair<long long, long long>
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

const ll inf=1000000000000;
const ll num1=1ll<<63-1;
const ll num2=1ll<<61-1;
const ll num3=1ll<<59-1;

pii arr[500000];
ll t[2000000];
set<ll> begone;
ll n, ans;

void preprocess()
{

}


void build(int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v]=arr[tl].sc;
        return;
    }
    int tm=(tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v]=max(t[v*2], t[2*v+1]);
}

ll q(int v, int tl, int tr, int l, int r)
{
    if(tl>r || tr<l || l>r)    return -inf;
    if(tl>=l && tr<=r)  return t[v];
    int tm=(tl+tr)/2;
    return max(q(2*v, tl, tm, l, r), q(2*v+1, tm+1, tr, l, r));
}

void firstop()
{
    ans=abs(arr[0].fr-q(1, 0, n-1, 1, n-1));
    begone.insert(arr[0].sc);
}

void solve()
{
    cin>>n;
    ans=inf;
    for(int i=0; i<n; i++)  cin>>arr[i].fr>>arr[i].sc;
    sort(arr, arr+n);

    build(1, 0, n-1);

    firstop();
    for(int i=1; i<n; i++)
    {
        ll k=q(1, 0, n-1, i+1, n-1);
        if(k>arr[i].fr)
        {
            ans=min(ans, k-arr[i].fr);
            begone.insert(arr[i].sc);
            continue;
        }
        if(k==arr[i].fr)
        {
            ans=0;
            break;
        }
        auto ind = begone.lower_bound(arr[i].fr);
        if(ind==begone.end())
        {
            ind--;
            if(*ind>k)  k=*ind;
            ans=min(ans, abs(k-arr[i].fr));
            begone.insert(arr[i].sc);
            continue;
        }
        if(ind!=begone.begin())
        {
            auto i2=ind;
            i2--;
            ans=min({ans, abs(k-arr[i].fr), abs(*ind-arr[i].fr), abs(*i2-arr[i].fr)});
            begone.insert(arr[i].sc);
            continue;
        }
        ans=min({ans, abs(k-arr[i].fr), abs(*ind-arr[i].fr)});
        begone.insert(arr[i].sc);
    }
    begone.clear();
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //preprocess();
    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        solve();
    }
    return 0;
}

