using namespace std;
#include <bits/stdc++.h>
#define ll long long

pair<pair<ll, ll>, ll> dp[65][65];
ll pow2[65];
ll M;
ll choose(ll x)
{
    ll res = 1;
    x%=M;
    res *= x;
    res %= M;
    res *= (x - 1);
    res %= M;
    res *= (500000004LL);
    res %= M;
    return res;
}
pair<pair<ll, ll>, ll> recur(ll n, ll k)
{
    if(n == 0)
    {
        return make_pair(make_pair(1, 1), 1);
    }
    if(k == 0)
    {   
        return make_pair(make_pair(1, 0), 1);
    }
    ll bit = 0;
    for(ll i = 60; i >= 0; i--)
    {
        if(n & (1LL << i))
        {
            bit = i;
            break;
        }
    }

    auto ans = recur(n - pow2[bit], k - 1);
    //cout << ans.second << " " << bit << "\n";
    ll prefix = 0; ll suffix = 0; ll res = 0;
    if(dp[bit][k].first.first == pow2[bit])
    {
        prefix = ans.first.first + dp[bit][k].first.first;
    }
    else
    {
        prefix = dp[bit][k].first.first;
    }
    if(ans.first.second == (n - pow2[bit]))
    {
        suffix = ans.first.second + dp[bit][k].first.second;
    }
    else
    {
        suffix = dp[bit][k].first.second;
    }
    res += ans.second + dp[bit][k].second;
    
    res %= M;
    if(bit <= k)
    {
        res -= choose(dp[bit][k].first.second);
        res %= M;
        res -= choose(ans.first.first);
        res %= M;
        res += choose(ans.first.first + dp[bit][k].first.second);
        res %= M;
    }
    //cout << n << " " << k << " " << ans.first.first << " " << dp[bit][k].first.second << " " <<  ans.second << " " << dp[bit][k].second << " " << res << "\n";
    return make_pair(make_pair(prefix, suffix), res);


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t; M = 1000000007;
    dp[0][0] = make_pair(make_pair(1, 1), 1);
    for(ll i = 1; i < 65; i++)
    {
        dp[0][i] = make_pair(make_pair(1, 1), 1);
    }
    for(ll j = 1; j < 65; j++)
    {
        dp[j][0] = make_pair(make_pair(1, 0), 1);
    }   
    ll curr = 1;
    pow2[0] = 1;
    for(ll i = 1; i <= 60; i++)
    {
        curr *= 2;
        pow2[i] = curr;
        for(ll j = 1; j <= 60; j++)
        {
            ll prefix = 0; ll suffix = 0; ll ans = 0;
            if(dp[i - 1][j].first.first == curr/2)
            {
                prefix = curr/2 + dp[i - 1][j - 1].first.first;
            }
            else
            {
                prefix = dp[i - 1][j].first.first;
            }
            if(dp[i - 1][j - 1].first.second == curr/2)
            {
                suffix = curr/2 + dp[i - 1][j].first.second;
            }
            else
            {
                suffix = dp[i - 1][j - 1].first.second;
            }
            //if(i == 15 && j == 15) cout << prefix << " " << suffix << "\n";
            ans += dp[i - 1][j].second + dp[i - 1][j - 1].second;
            ans %= M;
            //if(i == 15 && j== 15) cout <<  dp[i - 1][j].first.second << " " << dp[i - 1][j - 1].first.first << " " << dp[14][15].second << " " << dp[14][14].second << " " <<  ans << "\n";
            if(j >= i - 1)
            {
                ans -= choose(dp[i - 1][j].first.second % M);
                ans %= M;
                ans -= choose(dp[i - 1][j - 1].first.first % M);
                ans %= M;
                //if(i == 15 && j == 15) cout << ans << "\n";
                ll total = dp[i - 1][j].first.second + dp[i - 1][j - 1].first.first;
                total%=M;
                //if(i == 15 && j == 15) cout << total << " " << choose(total) << "\n";
                if(total < 0) total += M;
                ans += choose(total);
                ans %= M;
            }
            if(ans < 0) ans += M;
            dp[i][j] = make_pair(make_pair(prefix, suffix), ans);
        }
    }
    //cout << dp[15][15].second << "\n";
    //cout << "\n";
    //cout << dp[50][15].second << "\n"; 
    while(t-->0)
    {
        ll n, k; cin >> n >> k;
        n = n - 1;
        auto res = recur(n, k);
        ll final_ans = res.second;
        if(final_ans < 0) final_ans += M;
        cout << final_ans << "\n";
        
        
    }
}