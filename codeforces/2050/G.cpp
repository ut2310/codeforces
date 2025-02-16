using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
vector<ll> adj[MAXN];
ll dp[MAXN], ans[MAXN];
void dfs(ll p, ll v)
{
    ll cnt = 0;
    vector<ll> track;
    for(auto u: adj[v]){
        if(u != p){
            dfs(v, u);
            cnt++;
            track.push_back(dp[u]);
        }
    }
    sort(track.begin(), track.end());
    if(cnt == 0){
        dp[v] = 1;
        return;
    }
    dp[v] = cnt;
    dp[v] = max(dp[v], cnt - 2 + track[track.size() - 1]);
    if(track.size() >= 2){
        ans[v] = max(dp[v], cnt - 4 + track[track.size() - 1] + track[track.size() - 2]);
        if(p != v) ans[v]++;
    }
    if(p != v) dp[v]++;
    if(cnt == 0)
    {
        dp[v] = 1;
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
        dfs(1, 1);
        ll res =0;
        for(int i = 1; i <= n; i++){
            res = max(res, dp[i]);
            res = max(res, ans[i]);
            adj[i].clear();
            dp[i] = 0;
            ans[i] = 0;
        }
        cout << res << "\n";

    }
}