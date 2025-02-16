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
pair<ll, ll> track[MAXN];
pair<ll, ll> res[MAXN];
void dfs(ll p, ll v)
{
    ll cnt = 0;
    vector<pair<ll, ll>> curr; ll addOn = 0; ll max_number = 0;
    for(auto j: adj[v]){
        if(j != p){
            cnt++;
            dfs(v, j);  
            curr.push_back({j, res[j].ff});
            addOn += res[j].ss;
        }
    }
    if(cnt == 0){
        res[v] = {track[v].ff, 0};
        return;
    }
    vector<ll> other;
    for(int i = 0; i < curr.size(); i++){
        curr[i].ss += addOn - res[curr[i].ff].ss;
        max_number = max(max_number, curr[i].ss);
        other.push_back(curr[i].ss);
    }
    if(track[v].ff + addOn > max_number){ //if left endpoint is greater than max_number
        res[v] = {track[v].ff + addOn, addOn};
    }
    else if(track[v].ss + addOn < max_number){ //if right end point is less than max number
        ll addOps = 0;
        for(int i = 0; i < other.size(); i++){
            if(track[v].ss + addOn < other[i]){
                addOps += other[i] - (track[v].ss + addOn);
            }
        }
        res[v] = {track[v].ss + addOn + addOps, addOps + addOn};
    }
    else{
        res[v] = {max_number, addOn};
    }

}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> track[i].first >> track[i].second;
        }
        for(int i = 0; i < n - 1; i++){
            ll p, v; cin >> p >> v;
            adj[p].push_back(v);
            adj[v].push_back(p);
        }
        //ll root = 4;
        ll ans = 1e18;
        for(int i = 1; i <= 1; i++){
            dfs(i, i);
            ans = min(ans, res[i].ff);
            for(int i = 0; i <= n; i++){
                res[i] = {0, 0};
            }
        }
        //dfs(root, root);
        //cout << res[root].ff << "\n";
        cout << ans << "\n";
        for(int i = 0; i <= n; i++){
            adj[i].clear();
            track[i] = {0, 0};
            res[i] = {0, 0};
        }
        
    }
}