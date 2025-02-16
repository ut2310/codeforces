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
set<ll> adj[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m; cin >> n >> m;
        vector<ll> deg(n + 1);
        for(int i = 0; i < m; i++){
            ll a, b; cin >> a >> b;
            deg[a]++; deg[b]++;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        priority_queue<pii> pq;
        for(int i = 1; i <= n; i++){
            pq.push({deg[i], i});
        }
        vector<pair<pii, ll>> res;
        while(pq.top().ff >= 2){
            pii curr = pq.top();
            pq.pop();
            if(deg[curr.ss] != curr.ff){
                continue;
            }
            ll n1 = curr.second;
            ll n2 = *adj[n1].begin();
            ll n3 = *next(adj[n1].begin());
            res.push_back({{n1, n2}, n3});
            adj[n1].erase(n2);
            adj[n2].erase(n1);
            adj[n1].erase(n3);
            adj[n3].erase(n1);
            if(adj[n2].count(n3) > 0){
                adj[n2].erase(n3);
                adj[n3].erase(n2);
                deg[n1]-=2; deg[n2]-=2; deg[n3] -= 2;
                pq.push({deg[n1], n1});
                pq.push({deg[n2], n2});
                pq.push({deg[n3], n3});
            }
            else{
                adj[n2].insert(n3);
                adj[n3].insert(n2);
                deg[n1]-=2;
                pq.push({deg[n1], n1});
            }
        }
        ll sum_degrees = 0;
        for(int i = 1; i <= n; i++){
            sum_degrees += deg[i];
        }
        if(sum_degrees == 0){
            cout << res.size() << "\n";
            for(int i = 0; i < res.size(); i++){
                cout << res[i].ff.ff << " " << res[i].ff.ss << " " << res[i].ss << "\n";
            }
        }
        else{
            ll start = -1;
            for(int i = 1; i <= n; i++){
                if(deg[i] == 1){
                    start = i;
                    break;
                }
            }
            ll start1 = *adj[start].begin();
            vector<ll> visited(n + 1);
            visited[start] = 1; visited[start1] = 1;
            for(int i = 1; i <= n; i++){
                if(visited[i] == 0){
                    res.push_back({{start, start1}, i});
                    start = i;
                    visited[i] = 1;
                    if(deg[i] == 1){
                        visited[*adj[i].begin()] = 1;
                    }
                }
            }
            cout << res.size() << "\n";
            for(int i = 0; i < res.size(); i++){
                cout << res[i].ff.ff << " " << res[i].ff.ss << " " << res[i].ss << "\n";
            }
        }

        for(int i = 1; i <= n; i++){
            adj[i].clear();
            deg[i] = 0;
        }
    }
}