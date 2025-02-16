using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll curr = 0;
        ll pow = 2;
        ll x = 1000000000;
        while(pow < 1e9)
        {
            ll a = pow - curr;
            ll b = a + pow;
            if(b > 2e9) break;
            cout << "? " << a << " " << b << "\n";
            //cout << __gcd(x + a, x + b) << " " << curr << "\n";
            cout.flush();
            ll ans; cin >> ans;
            if(ans == pow/2) curr += pow/2;
            pow *= 2;
        }
        ll y = 536870912;
        
        if(curr + y <= 1e9)
        {
            cout << "? " << y + curr << " " << 2 * (y + curr) << "\n";
            cout.flush();
            ll ans; cin >> ans;
            if(ans == (y + curr)) curr += y;
        }
        cout << "! " << curr << "\n";

    }
}