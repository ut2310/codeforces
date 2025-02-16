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
multiset<ll> adj[MAXN];
vector<ll> res;
void modify(ll u, ll v)
{
    adj[u].erase(adj[u].lower_bound(v));
    adj[v].erase(adj[v].lower_bound(u));
}
void dfs(ll p)
{
    res.push_back(p);
    if(adj[p].size() == 0){
        return;
    }
    ll get = *adj[p].begin();
    modify(p, get);
    dfs(get);
}
int main()
{
    ll n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    bool flag = false;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() % 2 != 0){
            flag = true;
        }
    }
    if(!flag){
        cout << "-1\n";
    }
    else{
        if(adj[1].size() % 2 == 0){
            queue<ll> bfs;
            bfs.push(1);
            vector<ll> visited(n + 1);
            vector<ll> prev(n + 1);
            vector<ll> res2;
            visited[1] = 1;
            while(bfs.size() > 0){
                ll curr = bfs.front();
                //cerr << curr << " " << prev[curr] << "\n";
                bfs.pop();
                for(auto j: adj[curr]){
                    if(visited[j] == 1){
                        continue;
                    }
                    prev[j] = curr;
                    visited[j] = 1;
                    if(adj[j].size() % 2 != 0){
                        res2.push_back(j);
                        while(prev[j] != 0){
                            //cout << j << " " << prev[j] << "hi2\n";
                            res2.push_back(prev[j]);
                            j = prev[j];
                        }
                        break;
                    }
                    bfs.push(j);
                }
                
                if(res2.size() > 0){
                    break;
                }
            }
            // for(auto j: res2){
            //     cerr << j << " ";
            // }
            for(int i = 0; i < res2.size() - 1; i ++){
                ll curr1 = res2[i]; ll curr2 = res2[i + 1];
                modify(curr1, curr2);
            }
            
        }
        dfs(1);
        cout << res.size() << "\n";
        ll temp2 = res.size();
        for(int i = 0; i < res.size(); i++){
            if(i < temp2 - 1) cout << res[i] << " ";
            else cout << res[i] << "\n";
        }
    }
}