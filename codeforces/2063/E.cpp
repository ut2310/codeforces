using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll subtree[MAXN], depth[MAXN], dist, n;
vector<ll> adj[MAXN];
void dfs(ll p, ll v)
{
    subtree[v] = 1;
    if(v != p) depth[v] = depth[p] + 1;
    for(auto j: adj[v]){
        if(j != p){
            dfs(v, j);
            subtree[v] += subtree[j];
        }
    }
    if(v != p) dist += subtree[v] * (n - subtree[v]);
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        cin >> n;
        for(int i = 0; i < n - 1; i++){
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ll res = -1 * n * (n + 1)/2;
        dfs(1, 1);
        for(int i = 1; i <= n; i++){
            res += subtree[i];
        }
        res += dist;
        // for(int i = 1; i <= n; i++){
        //     cout << depth[i] << " " << subtree[i] << "\n";
        // }
        //cout << dist << " " << res << "\n";
        vector<pair<ll, ll>> a;
        for(int i = 1; i <= n; i++){
            a.push_back({depth[i], i});
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++){
            res += depth[a[i].ss]*(n - i - 1 - i);
        }
        cout << res << "\n";
        for(int i = 0; i <= n; i++){
            depth[i] = 0;
            adj[i].clear();
            dist = 0;
        }
    }
}