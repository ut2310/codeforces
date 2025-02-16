using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
ll dp[MAXN][105];
ll M;
ll power(ll x, ll y, ll M)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
ll modInverse(ll A)
{
    return power(A, M - 2, M);
}
void mod(ll &A)
{
    A = A % M;
    if(A < 0) A += M;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N; cin >> N; M = 998244353;
    vector<ll> prob(N + 1);
    for(int i = 1; i <= N; i++)
    {
        cin >> prob[i];
    }
    vector<ll> ans(N + 1);
    ll i100 = modInverse(100);
    if(i100 < 0) i100 += M;
    ans[1] = i100 * (100 - prob[1]);
    mod(ans[1]);
    ans[1] = modInverse(ans[1]);  
    mod(ans[1]);
    //cout << ans[1] << "\n";
    for(int j = 1; j <= 99; j++)
    {
        dp[1][j] = 1;
        dp[1][j] *= ans[1];
        //if(j == 50) cout << dp[1][50] << "\n";
        mod(dp[1][j]);
        dp[1][j] *= j;
        mod(dp[1][j]);
        dp[1][j] *= j;
        mod(dp[1][j]);
        dp[1][j] *= i100;
        mod(dp[1][j]);
        dp[1][j] *= i100;
        mod(dp[1][j]);
        //if(j == 20) cout << dp[1][j] << "\n";

    }
   // cout << ans[1] << "\n";
    for(int i = 2; i <= N; i++)
    {
        ans[i] = 1 + dp[i - 1][prob[i]];
        mod(ans[i]);
        ll mult =  (i100*(100 - prob[i]));
        mod(mult);
        mult = modInverse(mult);
        mod(mult);
        ans[i] *= mult;
        mod(ans[i]);
        //cout << i - 1 << " " << prob[i] << " " << dp[i - 1][prob[i]] << " " << ans[i] << "\n";
        for(int j = 1; j <= 99; j ++)
        {
            dp[i][j] = dp[i - 1][j] * j;
            mod(dp[i][j]);
            dp[i][j] *= i100;
            mod(dp[i][j]);
            //if(j == 20 && i == 2) cout << dp[i - 1][j] << " " << dp[i][j] << "\n";
            ll addOn = ans[i];
            mod(addOn);
            addOn *= j;
            mod(addOn);
            addOn *= j;
            mod(addOn);
            addOn *= i100;
            mod(addOn);
            addOn *= i100;
            mod(addOn);
            dp[i][j] += addOn;
            mod(dp[i][j]);
        }
    }
    ll res = 0;
    for(int i = 1; i <= N; i++)
    {
        res += ans[i];
        mod(res);
    }
    cout << res << "\n";
}