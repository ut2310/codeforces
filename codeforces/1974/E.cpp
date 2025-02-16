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
        ll m, x; cin >> m >> x;
        ll size = 0;
        vector<pair<ll, ll>> store;
        for(int i = 0; i < m; i++)
        {
            ll c, h; cin >> c >> h;
            store.push_back(make_pair(c, h));
            size += h;
        }
        vector<ll> dp(size + 1);
        for(int i = 0; i <= size; i++)
        {
            dp[i] = -1e18;
        }
        dp[0] = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = size; j >= 0; j--)
            {
                if(dp[j] >= store[i].first)
                {
                    dp[j + store[i].second] =max(dp[j + store[i].second], (dp[j] - store[i].first + x));
                }
                dp[j] += x;
                //cerr << dp[j] << " ";
            }
            //cerr << "\n";
        }
        ll res = 0;
        for(int j = 0; j <= size; j++)
        {
            if(dp[j] >= 0) res= j;
        }
        cout << res << "\n";
    }
}