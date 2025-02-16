#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ALPHABETSIZE 26
#define ll long long
ll weight[MAXN];
vector<ll> adj[MAXN];
ll res;
void dfs(ll p, ll v)
{
    ll cnt = 0;
    ll track = 0;
    for(auto u: adj[v]){
        track += weight[u];
        cnt++;
        dfs(v, u);
    }
    weight[v] = track - weight[v];
    if(cnt == 0) weight[v] = 1e18;
}
ll dfs2(ll p, ll v, ll depth, ll root_weight)
{
    for(auto u: adj[v]){
        if(weight[u] > 0){
            ll curr = min(abs(root_weight), weight[u]);
            root_weight += curr;
            weight[u] -= curr;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        res = 0;
        for(int i = 1; i <= n; i++){
            cin >> weight[i];
        }
        for(int i = 2; i <= n; i++){
            ll parent; cin >> parent;
            adj[parent].push_back(i);
        }
        dfs(1, 1);
        for(int i = 1; i <= n; i++){
            
        }

        for(int i = 1; i <= n; i++){
            cout << weight[i] << " ";
        }
        cout << "\n";
    }
}