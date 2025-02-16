using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
vector<ll> adj[MAXN];
vector<pair<ll, ll>> adj2[650];
vector<ll> parent, rank_size;

void debug(vector<ll> a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
ll find_set(ll v) {
    if(parent[v] != v)
    {
        parent[v] = find_set(parent[v]);
    }
    return parent[v];  
}
void union_sets(ll a, ll b, vector<ll> &comp) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_size[a] > rank_size[b])
            swap(a, b);
        parent[a] = b;
        rank_size[b] += rank_size[a];
        comp.push_back(b);
    }
}
int main()
{
    ll n, m; cin >> n >> m;
    set<ll> degrees;
    vector<ll> deg(n + 1);
    for(int i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
        deg[u]++;
    }
    for(int i = 1; i <= n ; i++){
        degrees.insert(deg[i]);
        for(auto j: adj[i]){
            adj2[min(min(deg[i], deg[j]), 632LL)].push_back({i, j});
        }
    }
    vector<ll> track;
    for(auto i: degrees){
        track.push_back(i);
    }
    sort(track.begin(), track.end());
    for(int i = 0; i <= n; i++){
        parent.push_back(i);
        rank_size.push_back(1);
    }
    // debug(parent);
    // debug(rank_size);
    //debug(track);
    ll res = 0;
    vector<ll> curr_deg(n + 1);
    //i is the minimum possible degree, check if there is component where every node has degree at least i
    for(int i = 632; i >= 1; i--){
        if(i * (i + 1)/2 > m){
            continue;
        }
        vector<pii> edges = adj2[i];
        vector<ll> comp;
        //debug(curr_deg);
        for(auto j: edges){
            union_sets(j.ff, j.ss, comp);
            curr_deg[j.ff]++;
            curr_deg[j.ss]++;
        }
        //debug(curr_deg);
        vector<ll> lookAt(n + 1, 1e6);
        for(int j = 1; j <= n; j++){
            ll curr = find_set(j);
            lookAt[curr] = min(lookAt[curr], curr_deg[j]);
        }
        //debug(lookAt);
        for(int j = 1; j <= n; j++){
            ll curr = find_set(j);
            if(lookAt[curr] != 1e6 && lookAt[curr] >= i){
                res = max(res, i * rank_size[curr]);
            }
        }
    }
    cout << res << "\n";
    
}