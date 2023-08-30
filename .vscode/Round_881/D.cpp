using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
#define MAXN 200005
int t, n, q;
vector<int> adj[MAXN];
int parent[MAXN];
long long int dp[MAXN];
long long int dfs(int p, int v)
{
    int counter = 0;
    for(int u: adj[v])
    {
        if(u != p)
        {
            dp[v] += dfs(v, u);
            counter++;
        }
    }
    if(counter == 0)
    {
        dp[v] = 1;
        return 1;
    }
    return dp[v];
}
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        for(int i = 0; i < n - 1; i++)
        {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            //cout << a << " " << b << "\n";
        }
        dfs(1, 1);
        cin >> q;
        for(int i = 0; i < q; i++)
        {
            long long int a, b; cin >> a >> b;
            long long int res = dp[a] * dp[b];
            cout << res << "\n";
        }
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            dp[i] = 0;
        }
    }
}