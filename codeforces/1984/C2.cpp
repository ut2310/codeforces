using namespace std;
#include <bits/stdc++.h>
#define ll long long
ll M;
ll power(ll x, ll y)
{
    ll temp;
    if (y == 0)
        return 1;
    temp = (power(x, y / 2)) % M;
    if (y % 2 == 0)
        return (temp * temp) % M;
    else
        return (x * temp * temp) % M;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    M = 998244353;
    while(t-->0)
    {
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> ps(n);
        ps[0] = a[0];
        for(int i = 1; i < n; i++)
        {
            ps[i] = ps[i - 1] + a[i];
        }
        ll min1 = 0;
        for(int i = 0; i < n; i++)
        {
            min1 = min(min1, ps[i]);
        }
        if(min1 >= 0)
        {
            ll res = power(2, n);
            if(res < 0) res += M;
            cout << res << "\n";
        }
        else
        {
            ll track = 0;
            ll res = 0;
            for(int i = 0; i < n; i++)
            {
                if(ps[i] < 0) track++;
                if(ps[i] == min1)
                {
                    ll first = power(2, i - (track - 1)) % M;
                    ll second = power(2, n - i - 1) % M;
                    ll addOn = first * second;
                    addOn %= M;
                    res += addOn;
                    res %= M;
                }
            }
            if(res < 0) res += M;
            cout << res << "\n";
        }
        
    }
}