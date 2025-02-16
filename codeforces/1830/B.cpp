using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
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
        map<pair<ll, ll>, ll> mp;
        for(int i = 0; i < n; i++)
        {
            mp[make_pair(a[i], b[i])]++;
        }
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            ll m1 = a[i];
            ll b1 = -1 * b[i];
            for(int x = 1; x * x <= 2 * n; x++)
            {
                ll y = m1 * x + b1;
                if(y >= 1 && y * y <= 2 * n && mp.count(make_pair(x, y)) > 0) res += mp[make_pair(x, y)];
            }
            if(a[i] * a[i] == 2 * b[i]) res--;
        }
        cout << res/2 << "\n";
    }
}