using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005
vector<ll> adj[MAXN];
ll M;
pair<ll, ll> dp[MAXN];
ll mod(ll a, ll b)
{
    if(a % b < 0)
    {
        return b + a % b;
    }
    return a % b;
}
void dfs(ll p, ll v)
{   
    dp[v].first = 1;
    dp[v].second = 0;
    for(auto u: adj[v]){
        if(u != p){
            dfs(v, u);
            dp[v].first *= (dp[u].first + 1);
            dp[v].first %= M;
            dp[v].second += dp[u].first + dp[u].second;
            dp[v].second %= M;
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    M = 998244353;
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        for(int i = 0; i < n - 1; i++)
        {
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 1);
        // for(int i =1 ; i <= n; i++){
        //     cout << dp[i].first << " " << dp[i].second << "\n";
        // }
        ll res = dp[1].first + dp[1].second + 1;
        res %= M;
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            dp[i].first = 0; dp[i].second = 0;
        }
        cout << res << "\n";

    }
}