using namespace std;
#include <bits/stdc++.h>
#define ll long long
ll dp[2][201][3601];
int main()
{
    ll n, k1; cin >> n >> k1;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<pair<ll, ll>> info(n + 1);
    for(int i = 1; i <= n; i++){
        ll cnt1 = 0;
        ll cnt2 = 0;
        while(a[i - 1] % 2 == 0){
            a[i - 1] /= 2;
            cnt2++;
        }
        while(a[i - 1] % 5 == 0){
            a[i - 1]/=5;
            cnt1++;
        }
        //cout << i << " " << cnt1 << " " << cnt2 << "\n";
        info[i] = make_pair(cnt1, cnt2);
    }
    for(int i = 0; i <= 0; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 1; k <= 3600; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    //out << dp[0][0][1] << "\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 0; k <= 3600; k++){
                dp[1][j][k] = dp[0][j][k];
                ll check = max(0LL, k - info[i].first);
                // if(i == 1 && j == 1 && k == 2){
                //     cout << dp[0][j - 1][check] << " " << dp[1][j][k] << "\n";
                // }
                if(dp[0][j - 1][check] + info[i].second > dp[1][j][k] && dp[0][j - 1][check] >= 0){
                    dp[1][j][k] = dp[0][j - 1][check] + info[i].second;
                }
                //dp[0][j][k] = dp[1][j][k];
                // if(k <= 4){
                //     cout << i <<  " " << j << " " << k << " " << dp[1][j][k] << "\n";
                // }
            }
            
        }
        for(int j = 1; j <= i; j++){
            for(int k = 0; k <= 3600; k++){
                dp[0][j][k] = dp[1][j][k];
            }
        }
    }
    ll best = 0;
    for(ll k = 0; k <= 3600; k++){
        best = max(best, min(dp[0][k1][k], k));
    }
    cout << best << "\n";
    //bunch of (coins) worth i 2s & j 5s, 

}