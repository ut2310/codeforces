#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll res = a/2 + b/2 + c/2 + d/2;
        if(a %2 == 1 && b % 2 == 1 && c % 2 == 1) res++;
        cout << res << "\n";
    }
}