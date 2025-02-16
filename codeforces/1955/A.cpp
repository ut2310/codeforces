#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, a, b; cin >> n >> a >> b;
        if(2 * a <= b)
        {
            cout << n * a << "\n";
        }
        else
        {
            ll res = n/2 * b + n % 2 * a;
            cout << res << "\n";
        }
    }
}