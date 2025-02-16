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
        ll a, b; cin >> a >> b;
        ll res = (b + 1)/2;
        if(b % 2 == 0)
        {
            ll add = 7 * (b/2);
            if(a > add)
            {
                res += (a - add + 14)/15;
            }
        }
        else
        {
            ll add = 7 * (b/2) + 11;
            if(a > add)
            {
                res += (a - add + 14)/15;
            }
        }
        cout << res << "\n";
    }
}