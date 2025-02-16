using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 505
ll dp[MAXN][MAXN], dp2[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, k, M; cin >> n >> k >> M;
        for(int i = 0; i <= k; i++){
            dp[0][i] = 1;
            dp2[0][i] = 1;
        }
        for(int i = 0; i <= n; i++){
            dp2[i][0] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp2[i][j] += dp2[i][j - 1];
                dp2[i][j] %= M;
                for(int i1 = 0; i1 <= j; i1++){
                    dp2[i][j] += dp2[i - 1][i1] * dp2[i - 1][j - i1];
                    dp2[i][j] %= M;
                }
            }
        }
        vector<ll> power(505);
        power[0] = 1;
        for(int i = 1; i <= 504; i++){
            power[i] = power[i - 1] * 2;
            power[i] %= M;
            if(power[i] < 0){
                power[i] += M;
            }
        }
        
        //dp[1][0] is acc 0
        for(int i = 1; i <= n - 1; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= M;
                //u want to split j operations between the two subtrees
                for(int i1 = 0; i1 <= (j - 1)/2; i1++){
                    dp[i][j] += dp2[i - 1][i1] * dp[i - 1][j - i1]; //i1 operations on 2^(i + 1) - 1 nodes 2^(i )
                    dp[i][j] %= M;
                }
                //cout << i << " " << j << " " << dp[i][j] << "\n";

            }
        }
        //cout << dp[n - 1][k] << "\n";
        dp[n - 1][k] *= power[n - 1];
        dp[n - 1][k] %= M;
        cout << dp[n - 1][k] << "\n";
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j] = 0;
                dp2[i][j] = 0;
            }
        }
        
    }
}