using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 2005

vector<ll> adj[MAXN];
ll dp[MAXN][MAXN];
ll parent[MAXN], deg[MAXN];
void dfs(ll p, ll v, ll value)
{
    parent[v] = p;
    if(v != 1){
        if(value == 0){
            if(p == 1){
                dp[v][value] = dp[p][value] + 2 * deg[v] - 1;
            }
            else{
                dp[v][value] = dp[parent[p]][value] + 2 * deg[v];
            }
        }
        else{
            if(p == 1){
                dp[v][value] = min(dp[p][value] + 2 * deg[v] - 1, dp[p][value - 1] + 1);
            }
            else{
                dp[v][value] = min(dp[parent[p]][value] + 2 * deg[v], dp[parent[p]][value - 1] + 2);
            }
            
        }
    }
    for(auto child: adj[v]){
        if(p != child){
            dfs(v, child, value);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, q; cin >> n >> q;
        for(int i = 0; i < n - 1; i++){
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            deg[a]++; deg[b]++;
        }
        for(int i = 0; i <= n; i++){
            dfs(1, 1, i);
        }
        while(q-->0){
            ll node, coins; cin >> node >> coins;
            cout << dp[parent[node]][coins] + 1 << "\n";
        }
        for(int i = 1; i <= n; i++){
            parent[i] = 0;
            deg[i] = 0;
            adj[i].clear();
            for(int j = 0; j <= n; j++){
                dp[i][j] = 0;
            }
        }
    }
    
}