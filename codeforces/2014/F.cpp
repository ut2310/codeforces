#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ALPHABETSIZE 26
#define ll long long
ll weights[MAXN];
ll dp0[MAXN];
ll dp1[MAXN];
ll c;
vector<ll> adj[MAXN];
void dfs(ll p, ll v)
{
    for(auto u: adj[v]){
        if(u != p){
            dfs(v, u);
            dp0[v] += max(dp0[u], max(dp1[u], 0LL));
            dp1[v] += max(dp1[u] - 2 * c, max(dp0[u], 0LL));
        }
    }
    dp1[v] += weights[v];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n >> c;
        for(int i = 1; i <= n; i++){
            cin >> weights[i];
        }
        for(int i = 0; i < n - 1; i++){
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 1);
        ll res = max(dp0[1], dp1[1]);
        cout << res << "\n";
        for(int i = 1; i <= n; i++){
            //cout << dp0[i] << " " << dp1[i] << "\n";
            adj[i].clear();
            weights[i] = 0;
            dp0[i] = 0;
            dp1[i] = 0;
        }
    }
}