using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 400005
set<ll> adj[MAXN];
void bfs(int S, vector<ll>& par, vector<ll>& dist)
{
    // queue to store the nodes in the order they are
    // visited
    queue<ll> q;
    // Mark the distance of the source node as 0
    dist[S] = 0;
    // Push the source node to the queue
    q.push(S);

    // Iterate till the queue is not empty
    while (!q.empty()) {
        // Pop the node at the front of the queue
        ll node = q.front();
        q.pop();

        // Explore all the neighbours of the current node
        for (ll neighbour : adj[node]) {
            if (dist[neighbour] == 1e9) {
                par[neighbour] = node;
               
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    //graph is n vertices + c colors and the edges are simply if a color connects to a vertice
    while(t-->0)
    {
        ll n, m; cin >> n >> m;
        map<ll, ll> colors;
        ll track = n + 1;
        for(int i = 0; i < m; i++)
        {
            ll u, v, c; cin >> u >> v >> c;
            if(colors.count(c) == 0)
            {
                colors[c] = track;
                track++;
            }
            ll color = colors[c];
            adj[u].insert(color);
            adj[v].insert(color);
            adj[color].insert(u);
            adj[color].insert(v);
        }
        ll s, d; cin >> s >> d;
        vector<ll> dist(n + m + 5);
        for(int i = 0; i < n + m + 5; i++)
        {
            dist[i] = 1e9;
        }
        vector<ll> par(n + m + 5);
        bfs(s, par, dist);
        ll res = dist[d]/2;
        cout << res << "\n";
        for(int i = 0; i < n + m + 5; i++)
        {
            adj[i].clear();
        }
        

    }
}