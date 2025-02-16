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
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> dp1(n);
        dp1[0] = a[0];
        ll res = 0;
        ll track = a[0];
        for(int i = 1; i < n; i++)
        {
            dp1[i] = dp1[i - 1] + a[i];
            if(dp1[i] < track)
            {
                track = dp1[i];
                res = i;
            }
        }
        ll final_res = track;
        if(final_res < 0) final_res *= -1;
        for(int i = res + 1; i < n; i++)
        {
            final_res += a[i];
        }
        cout << final_res << "\n";
    }
}