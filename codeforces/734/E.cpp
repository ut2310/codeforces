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
vector<ll> adj[MAXN];
ll track[MAXN];
ll cnt1, cnt2;
void dfs(ll p, ll v, ll cmp1)
{
    bool flag = false;
    if(track[p] != track[v]){
        if(track[v] == 0) cnt1++;
        if(track[v] == 1) cnt2++;
        flag = true;
    }
    for(auto u: adj[v]){
        if(u != p){
            dfs(v, u);
        }
    }
}
int main()
{
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(int i =  1; i <= n; i++){
        cin >> track[i];
    }
    for(int i = 1; i < n; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(track[1] == 0){
        cnt1++;
    }
    else{
        cnt2++;
    }
    dfs(1, 1);
    cout << min(cnt1, cnt2) << "\n";
}