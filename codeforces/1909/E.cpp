using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
vector<bool> visited; // keeps track of which vertices are already visited

// runs depth first search starting at vertex v.
// each visited vertex is appended to the output vector when dfs leaves it.
void dfs(ll v, vector<vector<ll>> const& adj, vector<ll> &output) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}
vector<ll> strongly_connected_components(vector<vector<ll>> const& adj,
                                  vector<vector<ll>> &components,
                                  vector<vector<ll>> &adj_cond) {
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vector<ll> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);

    // create adjacency list of G^T
    vector<vector<ll>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<ll> roots(n, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order)
        if (!visited[v]) {
            std::vector<ll> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *min_element(begin(component), end(component));
            for (auto u : component)
                roots[u] = root;
        }

    // add edges to condensation graph
    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
    return roots;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m; cin >> n >> m;
        vector<vector<ll>> adj(n);
        for(int i = 0; i < m; i++){
            ll a, b; cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
        }
        vector<vector<ll>> comp;
        vector<vector<ll>> adj_cond;
        vector<ll> roots = strongly_connected_components(adj, comp, adj_cond);
        vector<ll> sizes(n);
        for(auto i: comp){
            ll get = 1e9;
            for(auto j: i){
                get = min(j, get);
            }
            sizes[get] += i.size();
        }
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(sizes[i] != 0 && adj_cond[i].size() == 0){
                if(sizes[i] <= n/5){
                    vector<ll> final_res;
                    for(int j = 0; j < n; j++){
                        if(roots[j] == i){
                            final_res.push_back(j);
                        }
                    }
                    cout << final_res.size() << "\n";
                    for(auto j: final_res){
                        cout << j + 1 << " ";
                    }
                    cout << "\n";
                    flag = true;
                    break;
                }
            }
        }
        if(!flag) cout << "-1\n";
    }
}