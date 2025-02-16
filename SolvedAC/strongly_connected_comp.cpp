using namespace std;
#include <bits/stdc++.h>
#define ll long long
vector<ll> adj[10005];
vector<ll> adjt[10005];
ll seen[10005];
ll done[10005];
void dfs(ll v, ll &time)
{
    seen[v] = time;
    for(auto u: adj[v]){
        if(seen[u] == 0){
            time++;
            dfs(u, time);
        }
    }
    time++;
    done[v] = time;
}
void dfs2(ll v, vector<ll> &curr)
{
    seen[v] = 1;
    curr.push_back(v);
    for(auto u: adjt[v]){
        if(seen[u] == 0){
            dfs2(u, curr);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll V, E; cin >> V >> E;
    for(int i = 1; i <= E; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adjt[v].push_back(u);
    }
    ll time = 1;
    for(int i = 1; i <= V; i++){
        if(seen[i] == 0){
            dfs(i, time);
        }
    }
    // cout << "\n";
    // for(int i = 1; i <= V; i++){
    //     cout <<seen[i] << " " << done[i] << "\n";
    // }
    vector<pair<ll, ll>> curr;
    for(int i = 1; i <= V; i++){
        curr.push_back(make_pair(done[i], i));
    }
    sort(curr.begin(), curr.end(), greater<pair<ll, ll>>());
    int K = 0;
    vector<vector<ll>> res;
    for(int i = 1; i <= V; i++){
        seen[i] = 0;
    }
    
    //cout << "\n";
    for(int i = 0; i < curr.size(); i++){
        vector<ll> cc;
        if(seen[curr[i].second] == 0){
            dfs2(curr[i].second, cc);
            sort(cc.begin(), cc.end());
            res.push_back(cc);
        }
        
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++){
        for(auto j: res[i]){
            cout << j << " ";
        }
        cout << "-1\n";
    }




}