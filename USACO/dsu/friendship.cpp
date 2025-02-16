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
vector<pair<ll, ll>> adj2[MAXN];
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
    vector<ll> deg(n + 1);
    for(int i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[v]++;
        deg[u]++;
    }
    vector<pii> degrees;
    for(int i = 1; i <= n; i++){
        degrees.push_back({deg[i], i});
    }
    sort(degrees.begin(), degrees.end());
    for(auto i : degrees){
        ll n1 = i.second;
        
    }
    vector<pair<ll, pii>> edges;
    for(int i = 1; i <= n ; i++){
        for(auto j: adj[i]){
            edges.push_back({min(deg[i], deg[j]), {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    vector<ll> currDeg(n + 1);
    for(int i = 0; i <= n; i++){
        parent.push_back(i);
        rank_size.push_back(1);
    }
    ll res = 0;
    vector<priority_queue<> comp(n + 1);
    for(int i = 1; i <= n; i++){
        comp[i].push();
    }
    for(int i = edges.size() - 1; i >= 0; i--){
        ll n1 = edges[i].ss.ff; ll n2 = edges[i].ss.ss;
        currDeg[n1]++;
        currDeg[n2]++;
        union_sets(n1, n2);
        
    }
    
    
}