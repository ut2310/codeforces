#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 200005
set<ll> adj[MAXN];
ll deg[MAXN];
ll store[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq; 
    for(int i = 0; i < n - 1; i++)
    {
        ll a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    
    for(int i = 1; i <= n; i++)
    {
        store[i] = 1;
        if(deg[i] == 1) pq.push(make_pair(store[i], i));
    }
    bool flag = true;
    while(pq.size() > 0)
    {
        auto curr = pq.top();
        pq.pop();
        for(ll itr: adj[curr.second])
        {
            adj[itr].erase(curr.second);
            deg[itr]--;
            if(store[curr.second] > store[itr])
            {
                flag = false;
            }
            else
            {
                store[itr] += store[curr.second];
                if(deg[itr] == 1)
                {
                    pq.push(make_pair(store[itr], itr));
                }
            }
        }
        if(!flag)
        {
            break;
        }
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";

    

}