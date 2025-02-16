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
    {
        ll x1 = temp * temp;
        x1 %= M;
        return (x * x1) % M;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    M = 1000000007;
    while(t-->0)
    {
        ll l, r, k; cin >> l >> r >> k;
        if(k <= 9)
        {
            ll x = 9/k;
            x++;
            ll res1 = power(x, l);
            res1%=M;
            ll res2 = power(x, r - l) - 1;
            res2%=M;
            //cout << x << " " << res1 << " " << res2 << "\n";
            ll res = res1 * res2;
            res%=M;
            if(res < 0) res += M;
            cout << res << "\n";

        }
        else
        {
            cout << "0\n";
        }
    }
}