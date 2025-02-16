#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll cmex = 0;
        vector<ll> res(n);
        for(int i = 0; i < n; i++)
        {
            if(a[i] > 0)
            {
                res[i] = cmex;
                cmex+=a[i];
            }
            else if(a[i] < 0)
            {
                res[i] = cmex + -1 * a[i];
            }
        }
        for(int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}