#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
vector<ll> adj[MAXN];
ll res;
void dfs(ll p, ll v, string &s, bool flag)
{
    if(s[v] == 'P')
    {
        for(auto u: adj[v])
        {
            if(u != p)
            {
                if(s[u] == 'S')
                {
                    res++;
                    dfs(v, u, s, true);
                }
                else
                {
                    dfs(v, u, s, flag);
                }
            }
        }
    }
    else if(s[v] == 'S')
    {
        for(auto u: adj[v])
        {
            if(u != p)
            {
                if(s[u] == 'P')
                {
                    res++;
                    dfs(v, u, s, true);
                }
                else
                {
                    dfs(v, u, s, flag);
                }
            }
        }
    }
    else
    {
        for(auto u: adj[v])
        {
            if(u != p)
            {
                if(s[u] == 'S')
                {
                    res++;
                    dfs(v, u, s);
                }
                else
                {
                    dfs(v, u, s);
                }
            }
        }
    }
}
int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        res = 0;
        for(int i = 1; i <= n - 1; i++)
        {
            ll a; cin >> a;
            adj[a - 1].push_back(i);
            adj[i].push_back(a - 1);
        }
        string s; cin >> s;
        dfs(1, 1, s, false);
    }
}