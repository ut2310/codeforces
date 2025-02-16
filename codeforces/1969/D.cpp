#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        vector<ll> b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<pair<ll, ll>> track;
        for(int i = 0; i < n; i++)
        {
            track.push_back(make_pair(b[i], a[i]));
        }
        sort(track.begin(), track.end());
        reverse(track.begin(), track.end());
        ll res = 0;
        ll ibuy = 0;
        ll iprofit = 0;
        priority_queue<ll> pq;
        for(int i = 0; i < k; i++)
        {
            ibuy += track[i].second;
            pq.push(track[i].second);
        }
        for(int i = k; i < n; i++)
        {
            if(track[i].first > track[i].second)
            {
                iprofit += track[i].first - track[i].second;
            }
        }
        res = max(res, iprofit - ibuy);
        if(k > 0)
        {
            for(int i = 1; i <= n - k; i++)
            {
                ll curr = pq.top();
                pq.pop();
                pq.push(track[i + k - 1].second);
                ibuy -= curr;
                ibuy += track[i + k - 1].second;
                if(track[i + k - 1].first > track[i + k - 1].second)
                {
                    iprofit -= track[i + k - 1].first - track[i + k - 1].second;
                }
                res = max(res, iprofit - ibuy);
            }
        }
        
        cout << res << "\n";

    }
    
}