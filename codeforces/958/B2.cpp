using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
vector<ll> adj[MAXN];
ll dist[MAXN], depth[MAXN], parent[MAXN], visited[MAXN];
void dfs(ll p, ll v, ll distance)
{
    dist[v] = distance;
    for(auto u: adj[v]){
        if(u != p) dfs(v, u, distance + 1);
    }
}
void dfs2(ll p, ll v)
{
    parent[v] = p;
    ll curr = 0;
    for(auto u: adj[v]){
        if(u != p){
            dfs2(v, u);
            curr = max(curr, depth[u] + 1);
        }
    }
    depth[v] = curr;
}
void dfs3(ll p, ll v, ll &track)
{
    visited[v] = 1; track += 1;
    ll most = -1; ll node = -1;
    for(auto u: adj[v]){
        if(u != p){
            if(depth[u] > most){
                most = depth[u];
                node = u;
            }
        }
    }
    //cout << most << " " << node << " " << p << " " << v << " " << track << "\n";
    if(node != -1) dfs3(v, node, track);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1, 0);
    ll furthest = 0;
    ll node = 1;
    for(int i = 1; i <= n; i++){
        if(dist[i] > furthest){
            furthest = dist[i];
            node = i;
        }
    }
    dfs2(node, node);
    priority_queue<pair<ll, ll>> pq;
    for(int i = 1; i <= n; i++){
        if(i != node){
            pq.push({depth[i], i});
        }
    }
    vector<ll> res(n + 1);
    res[1] = 1;
    for(int i = 2; i <= n; i++){
        while(!pq.empty() && visited[pq.top().second] == 1){
            pq.pop();
        }
        if(pq.empty()){
            res[i] =  n;
            continue;
        } 
        auto curr = pq.top();
        //cerr << curr.first << " " << curr.second << "\n";
        pq.pop();
        ll total = res[i - 1];
        //cout << parent[curr.second] << " " << curr.second << " " << total << "\n";
        dfs3(parent[curr.second], curr.second, total);
        res[i] = total;
    }
    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }
    cout << "\n";
}