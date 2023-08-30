using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#define MAXN 100005
int n, m;
vector<int> adj[MAXN];
int amount[MAXN];
long long int imp[MAXN];
vector<long long int> vertimp;
int parent[MAXN];
set<int, decltype(cmp)*> sons[MAXN];
bool cmp(int &u, int &v)    
{
    return imp[u] < imp[v];
}
int dfsImp(int p, int s)
{
    imp[s]= vertimp[s - 1]; 
    parent[s] = p;
    for(int v: adj[s])
    {
        if(p != v)
        {
            sons[s].insert(v);
            imp[s] += dfsImp(s, v);
        }
    }
    return imp[s];
}
int dfsSize(int p, int s)
{
    amount[s]= 1;
    for(int v: adj[s])
    {
        if(p != v)
        {
            amount[s] += dfsSize(s, v);
        }
    }
    return amount[s];
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        long long int a; cin >> a;
        vertimp.push_back(a);
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsImp(1, 1);
    dfsSize(1, 1);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        if(a == 1)
        {
            cout << imp[b] << "\n";
        }
        else
        {
            if(sons[b].size() != 0)
            {
                int son_x = *sons[b].rbegin();
                
            }
        }
    }
}