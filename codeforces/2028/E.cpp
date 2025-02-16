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
ll M;
vector<ll> adj[MAXN];
ll depth1[MAXN], depth2[MAXN], res[MAXN];
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
ll modInverse(ll A)
{
    return power(A, M - 2);
}
void dfs(ll p, ll v, ll track)
{
    ll cnt = 0;
    depth2[v] = 1e9;
    depth1[v] = track;
    for(auto u: adj[v]){
        if(u != p){
            dfs(v, u, track + 1);
            depth2[v] = min(depth2[v], depth2[u] + 1);
            cnt++;
        }
    }
    if(cnt == 0){
        depth2[v] = 0;
    }
}
void dfs2(ll p, ll v)
{
    res[v] = res[p] * depth2[v];
    res[v] = (res[v] + M) % M;
    res[v] *= modInverse(depth2[v] + 1);
    res[v] = (res[v] + M) % M;
    if(v == 1){
        res[v] = 1;
    }
    for(auto u: adj[v]){
        if(u != p){
            dfs2(v, u);
        }
    }
    if(depth2[v] == 0){
        res[v] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    M = 998244353;
    while(t-->0){
        ll n; cin >> n;
        for(int i =0; i < n - 1; i++){
            ll a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //cerr << "hello\n";
        dfs(1, 1, 0);
        res[1] = 1;
        dfs2(1, 1);
        for(int i = 1; i <= n; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
        for(int i = 1; i <= n; i++){
            depth1[i] = 0; depth2[i] = 0;
            adj[i].clear(); res[i] = 0;
        }

    }
}