using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll x, y; cin >> x >> y;
        if(x % 10 == 0) cout << x * y << "\n";
        else if(x % 10 == 5)
        {
            ll res = max(x * y, (x + 5) * (y - 1));
            cout << res << "\n";
        }
        else
        {
            ll res = x * y;
            while(x % 10 != 2)
            {
                x += (x % 10);
                y--;
                res = max(res, x * y);       
            }
            ll z = (5 * y - x)/40;
            ll operations = 4 * z;
            for(ll i = operations - 10; i <= operations + 10; i++)
            {
                if(i >= 0)
                {
                    ll addOn = 20 * (i/4);
                    if(i % 4 == 1) addOn +=2;
                    if(i % 4 == 2) addOn += 6;
                    if(i % 4 == 3) addOn += 14;
                    res = max(res, (x + addOn) * (y - i));
                }
            }
            cout << res << "\n";
        }
        
    }
}