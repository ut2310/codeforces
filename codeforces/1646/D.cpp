#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ALPHABETSIZE 26
#define ll long long
vector<ll> adj[MAXN];
ll good[MAXN], weight[MAXN];
int main()
{
    ll n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(n == 2){
        cout << 2 << " " << 2 << "\n";
        cout << 1 << " " << 1 << "\n";
        return 0;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 1){
            pq.push({adj[i].size(), i});
        }
    }
    vector<ll> visited(n + 1);
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        if(visited[curr.second] == 1){
            continue;
        }
        visited[curr.second] = 1;
        bool flag = true;
        for(auto v: adj[curr.second]){
            if(good[v] == 1){
                flag = false;
            }
        }
        if(!flag){
            good[curr.second] = 0;
            weight[curr.second] = 1;
        }
        else{
            good[curr.second] = 1;
            weight[curr.second] = adj[curr.second].size();
        }
        for(auto v: adj[curr.second]){
            if(visited[v] == 0){
                pq.push({adj[v].size(), v});
            }
        }
    }
    ll res1 = 0; ll res2 = 0;
    for(int i = 1; i <= n; i++){
        res2 += weight[i];
    }
    for(int i = 1; i <= n; i++){
        res1 += good[i];
    }
    cout << res1 << " " << res2 << "\n";
    for(int i = 1; i <= n; i++){
        cout << weight[i] << " ";
    }
    cout << "\n";
}