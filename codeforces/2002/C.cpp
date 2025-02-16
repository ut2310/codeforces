using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        vector<pair<ll, ll>> circ;
        for(int i = 0; i < n; i++)
        {
            ll a, b; cin >> a >> b;
            circ.push_back(make_pair(a, b));
        }
        ll xs, ys, xe, ye; cin >> xs >> ys >> xe >> ye;
        ll comp = (xe - xs) * (xe - xs) + (ye - ys) * (ye - ys);
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if((circ[i].first - xe) * (circ[i].first - xe) + (circ[i].second - ye) * (circ[i].second - ye) <= comp)
            {
                flag = false;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}