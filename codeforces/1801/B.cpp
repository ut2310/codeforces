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
        ll n; cin >> n;
        vector<pair<ll, ll>> store(n);
        map<ll, ll> freq;
        set<ll> track;
        for(int i = 0; i < n; i++)
        {
            ll a, b; cin >> a >> b;
            store[i] = make_pair(a, b);
            freq[b]++;
            track.insert(b);
        }
        sort(store.begin(), store.end());
        ll cmex = -1e18;
        ll res = 1e18;
        for(int i = n - 1; i >= 0; i--)
        {
            ll max1 = store[i].first;
            freq[store[i].second]--;
            //cout << freq[store[i].second] << " " << store[i].second << "\n";
            if(freq[store[i].second] == 0) track.erase(store[i].second);
            // for(auto j: track) cout << j << "\n";
            // cout << "\n";
            if(cmex  >= max1)
            {
                res = min(res, cmex - max1);
            }
            else
            {
                res = min(res, abs(cmex - max1));
                auto itr1 = track.upper_bound(max1);
                if(itr1 != track.begin())
                {
                    auto itr2 = prev(itr1);
                    ll pos2 = *itr2;
                    res = min(res, abs(max1 - pos2));
                }
                ll pos1 = *itr1;
                //cout << res << "\n";
                if(itr1 != track.end()) res = min(res, abs(max1 - pos1));
                
                //cout << track.size() << " " << max1 << " " << pos1 << " " << pos2 << " " << res << "\n";

            }
            cmex = max(cmex, store[i].second);
        }
        cout << res << "\n";
    }
}
