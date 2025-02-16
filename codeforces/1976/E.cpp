using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ll n, q; cin >> n >> q;
    vector<ll> l(q); vector<ll> r(q);
    vector<ll> visited(n + 1);
    for(int i = 0; i < q; i++)
    {
        cin >> l[i];
        visited[l[i]] = 1;
    }
    for(int i = 0; i < q; i++)
    {
        cin >> r[i];
        visited[r[i]] = 1;
    }
    vector<pair<ll, ll>> adj(n + 1);
    ll first = -1;
    for(int i = 0; i < q; i++)
    {
        if(first == -1 || first == r[i])
        {
            first = l[i];
        }
        if(adj[l[i]].first == 0 && adj[r[i]].second == 0)
        {
            adj[l[i]] = (make_pair(r[i], adj[l[i]].second));
            adj[r[i]] = make_pair(adj[r[i]].first, l[i]);
        }
        else if(adj[l[i]].first != 0)
        {
            ll prev = adj[l[i]].first;
            adj[l[i]] = make_pair(r[i], adj[l[i]].second);
            adj[r[i]] = make_pair(prev,  l[i]);
            adj[prev] = make_pair(adj[prev].first, r[i]);
        }
        else if(adj[r[i]].second != 0)
        {
            ll prev = adj[r[i]].second;
            adj[prev] = make_pair(l[i], adj[prev].second);
            adj[l[i]] = make_pair(r[i], prev);
            adj[r[i]] = make_pair(adj[r[i]].first, l[i]);
        }
    }
    deque<ll> a;
    a.push_back(first);
    while(adj[first].first != 0)
    {
        ll next = adj[first].first;
        a.push_back(next);
        first = next;
    }
    a.push_back(0);
    a.push_front(0);
    vector<ll> values;
    // for(int i =0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    for(int i = 1; i < a.size(); i++)
    {
        values.push_back(max(a[i], a[i - 1]));
    }
    sort(values.begin(), values.end());
    // for(int i =0; i < values.size(); i++)
    // {
    //     cout << values[i] << " ";
    // }
    // cout << "\n";
    ll options = values.size();
    ll res = 1; ll M = 998244353;
    for(int i = n; i >= 1; i--)
    {
        if(visited[i] == 0)
        {
            ll index = upper_bound(values.begin(), values.end(), i) - values.begin();
            //cout << options << " " << index << "\n";
            res *= (options - index); res = res % M;
            //cout << i << " " << options - index << "\n";
            options++;
        }
    }
    cout << res << "\n";
    
}