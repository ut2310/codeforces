using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 22
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dp[51][51];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(ll i = 2; i <= 50; i++){
        for(ll j = 0; j <= i; j++){
            if(j == 0 || j == i){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
            // if(i <= 10){
            //     cout << i << " " << j << dp[i][j] << "\n";
            // }
        }
        
    }
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        ll res = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            res += a[i];
        } 
        if(n > 1) res = max(res, abs(a[0] - a[n - 1]));
        for(ll i = 2; i <= n; i++){
            ll temp = 0;
            for(int j = 0; j < i; j++){
                if(j % 2 == 0){
                    temp += dp[i - 1][j] * a[j];
                }
                else{
                    temp -= dp[i - 1][j] * a[j];
                }
            }
            ll temp3 = 0;
            ll temp2 = 0;
            for(int j = n - i; j <= n - 1; j++){
                if(j % 2 == 0){
                    temp3 += dp[i - 1][temp2] * a[j];
                }
                else{
                    temp3 -= dp[i - 1][temp2] * a[j];
                }
                temp2++;
            }
            //cout << i << " " << temp << " " << temp3 << "\n";
            if(i < n) res = max(res, abs(temp3 - temp));
            else res = max(res, abs(temp));
        }
        cout << res << "\n";
    }
}