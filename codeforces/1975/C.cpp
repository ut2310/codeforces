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
        ll n; cin >> n;
        vector<ll> a(n);
        vector<pair<ll, ll>> b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = make_pair(a[i], i);
        }
        sort(b.begin(), b.end());
        ll res = -1;
        for(int i = n - 1; i >= 0; i--)
        {
            ll num = b[i].first;
            ll index = b[i].second;
            if(index + 1 < n && a[index + 1] >= num)
            {
                res = num;
                break;
            }
            if(index + 2 < n && a[index + 2] >= num)
            {
                res = num;
                break;
            }
            if(index - 1 >= 0 && a[index - 1] >= num)
            {
                res = num;
                break;
            }
            if(index - 2 >= 0 && a[index - 2] >= num)
            {
                res = num;
                break;
            }
        }
        cout << res << "\n";
    }
}    