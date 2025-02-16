using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dp[MAXN][2], M;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    M = 998244353;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(a[0] == 0){
            dp[0][0] = 1;
            dp[0][1] = 1;
        }
        else{
            dp[0][1] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= 1; j++){
                if(j == 0){
                    if(a[i] == a[i - 1]){
                        dp[i][0] += dp[i - 1][0];
                        dp[i][0] %= M;
                    }
                    if(i == 1){
                        if(a[i] == 1) dp[i][0]++;
                    }
                    else if(a[i - 2] + 1 == a[i]){
                        dp[i][0] += dp[i - 2][0];
                        dp[i][0] %= M;
                    }
                }
                else{
                    //previous guy must tell truth
                    dp[i][1] += dp[i - 1][0];
                    dp[i][1] %= M;
                }
            }
            //cout << i << " " <<  dp[i][0] << " " << dp[i][1] << "\n";
        }
        ll res = dp[n - 1][0] + dp[n - 1][1];
        res %= M;
        if(res < 0) res += M;
        cout << res << "\n";
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
    }
}