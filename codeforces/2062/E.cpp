using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 400005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
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
        vector<pair<ll, ll>> weights;
        for(int i = 1; i <= n; i++){
            ll temp; cin >> temp;
            weights.push_back({temp, i});
        }
        sort(weights.begin(), weights.end());
        for(int i = 0; i < n - 1; i++){
            ll u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 1);
        bool flag = false; ll res = -1;
        ll curr = weights[n - 1].ss; ll before_lca = 0;
        for(int i = n - 2; i >= 0; i--){
            if(weights[i].ff == weights[i + 1].ff && before_lca == 0){
                curr = lca(curr, weights[i].ss);
                continue;
            }
            else if(weights[i].ff == weights[i + 1].ff){
                curr = lca(curr, weights[i].ss);
                if(lca(weights[i].ss, before_lca) != weights[i].ss){
                    flag = true;
                    res = weights[i].ss;
                    break;
                }
            }
            else if(weights[i].ff != weights[i + 1].ff){
                before_lca = curr;
                curr = weights[i].ss;
                //cout << weights[i].ss << " " << before_lca << " " << lca(weights[i].ss, before_lca) << "\n";
                if(lca(weights[i].ss, before_lca) != weights[i].ss){
                    flag = true;
                    res = weights[i].ss;
                    break;
                }
            }
        }
        if(flag){
            cout << res << "\n";
        }
        else{
            cout << "0\n";
        }
        for(int i = 0; i <= n; i++){
            depth[i] = 0; adj[i].clear();
            for(int j = 0; j <= 20; j++){
                jump[i][j] = 0;
            }
        }
    }
}