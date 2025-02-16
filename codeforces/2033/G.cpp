using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
vector<ll> adj[MAXN];
ll jump[MAXN][21], depth[MAXN];
pair<pair<ll, ll>, ll> diam[MAXN];
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
void dfsdiam(ll u, ll v)
{
    ll cnt = 0;
    priority_queue<pair<ll, ll>> pq;
    pair<pair<ll, ll>, ll> best = {{-1, -1}, -1};
    for(auto j: adj[v]){
        if(j != u){
            dfsdiam(v, j);
            if(depth[diam[j].first.first] > depth[diam[j].first.second] ){
                pq.push({depth[diam[j].first.first] - depth[v], diam[j].first.first});
            }
            else{
                pq.push({depth[diam[j].first.second] - depth[v], diam[j].first.second});
            }
            if(diam[j].second > best.second){
                best = diam[j];
            }
            cnt++;
        }
    }
    if(cnt == 0){
        diam[v] = {{v, v}, 0};
    }
    else if(cnt == 1){
        auto curr = pq.top();
        if(curr.first > best.second){
            diam[v] = {{curr.second, v}, curr.first};
        }
        else{
            diam[v] = best;
        }
    }
    else{
        auto curr1 = pq.top(); pq.pop();
        auto curr2 = pq.top();
        if(curr1.first + curr2.first > best.second){
            diam[v] = {{curr1.second, curr2.second}, curr1.first + curr2.first};
        }
        else{
            diam[v] = best;
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
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        for(int i = 0; i < n - 1; i++){
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 1);  
        dfsdiam(1, 1);
        ll q; cin >> q;
        for(int i = 0; i <  q; i++){
            ll v, k; cin >> v >> k;
            ll get_node = ancestor(v, k);
            ll n1 = diam[get_node].first.first;
            ll n2 = diam[get_node].first.second;
            ll dist1 = depth[n1] + depth[v] - 2 * depth[lca(n1, v)];
            ll dist2 = depth[n2] + depth[v] - 2 * depth[lca(n2, v)];
            cout << max(dist1, dist2) << " ";
        }
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            diam[i] = {{0, 0}, 0};
            depth[i] = 0;
            for(int j = 0; j <= 20; j++){
                jump[i][j] = 0;
            }
        }
        cout << "\n";
    }
}