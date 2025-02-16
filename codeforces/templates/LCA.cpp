using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
vector<ll> adj[MAXN];
ll depth[MAXN];
ll jump[MAXN][21];
void dfs(ll u, ll v)
{
    jump[v][0] = u;
    for(int i = 1; i <= 20; i++){
        jump[v][i] = jump[jump[v][i - 1]][i - 1];
    }
    for(auto j: adj[v]){
        if(j != u){
            depth[j] = depth[v] + 1;
            dfs(v, j);
        }
    }
    
}

ll ancestor(ll a, ll x)
{
    ll cnt = 0;
    ll res = a;
    while(x > 0){
        if(x % 2 == 1){
            res = jump[res][cnt];
        }
        x /= 2;
        cnt++;
    }
    return res;
}
ll lca(ll u, ll v)
{
    if(depth[u] != depth[v]){
        if(depth[u] < depth[v]){
            v = ancestor(v, depth[v] - depth[u]);
        }
        else{
            u = ancestor(u, depth[u] - depth[v]);
        }
    }
    //cout << u << " " << v << "\n";
    if(u == v){
        return u;
    }
    for(int i = 20; i >= 0; i--){
        if(jump[u][i] != jump[v][i]){
            u = jump[u][i];
            v = jump[v][i];
        }
    }
    return jump[u][0];
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, q; cin >> n >> q; 
    for(int i = 2; i <= n; i++){
        ll a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    dfs(1, 1);
    // for(int i = 1; i <= 5; i++){
    //     for(int j = 0; j <= 20; j++){
    //         cout << jump[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 1; i <= q; i++){
        ll a, b; cin >> a >> b;
        cout << lca(a, b) << "\n";
    }

    depth[1] = 0;
}