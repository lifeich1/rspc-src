#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
using namespace std;
#define ll long long int


ll test()
{
    int n,m;
    cin >> n>>m;
    
    ll l, r;
    cin >> l >> r;
    n -= 2;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A.begin(), A.end());

    ll min_cost = 1e17;
    n -= m;
    for (int i = 0; i <= n; i++)
    {
        ll first = A[i];
        ll last = A[i + m - 1];

        ll cost = 0;
        if (first < l)
            cost += (l - first);
        if (last > r)
            cost += (last-r);
        min_cost = cost < min_cost ? cost : min_cost;
    }
    cout << min_cost << endl;
    return 0;
}

int main()
{
    //int t;
    //cin >> t;
    //while (t--)
        //cout << test() << endl;
        test();
}
