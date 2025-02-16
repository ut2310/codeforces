using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
set<ll> adj[MAXN];
ll deg[MAXN];
ll dp[MAXN], dp2[MAXN], dp3[MAXN], depth[MAXN];
void dfs0(ll p, ll v)
{
    for(auto c: adj[v])
    {
        if(c != p)
        {
            dp2[c] = dp2[v] + 1;
            dfs0(v, c);
        }
    }
}
void dfs1(ll p, ll v)
{
    for(auto c: adj[v])
    {
        if(c != p)
        {
            dp3[c] = dp3[v] + 1;
            dfs1(v, c);
        }
    }
}
void dfs2(ll p, ll v)
{
    ll cnt = 0;
    for(auto c: adj[v])
    {
        if(c != p)
        {
            dfs2(v, c);
            if(1 + dp[c] > dp[v]) dp[v] = 1 + dp[c];
            cnt++;
        }
    }
    if(cnt == 0) dp[v] = 0;
}
void dfs3(ll p, ll v)
{
    vector<pair<ll, ll>> store;
    for(auto c: adj[v])
    {
        store.push_back(make_pair(dp[c], c));
    }
    sort(store.begin(), store.end());
    // if(v == 8)
    // {
    //     for(auto i: store)
    //     {
    //         cout << i.first << " " << i.second << "\n";
    //     }
    // }
    for(auto c: adj[v])
    {
        if(p!=c)
        {
            //cout << c << " " << v << " " << dp[c] << " " << dp[v] << "\n";
            ll og1 = dp[c];
            ll og2 = dp[v];
            if(store[store.size() - 1].second != c)
            {
                dp[c] = max(2 + store[store.size() - 1].first, dp[c]);
            }
            else if(store.size() >= 2)
            {
                // if(c == 8 && v == 1)
                // {
                //     for(auto j: store)
                //     {
                //         cout << j.first << " " << j.second << "\n";
                //     }
                // } 
                dp[c] = max(2 + store[store.size() - 2].first, dp[c]);
                dp[v] = store[store.size() - 2].first + 1;
            }
            else
            {
                dp[c] = max(1LL, dp[c]);
                dp[v] = 0;
            }
            //cout << c << " " << v << " " << dp[c] << " " << dp[v] << "\n";
            depth[c] = dp[c];
            dfs3(v, c);
            dp[c] = og1;
            dp[v] = og2;
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t; 
    while(t-->0)
    {
        ll n; cin >> n;
        ll a, b; cin >> a >> b;
        for(int i = 0; i < n - 1; i++)
        {
            ll x, y; cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
            deg[x]++;
            deg[y]++;
        }
        dfs0(a, a); //dp2 stores all distances from a
        dfs1(b, b); //dp3 stores all distances from b
        dfs2(a, a);
        dfs3(a, a);
        depth[a] = dp[a];
        ll res = 1e18;
        for(int i = 1; i <= n; i++)
        {
            ll addOn = max(dp3[i], dp2[i]);
            if(dp2[i] > dp3[i] && (dp2[i] - dp3[i]) % 2 != 0)
            {
                addOn++;
            }
            //cout << addOn << " " << i << " " <<  depth[i] << "\n";
            res = min(res, 2 * (n - 1) - depth[i] + addOn);
        }
        cout << res << "\n";
        //cout << dp2[b] << "\n";
        
        for(int i = 0; i <= n; i++)
        {
            dp[i] = 0; dp2[i] = 0; dp3[i] = 0; depth[i] = 0;
            adj[i].clear();
            deg[i] = 0;
        }

    }
}    