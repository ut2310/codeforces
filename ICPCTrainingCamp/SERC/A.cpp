using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 1005   
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
vector<ll> adj[MAXN];
vector<pair<pair<ll, ll>, ll>> res;
void dfs(ll p, ll v, ll root)
{
    //cout << p << " " << v << " " << root << "\n";
    if(p != v && v != root && p != root){
        res.push_back({{root, p}, v});
    }
    for(auto u: adj[v]){
        if(u != p){
            dfs(v, u, root);
        }
    }
}
int main()
{
    ll n; cin >> n;
    vector<ll> deg(n + 1);
    for(int i = 0; i < n - 1; i++){
        ll a, b; cin >> a >> b;
        deg[a]++; deg[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll currn = -1; ll val = 0;
    for(int i = 1; i <= n; i++){
        if(deg[i] > val){
            currn = i;
            val = deg[i];
        }
    }
    dfs(currn, currn, currn);

    cout << res.size() << "\n";
    for(auto j: res){
        cout << j.ff.ff << " " << j.ff.ss << " " << j.ss << "\n";
    }
}