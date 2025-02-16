using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
vector<ll> adj[MAXN];
ll in_degree[MAXN];
int main()
{
    ll n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<ll> ans;
    for(int i = 1; i <= n; i++){
        //cout << in_degree[i] << "\n";
        if(in_degree[i] == 0){
            pq.push(i);
        }
    }
    bool flag = true;
    while(pq.size() > 0){
        ll curr = pq.top();
        pq.pop();
        ans.push_back(curr);
        for(auto j: adj[curr]){
            in_degree[j]--;
            if(in_degree[j] == 0){
                pq.push(j);
            }
        }
    }
    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << " ";
    // }
    // cout << "\n";
    if(ans.size() != n) cout << "IMPOSSIBLE\n";
    else{
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    
}