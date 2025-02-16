using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
vector<ll> adj[MAXN];
set<ll> adj2[MAXN];
ll depth[MAXN], subtree[MAXN];
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
            //cout << j << " " << v << " " << depth[v] << "\n";
            dfs(v, j);
        }
    }
    
}
void dfs2(ll p, ll v)
{
    subtree[v] = 1;
    for(auto u: adj[v]){
        if(u != p){
            adj2[v].insert(u);
            dfs2(v, u);
            subtree[v] += subtree[u];
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
pair<ll, ll> lca(ll u, ll v)
{
    ll track = 0;
    //cout << depth[u] << " " << depth[v] << "hi3\n";
    track += abs(depth[u] - depth[v]);

    if(depth[u] != depth[v]){
        if(depth[u] < depth[v]){
            v = ancestor(v, depth[v] - depth[u]);
        }
        else{
            u = ancestor(u, depth[u] - depth[v]);
        }
    }
    //cout << track << " hi1\n";
    //cout << u << " " << v << "\n";
    if(u == v){
        return {u, track};
    }
    for(int i = 20; i >= 0; i--){
        if(jump[u][i] != jump[v][i]){
            u = jump[u][i];
            v = jump[v][i];
            track += 2 * (1 << i);
        }
    }
    //cout << track << " hi2\n";
    return {jump[u][0], track + 2};
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, q; cin >> n; 
    for(int i = 0; i < n - 1; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    dfs(1, 1);
    // for(int i = 1; i <= n; i++){
    //     cout << depth[i] << " ";
    // }
    //cout << "\n";
    dfs2(1, 1);
    // for(int i = 1; i <= 5; i++){
    //     for(int j = 0; j <= 20; j++){
    //         cout << jump[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 1; i <= q; i++){
        ll a, b; cin >> a >> b;
        pair<ll, ll> get = lca(a, b);
        //cout << get.first << " " << get.second << "\n";
        if(get.second % 2 != 0){
            cout << "0\n";
        }
        else{
            if(a == b){
                cout << n << "\n";
                continue;
            }
            ll node = -1;
            ll other_node_1 = -1;
            ll res = n;
            if(depth[a] >= depth[b]){
                node = ancestor(a, get.second/2);
                res -= subtree[ancestor(a, get.second/2 - 1)];
                ll n1 = ancestor(b, get.second/2 - 1);
                if(adj2[node].count(n1) > 0){
                    res -= subtree[n1];
                }
                else{
                    res -= (n - subtree[node]);
                }
            }
            else{
                node = ancestor(b, get.second/2);
                res -= subtree[ancestor(b, get.second/2 - 1)];
                ll n1 = ancestor(a, get.second/2 - 1);
                if(adj2[node].count(n1) > 0){
                    res -= subtree[n1];
                }
                else{
                    res -= (n - subtree[node]);
                }
            }
            cout << res << "\n";
        }
    }

}