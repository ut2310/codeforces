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
#define ll long long
ll t, n, m;
vector<pair<ll, ll>> adj[MAXN];
ll visited[MAXN];
ll weight[MAXN];
bool dfs(int root)
{
    visited[root] = 1;
    for (auto i : adj[root])
    {
        cout << root << " " << weight[root] << " " << i.second << " " << weight[i.first] << " " << visited[i.first] << "\n";
        if (visited[i.first] == 1)
        {
            if (weight[i.first] != (weight[root] + i.second))
            {
                return false;
            }
        }
        else
        {
            weight[i.first] = weight[root] + i.second;
            visited[i.first] = 1;
            return dfs(i.first);
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t-->0)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            ll a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back(make_pair(b, d));
            adj[b].push_back(make_pair(a, -1 * d));
        }
        bool res = true;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                res = dfs(i);
                //cout << res << "\n";
            }
            if(res == false)
            {
                break;
            }
        }
        // cout << "WEIGHTS:        ";
        // for(int i = 1; i <= n; i++)
        // {
        //     cout << weight[i] << " ";
        // }
        //cout << "\n";
        if(res)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}