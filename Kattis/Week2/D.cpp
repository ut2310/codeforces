using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1005
#define ALPHABETSIZE 26
vector<pair<ll, ll>> adj[MAXN];
ll dp[MAXN];
void dfs(ll p, ll v, ll edge_weight)
{
    ll res = 0;
    ll cnt = 0;
    for(auto c: adj[v]){
        if(c.first != p){
            dfs(v, c.first, c.second);
            res += dp[c.first];
            cnt++;
        }
    }
    if(p == v){
        dp[v] = res;
        return;
    }
    if(cnt==0){
        dp[v] = edge_weight;
        return;
    }
    dp[v] = min(edge_weight, res);
    return;
}
int main()
{
    ll n, r; 
    while(cin >> n >> r)
    {
        for(int i = 0; i < n - 1; i++){
            ll u, v, w; cin >> u >> v >> w;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        dfs(r, r, 1e18);
        cout << dp[r] << "\n";
        for(int i = 1; i <= n; i++){
            dp[i] = 0;
            adj[i].clear();
        }
    }
    
}