using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 5005
ll dp[MAXN][8200];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        dp[0][0] = 1;
        ll get = 1;
        while(get < n){
            get *= 2; get++;
        }
        vector<ll> cnt(n + 5);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= n + 4; j++){
                cnt[j] = 0;
            }
            ll cmex = 0;
            for(int j = 0; j <= get; j++){
                dp[i][j] = dp[i - 1][j];
            }
            for(int l = i - 1; l >= 0; l--){ //look at segment l to i - 1
                cnt[a[l]]++;
                while(cnt[cmex] > 0) cmex++;
                if(cnt[a[l]] == 1 && cnt[a[i - 1]] == 1 && a[l] < cmex && a[i - 1] < cmex){
                    //mex of l to i - 1 is cmex and check if 
                    for(int j = 0; j <= get; j++){
                        //cout << i << " " << j << " " << l << " " << (cmex ^ j) << " " << dp[l][cmex ^ j] << "\n";
                        if(dp[l][cmex ^ j] == 1){
                            dp[i][j] = 1;
                        }
                    }
                    //cout << "chicken\n";
                }
            }
        }
        ll res = -1;
        for(int j = get; j >= 0; j--){
            if(dp[n][j] == 1){
                res = j;
                break;
            }
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= get; j++){
                dp[i][j] = 0;
            }
        }
        cout << res << "\n";
    }
}