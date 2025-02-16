#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, x, y; cin >> n >> x >> y;
        vector<ll> pos(x);
        set<ll> track;
        for(int i = 0; i < x; i++)
        {
            cin >> pos[i];
            track.insert(pos[i]);
        }
        sort(pos.begin(), pos.end());
        ll res = 0;
        ll useless = 0;
        map<ll, ll> addOn;
        for(int i = 1; i < x; i++)
        {
            if(pos[i] - pos[i - 1] == 2)
            {
                res++;
                useless++;
            }
        }
        if(track.count(n) > 0 && track.count(2) > 0 && track.count(1) == 0)
        {
            res++;
            useless++;
        }
        if(track.count(n - 1) > 0 && track.count(1) > 0 && track.count(n) == 0)
        {
            res++;
            useless++;
        }
        set<ll> visited;
        for(int i = 0; i < x; i++)
        {
            
            ll look = pos[i] - 2;
            if(look <= 0) look += n;
            if(track.count(look) == 0)
            {
                visited.insert(look);
                ll be1 = look - 1;
                ll be2 = look - 2;
                ll af1 = look + 1;
                ll af2 = look + 2;
                
                if(be1 <= 0) be1 += n;
                if(be2 <= 0) be2 += n;
                if(af1 > n) af1 -= n;
                if(af2 > n) af2 -= n;
                if(track.count(be1) == 0 && track.count(be2) > 0)
                {
                    addOn[look]++;
                }
                if(track.count(af1) == 0 && track.count(af2) > 0)
                {
                    addOn[look]++;  
                }
            }
        }
        for(int i = 0; i < x; i++)
        {
            
            ll look = pos[i] + 2;
            if(look > n) look -= n;
            if(track.count(look) == 0 && visited.count(look) == 0)
            {
                ll be1 = look - 1;
                ll be2 = look - 2;
                ll af1 = look + 1;
                ll af2 = look + 2;
                
                if(be1 <= 0) be1 += n;
                if(be2 <= 0) be2 += n;
                if(af1 > n) af1 -= n;
                if(af2 > n) af2 -= n;
                if(track.count(be1) == 0 && track.count(be2) > 0)
                {
                    addOn[look]++;
                }
                if(track.count(af1) == 0 && track.count(af2) > 0)
                {
                    addOn[look]++;  
                }
            }
        }
        ll amt = 0;
        ll total = x;
        vector<ll> curr2;
        for(auto j: addOn)
        {
            curr2.push_back(j.second);
        }
        sort(curr2.begin(), curr2.end());
        for (int i = curr2.size() - 1; i >= 0; i--)
        {
            if(amt == y) break;
            res += curr2[i];
            useless += curr2[i];
            amt++;
        }
        //cout << res << " " << useless.size() << "\n";
        total += amt;
        ll left = n - useless - total;
        total += min((y - amt), left);
        res += total - 2;
        cout << res << "\n";
    }
}