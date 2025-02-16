#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ALPHABETSIZE 26
#define ll long long

ll colors[MAXN], ans[MAXN], res;
vector<ll> adj[MAXN];
void dfs(ll p, ll v)
{
    ll temp = ans[colors[v]];
    res += temp;
    for(auto u: adj[v]){
        ans[colors[v]] = 1;
        if(u != p){
            dfs(v, u);
        }
    }
    ans[colors[v]] = temp + 1;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> colors[i];
        }
        for(int i = 0; i < n - 1; i++){
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 1);
        cout << res << "\n";
        for(int i = 1; i <= n; i++){
            colors[i] = 0; ans[i] = 0; res = 0;
            adj[i].clear();
        }
    }
}