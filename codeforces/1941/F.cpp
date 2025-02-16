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
        ll n, m, k; cin >> n >> m >> k;
        vector<ll> a(n); 
        vector<ll> d(m);
        vector<ll> f(k);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < m; i++)
        {
            cin >> d[i];
        }
        for(int i = 0; i < k; i++)
        {
            cin >> f[i];
        }
        sort(d.begin(), d.end());
        sort(f.begin(), f.end());
        vector<pair<ll, pair<ll, ll>>> diff;
        for(int i = 1; i < n; i++)
        {
            diff.push_back(make_pair(a[i] - a[i - 1], make_pair(a[i - 1], a[i])));
        }
        sort(diff.begin(), diff.end());

        pair<ll, pair<ll, ll>> diff1 = diff[diff.size() - 1];
        ll res = diff1.first;
        for(int i = 0; i < m; i++)
        {   
            //a and b want closest number to (a + b)/2
            ll goal = (diff1.second.first + diff1.second.second)/2;
            ll i1 = upper_bound(f.begin(), f.end(), goal - d[i]) - f.begin();

            if(i1 >= 0 && i1 < f.size())
            {
                ll pos1 = f[i1] + d[i];
                if(diff1.second.first < pos1 && pos1 < diff1.second.second)
                {
                    res = min(res, max(pos1 - diff1.second.first, diff1.second.second - pos1));
                }
            }
            if((i1 - 1) >= 0 && i1 - 1 < f.size())
            {
                ll pos1 = f[i1 - 1] + d[i];
                if(diff1.second.first < pos1 && pos1 < diff1.second.second)
                {
                    res = min(res, max(pos1 - diff1.second.first, diff1.second.second - pos1));
                }
            }
        }
        if(diff.size() >= 2)
        {
            res = max(res, diff[diff.size() - 2].first);
        }
        cout << res << "\n";

    }
}