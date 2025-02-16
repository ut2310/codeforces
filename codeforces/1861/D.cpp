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
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll p1 = 0;
        vector<pair<ll, ll>> track(n + 1);
        for(int i = 1; i < n; i++)
        {
            ll p1 = track[i].first;
            ll p2 = track[i].second;
            
            if(a[i] >= a[i - 1])
            {
                p1++;
            }
            if(a[i] <= a[i - 1])
            {
                p2++;
            }
            track[i + 1] = make_pair(p1, p2);
            track[i + 1] = make_pair(p1, p2);
        }
        ll res = 1e9;
        vector<pair<ll, ll>> suffix(n + 1);
        for(int i = n - 2; i >= 0; i--)
        {
            ll p1 = suffix[i + 1].first;
            ll p2 = suffix[i + 1].second;
            if(a[i + 1] >= a[i]) p1++;
            if(a[i + 1] <= a[i]) p2++;
            suffix[i] = make_pair(p1, p2);
        }
        for(int i = 0; i <= n; i++)
        {
            //cout << i << " " << track[i].first << "\n";
            if(i > 0) res = min(res, 1 + track[i].first + min(suffix[i].first + 1, suffix[i].second));
            else res = min(res, track[i].first + min(suffix[i].first + 1, suffix[i].second));
            //cout << res << "\n";
        }
        cout << res << "\n";

    }
}