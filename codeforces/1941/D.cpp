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
        ll n, c; cin >> n >> c;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll total = ((c + 1) * c)/2 + (c + 1);
        ll sub1 = 0;
        for(int i = 0; i < n; i++)
        {
            sub1 += a[i]/2 + 1;
        }
        ll sub2 = n * c + n;
        for(int i = 0; i < n; i++)
        {
            sub2 -= a[i];
        }
        ll both = 0;
        ll even = 0;
        ll odd = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] % 2 == 0)even++;
            else odd++;
        }
        both += (even * (even - 1)/2) + ((odd)*(odd - 1))/2 + n;
        ll res = total - sub1 - sub2 + both;
        cout << res << "\n";
    }
}