#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, m; cin >> n >> m;;
        ll res = 0;
        for(int x = 1; x <= n + 1; x++)
        {
            if(m * (x * m - 1) <= n)
            {
                res += m;
            } 
            else
            {
                ll low = 1;
                ll high = m; 
                while(low < high)
                {
                    ll mid = (low + high + 1)/2;
                    if(mid * (x * mid - 1) <= n) low = mid;
                    else high = mid - 1;
                }
                res += low;
            }
        }
        res--;
        cout << res << "\n";
    }
}