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
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll lcm = 1;
        for(int i = 0; i < n; i++)
        {
            ll curr = __gcd(lcm, a[i]);
            lcm *= a[i];
            lcm/=curr;
        }
        vector<ll> res(n);
        ll total = 0;
        for(int i = 0; i < n; i++)
        {
            res[i] = lcm/a[i];
            total += res[i];
        }
        if(total < lcm)
        {
            for(int i = 0; i < n; i++)
            {
                cout << res[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "-1\n";
        }

    }
}