using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, k; cin >> n >> k;
        vector<ll> l(n); vector<ll> r(n);
        for(int i = 0; i < n; i++)
        {
            cin >> l[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> r[i];
        }
        ll total = 0;
        for(int i = 0; i < n; i++)
        {
            total += r[i] - l[i] + 1;
        }
        if(total < k)
        {
            cout << -1 << "\n";
        }
        else
        {
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            ll track = 0;
            ll res = 1e18;
            for(int i = 0; i < n; i++)
            {
                pq.push(r[i] - l[i] + 1);
                track += r[i] - l[i] + 1;
                while(track >= k && pq.size() > 0)
                {
                    ll top = pq.top();
                    if(track - top >= k && top <= 1)
                      {
                        track -= top;
                        pq.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                if(track >= k)
                {
                    ll currsize = pq.size();
                    //cout << currsize << " " << r[i] << " " << track << " " << k << "\n";
                    res = min(res, 2 * currsize + r[i] - (track - k));
                }
            }
            cout << res << "\n";
        }
    }
}