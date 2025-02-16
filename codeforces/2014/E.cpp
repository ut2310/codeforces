#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define ALPHABETSIZE 26
#define ll long long
vector<pair<ll, ll>> adj[MAXN];

void dijkstra(ll start_node, vector<ll> &dp)
{

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for(int i = 1; i < dp.size(); i++){
        dp[i] = 1e18;
    }
    dp[start_node] = 0;
    pq.push(make_pair(0, start_node));
    while (!pq.empty()) {
		const auto [cdist, node] = pq.top();
		pq.pop();
		if (cdist != dp[node]) { continue; }
		for (const pair<int, int> &i : adj[node]) {
			if (cdist + i.second < dp[i.first]) {
				pq.push({dp[i.first] = cdist + i.second, i.first});
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m, h; cin >> n >> m >> h;
        vector<int> horses(n + 1);
        for(int i = 0; i < h; i++){
            ll temp; cin >> temp;
            horses[temp] = 1;
        }
        //consider mod n + 1
        for(int i = 0; i < m; i++){
            ll u, v, w; cin >> u >> v >> w;
            if(horses[u] == 0 && horses[v] == 0){
                adj[v].push_back(make_pair(u, w));
                adj[u].push_back(make_pair(v, w));
                adj[u + n + 1].push_back(make_pair(v + n + 1, w/2));
                adj[v + n + 1].push_back(make_pair(u + n + 1, w/2));
            }
            else if(horses[u] == 1 && horses[v] == 0){
                adj[v].push_back(make_pair(u + n + 1, w));
                adj[u + n + 1].push_back(make_pair(v + n + 1, w/2));
                adj[v + n + 1].push_back(make_pair(u + n + 1, w/2));
            }
            else if(horses[u] == 0 && horses[v] == 1){
                adj[u].push_back(make_pair(v + n + 1, w));
                adj[v + n + 1].push_back(make_pair(u + n + 1, w/2));
                adj[u + n + 1].push_back(make_pair(v + n + 1, w/2));
            }
            else{
                adj[v + n + 1].push_back(make_pair(u + n + 1, w/2));
                adj[u + n + 1].push_back(make_pair(v + n + 1, w/2));
            }
        }
        vector<ll> dp1(2*n + 5);
        vector<ll> dp2(2*n + 5);
        if(horses[1] == 0 && horses[n] == 0){
            dijkstra(1, dp1);
            dijkstra(n, dp2);
        }
        else if(horses[1] == 1 && horses[n] == 0){
            dijkstra(n + 2, dp1);
            dijkstra(n, dp2);
        }
        else if(horses[1] == 0 && horses[n] == 1){
            dijkstra(1, dp1);
            dijkstra(2*n + 1, dp2);
        }
        else{
            dijkstra(n + 2, dp1);
            dijkstra(2*n + 1, dp2);
        }
        if(dp1[n] == 1e18 && dp1[2*n + 1] == 1e18){
            cout << "-1\n";
        }
        else{
            ll res = 1e18;
            for(int i = 1; i <= n; i++){
                res = min(res, max(min(dp1[i], dp1[i + n + 1]), min(dp2[i], dp2[i + n + 1])));
            }
            cout << res << "\n";
        }
        for(int i = 1; i <= 2*n + 1; i++){
            adj[i].clear();
        }
    }
}