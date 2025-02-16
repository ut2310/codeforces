using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, m, k; cin >> n >> m >> k;
        vector<pair<ll, ll>> a;
        for(int i = 0; i < m; i++)
        {
            ll l, r; cin >> l >> r;
            a.push_back(make_pair(l, 0));
            a.push_back(make_pair(r + 1, 1));
        }
        sort(a.begin(), a.end());
        vector<ll> ps(n + 5);
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i].second == 0) ps[a[i].first]++;
            if(a[i].second == 1) ps[a[i].first]--;
        }
        for(int i = 1; i <= n; i++)
        {
            ps[i] = ps[i - 1] + ps[i];
        }
        ll cnt = 0; ll res = 0;
        for(int i = 1; i <= n; i++)
        {
            if(ps[i] == 0) cnt++;
        }
        priority_queue<pair<ll, ll>> pq;
        for(int i = 1; i <= n; i++)
        {
            
            if(ps[i] == 2)
            {
                
            }
        }
        res += cnt;

    }
}