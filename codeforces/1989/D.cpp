using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<ll> c(m);
    for(int i = 0; i < m; i++)
    {
        ll temp; cin >> c[i];
    }
    vector<pair<ll, ll>> diff;
    for(int i =0; i < n; i++)
    {
       diff.push_back(make_pair(a[i], a[i] - b[i]));
    }
    sort(diff.begin(), diff.end());
    ll j = 0; ll best = 1e9; ll b_index = -1;
    vector<ll> dp(1e6 + 1);
    for(int i = 1; i <=1e6; i++)
    {
        while(j < n && i >= diff[j].first)
        {
            if(diff[j].second < best)
            {
                b_index = j;
                best = diff[j].second;
            }
            j++;
        }
        if(best != 1e9)
        {
            ll cnt =  (i - diff[b_index].first)/best + 1;
            ll prev = i - cnt * best;
            dp[i] = dp[prev] + cnt;
            //cout << i << " " << prev << " " << cnt << "\n";
        }
        //if(i <= 10) cout << dp[i] << " ";
    }
    ll res =0;
    for(int i = 0; i < m; i++)
    {
        if(c[i] >= 1e6)
        {
            ll cnt =  (c[i] - diff[b_index].first)/best + 1;
            ll prev = c[i] - cnt * best;
            res += dp[prev] + cnt;
        }
        else
        {
            res += dp[c[i]];
        }
    }
    res *= 2;
    cout << res << "\n";

}