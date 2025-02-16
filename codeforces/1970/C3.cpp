#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 200005
vector<ll> adj[MAXN];
pair<ll, ll> store[MAXN];
ll res[MAXN];
void dfs1(ll u, ll v)
{
    for(auto child: adj[v])
    {
        if(u != child)
        {
            dfs1(v, child);
            if(store[child].first == 0)
            {
                store[v].first = 1;
                store[v].second++;
            }
        }
    }
}
void dfs2(ll u, ll v)
{
    for(auto child: adj[v])
    {
        if(u != child)
        {
            //reroot between v and child
            auto og1 = store[child];
            auto og2 = store[v];
            if(store[child].first == 0)
            {
                if(store[v].second == 1)
                {
                    store[v].first = 0;
                    store[v].second = 0;
                    store[child].first = 1;
                    store[child].second = 1;
                }
                else
                {
                    store[v].second--;
                }
            }
            else
            {
                if(store[v].first == 0)
                {
                    store[child].second++;
                }
            }
            res[child] = store[child].first;
            dfs2(v, child);
            store[child] = og1;
            store[v] = og2;
        }
    }
}
int main()
{
    ll n, t; cin >> n >> t;

    for(int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> startingnodes(t);
    dfs1(1, 1);
    res[1] = store[1].first;
    //cout << res[1] << "chick\n";
    // for(int i = 1; i <= n; i++)
    // {
    //     cout << store[i].first << " " << store[i].second << "\n";
    // }
    dfs2(1, 1);
    //cout << res[1] << "chick\n";
    for(int i = 0; i < t; i++)
    {
        cin >> startingnodes[i];
    }
    for(int i = 0; i < t; i++)
    {
        if(res[startingnodes[i]] == 1)
        {
            cout << "Ron\n";
        }
        else
        {
            cout << "Hermione\n";
        }
    }
}