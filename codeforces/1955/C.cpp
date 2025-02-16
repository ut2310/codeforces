#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        ll curr = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            curr += a[i];
        }
        if(k >= curr)
        {
            cout << n << "\n";
        }
        else
        {
            ll i1 = 0;
            ll i2 = n - 1;
            ll cnt = 0;
            //cout << k << "\n";
            while(k > 0)
            {
                if(a[i1] <= a[i2])
                {
                    if(a[i1] * 2 - 1 <= k)
                    {
                        k -= a[i1] * 2 - 1;
                        a[i2] -= a[i1] - 1;
                        i1++;
                        if(k >  0)
                        {
                            a[i2] -= 1;
                            if(a[i2] == 0) i2--;
                            k--;
                        }
                        
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if(a[i2] * 2 <= k)
                    {
                        a[i1] -= a[i2];
                        k -= 2 * a[i2];
                        i2--;
                    }
                    else
                    {
                        break;
                    }
                }
                //cout << i1 << " " << i2 << " " << k << "\n";
            }
            
            ll res = i1 + n - 1 - i2;
            //cout << i1 << " " << i2 << " " << res << "\n";
            cout << res << "\n";
        }
        
    }
}