#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
// typedef is used to create an alias for a data type
// #define is used to define a constant value
 
typedef long long ll;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<lli> vlli;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
 
#define pb(a) push_back(a)
#define pbr(a, b) pb(make_pair(a, b))
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define rfr(i, a, b) for (int i = a; i >= b; i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*
-> Generic Function for BFS traversal of a Graph
 (valid for directed as well as undirected graphs
 which can have multiple disconnected components)
-- Inputs --
-> V - represents number of vertices in the Graph
-> adj[] - represents adjacency list for the Graph
-- Output --
-> bfs_traversal - a vector containing bfs traversal
for entire graph
*/
//returns complete bfs traversal of graph
vector<int> bfstravel(int V, vector<int> adj[])
{
    vector<int> bfs_traversal;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; ++i) {
 
        // To check if already visited
        if (!vis[i]) {
            queue<int> q;
            vis[i] = true;
            q.push(i);
 
            // BFS starting from ith node
            while (!q.empty()) {
                int g_node = q.front();
                q.pop();
                bfs_traversal.push_back(g_node);
                for (auto it : adj[g_node]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfs_traversal;
}
//returns vector of number of nodes in each disconnected component of graph
vector<int> bfsComp(int V, vector<int> adj[])
{
    vector<int> bfs_traversal;
    vector<bool> vis(V, false);
    int count= 0;
    for (int i = 0; i < V; ++i) {
        // To check if already visited
        if (!vis[i]) {
            count=0;
            queue<int> q;
            vis[i] = true;
            q.push(i);
            count++;
            // BFS starting from ith node
            while (!q.empty()) {
                int g_node = q.front();
                q.pop();
                // 
                for (auto it : adj[g_node]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                        count++;
                    }
                }
            }
            bfs_traversal.push_back(count);
        }
    }
    return bfs_traversal;
}
//returns vector nodes in each disconnected component of graph
vector<vector<int>> bfsComp_ret_nodes(int V, vector<int> adj[])
{
    vector<vector<int>> bfs_traversal;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; ++i) {
        vector<int> mad;
        // To check if already visited
        if (!vis[i]) {
            queue<int> q;
            vis[i] = true;
            q.push(i);
            mad.push_back(i);
            // BFS starting from ith node
            while (!q.empty()) {
                int g_node = q.front();
                q.pop();
                // 
                for (auto it : adj[g_node]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                        mad.push_back(i);
                    }
                }
            }
            bfs_traversal.push_back(mad);
        }
    }
    return bfs_traversal;
}
//convert decimal to binary
string decimalToBinary(int n)
{
    //finding the binary form of the number and
    //converting it to string.
    string s = bitset<64> (n).to_string();
     
    //Finding the first occurrence of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');
     
    if(loc1 != string::npos)
        return s.substr(loc1);
     
    return "0";
}
//counting sort
string* optimizedCountingSort(string mad[], int n, int ith){
    int freq[10]={0};
    vector<pair<int,string>> sad;
    for (int i = 0; i < n; i++)
    {
        sad.push_back(make_pair(int(mad[i][ith])-48,mad[i]));
    }
    

    forn(i,n){
        freq[int(mad[i][ith])-48]+=1;
    }
    forn(i,10){
        if (i==0)
        {
            i++;
        }
        freq[i]+=freq[i-1];
    }
    pair<int,string> b[n];
    for (int i = n-1; i >= 0; i--)
    {
        b[freq[int(mad[i][ith])-48]-1]=sad[i];
        freq[int(mad[i][ith])-48]=freq[int(mad[i][ith])-48]-1;
    }
    for (int i = 0; i < n; i++)
    {
        mad[i]=b[i].second;
    }
    
    return mad;
    
}
//the 4 functions below are used for DFS traversal
class Graph {

	// A function used by DFS
	void DFSUtil(int v);

public:
	map<int, bool> visited;
	map<int, list<int> > adj;
	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints DFS traversal of the complete graph
	void DFS();
};
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}
void Graph::DFSUtil(int v)
{
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i);
}
void Graph::DFS()
{
	// Call the recursive helper function to print DFS
	// traversal starting from all vertices one by one
	for (auto i : adj)
		if (visited[i.first] == false)
			DFSUtil(i.first);
}
//median of two sorted arrays in log(m+n) time
float median(int nums1[],int nums2[],int m,int n) {
    int finalArray[n+m];
    int i=0,j=0,k=0;
    while(i<m && j<n) {
        if(nums1[i]<nums2[j]) {
            finalArray[k++] = nums1[i++];
        }
        else {
            finalArray[k++] = nums2[j++];
        }
    }
    if(i<m) {
        while(i<m) 
            finalArray[k++] = nums1[i++];
    }
    if(j<n) {
        while(j<n)
            finalArray[k++] = nums2[j++];
    }
    n = n+m;
    if(n%2==1) 
        return finalArray[((n+1)/2)-1];
    else return ((float)finalArray[(n/2)-1]+(float)finalArray[(n/2)])/2;
}

void solve()
{
    lli n,q,k;
    cin>>n>>q;
    vlli mad(n);
    forn(i,n){cin>>mad[i];}
    sort(mad.begin(),mad.end());
    while (q--)
    {
        vlli sad(n);
        cin>>k;
        if (k<=n){
            fr(i,1,n){
                if(i<=k)sad[i-1]=mad[i-1]+k-i+1;
                else sad[i-1]=mad[i-1];
            }
            sort(sad.begin(),sad.end());
            cout<<sad[0]<<" ";
        }else{
            lli tmp = (k-n+1)/2;            
            fr(i,1,n){
                if((n+k)%2 && i==n){
                    sad[i-1]=mad[i-1];
                    continue;
                }
                sad[i-1]=(mad[i-1]+k-i+1);
            }
            sort(sad.rbegin(),sad.rend());
            // cout<<endl<<sad[0]<<endl;
            int ind=0;
            while (tmp>0 && ind<n)
            {
                tmp=tmp-(sad[ind++]-sad[n-1]);
            }
            if (tmp>0)
            {
                if(tmp%n==0)cout<<sad[n-1]-(tmp/n)<<" ";
                else cout<<sad[n-1]-(tmp/n)-1<<" ";
            }else
            {
                cout<<sad[n-1]<<" ";
            }
            
            
            
            
            
            
        }
    }
    
    
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //speedup for leetcode
    /* static const auto speedup = []() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
    }(); */
    
    /* int t;
    cin >> t;
    while (t--)
    {
        solve();
    } */

    solve();
    cout<<endl;
    return 0;
}

