using namespace std;
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

vector<ll> added_edges[MAXN];
set<ll> adj[MAXN];
ll n, m, parent[MAXN], rank_size[MAXN], track;
ll find_set(ll v) {
    if(parent[v] != v) parent[v] = find_set(parent[v]);
    return parent[v];  
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_size[a] > rank_size[b])
            swap(a, b);
        parent[a] = b;
        ll i1 = rank_size[a]; ll i2 = rank_size[b];
        track += ((i1 + i2) * (i1 + i2 - 1))/2 - ((i1)*(i1 - 1)/2) - ((i2)*(i2 - 1)/2);
        rank_size[b] += rank_size[a];
        
    }
}

int main()
{
    ll n, m; cin >> n >> m;
    string s; cin >> s;
    for(int i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i = 0; i < s.size(); i++){
        //look at node i + 1
        if(s[i] == '1' && adj[i + 1].size() > 0){
            ll last = *adj[i + 1].rbegin();
            for(auto j: adj[i + 1]){
                if(j != last && j > (i + 1)){
                    adj[j].insert(last);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        rank_size[i] = 1;
        parent[i] = i;
    }
    vector<ll> res(n);
    track = 0;
    for(int i = n; i >= 1; i--){
        for(auto j: adj[i]){
            if(j > i){
                union_sets(i, j);
                //cout << i << " " << j << "hi2\n";
            }
            
        }
        // for(auto j: added_edges[i]){
        //     union_sets(i, j);
        //     //cout << i << " " << j << "hi1\n";
        // }
        res[i - 1] = track;
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << "\n";
    }
}