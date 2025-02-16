#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll M, dp[5005][5005];
int main()
{
    M =  998244353;
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    //dp[i][j] reps how many make i using first j elements
    for(int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    
    for(int i = 1; i <= 5000; i++)
    {
        dp[i][0] = 0;
        for(int j = 0; j < n; j++)
        {
            dp[i][j + 1] = dp[i][j];
            if(a[j] <= i)
            {
                dp[i][j + 1] += dp[i - a[j]][j];
            }
            dp[i][j + 1] %= M;
        }
    }
    ll res = 0;
    for(int i = 1; i <= 5000; i++)
    {
        ll temp = (i + 1)/2;
        res += dp[i][n] * temp;
        //cout << res << "\n";
        // if(i <= 10)
        // {
        //     cout << res << "\n";
        //     cout << i << " " << dp[i][n] << "\n";;
        // } 
        res %= M;
    }
    //cout << res << "\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = a[i]; j < 2 * a[i]; j++)
        {
            ll initial = (j + 1)/2;
            res += dp[j - a[i]][n] * (a[i] - initial);
            res %= M; 
        }
    }
    if(res < 0) res += M;
    cout << res << "\n";

}