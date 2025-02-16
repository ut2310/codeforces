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
        ll l, r; cin >> l >> r;
        set<ll> powers;
        map<ll, ll> mp;
        ll curr = 1;
        powers.insert(1);
        ll res = 0;
        for(ll i = 1; i <= 31; i++)
        {
            curr *= 2;
            if(curr > r)
            {
                break;
            }
            else
            {
                res++;
            }
        }
        cout << res << "\n";
        
    }
}