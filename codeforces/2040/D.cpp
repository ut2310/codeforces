using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
vector<ll> adj[MAXN];
ll res[MAXN], visited[2 * MAXN];
void dfs(ll u, ll v, ll value)
{
    res[v] = value;
    visited[value] = 1;
    ll ass  = -1;
    for(auto c: adj[v]){
        if(c != u){
            while(visited[value + ass] == 1 || value + ass <= 0){
                if(ass == 1){
                    ass += 3;
                }
                else{
                    ass += 2;
                }
            }
            dfs(v, c, value + ass);
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
        for(int i = 0; i < n - 1; i++){
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ll track = 1;
        dfs(1, 1, 1);
        for(int i = 1; i <= n; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            res[i] = 0;
        }
        for(int i = 1; i <= 2 * n; i++){
            visited[i] = 0;
        }
    }
}