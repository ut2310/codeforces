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
        ll n, m; cin >> n >> m;
        ll res = 0;
        ll curr = 1;
        ll track = 0;
        ll bit = 0;
        for(int i = 0; i <= 31; i++)
        {
            if(n & (1 << i))
            {
                bit = i;
            }
        }
        for(int i = 0; i <= 31; i++)
        {
            if(n & (1 << i))
            {
                res += curr;
                track += curr;
            }
            else
            {
                //cout << curr << " " << track << " " << m << "\n";
                if(curr - track <= m || (track <= (m - 1) && i < bit))
                {
                    res += curr;
                }
            }
            curr *= 2;
        }
        cout << res << "\n";
    }
}