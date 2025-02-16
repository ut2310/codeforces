using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 72
ll arr[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN][MAXN]; //i, j, r, x
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    //cout << dp[1][4][1][0] << "hi\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int r = 0; r < k; r++){
                for(int x = 0; x <= m/2; x++){
                    dp[i][j][r][x] = -1;
                }
            }
        }
    }
    //cout << dp[1][4][1][0] << "hi\n";

    if(m == 1){
        cout << "0\n";
        return 0;
    }
    //cout << dp[1][4][1][0] << "hi\n";

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j][0][0] = 0;
        }
    }
    //cout << dp[1][4][1][0] << "hi\n";

    dp[1][1][arr[1][1] % k][1] = arr[1][1];
    for(int j = 2; j <= m; j++){
        for(int r = 0; r < k; r++){
            for(int x = 1; x <= m/2; x++){
                ll rem = (r - arr[1][j]) % k;
                if(rem < 0) rem += k;
                dp[1][j][r][x] = dp[1][j - 1][r][x];
                if(dp[1][j - 1][rem][x - 1] >= 0){
                    dp[1][j][r][x] = max(dp[1][j - 1][rem][x - 1] + arr[1][j], dp[1][j][r][x]);
                }
            }
        }
    }
    //cout << dp[1][4][1][0] << "hi\n";

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j == 1){
                for(int r = 0; r < k; r++){
                    for(int x = 0; x <= m/2; x++){
                        ll rem = (r - arr[i][j]) % k;
                        if(rem < 0) rem += k;
                        dp[i][j][r][0] = max(dp[i][j][r][0], dp[i - 1][m][r][x]);
                        if(dp[i - 1][m][rem][x] >= 0){
                            dp[i][j][r][1] = max(dp[i][j][r][1], dp[i - 1][m][rem][x] + arr[i][j]);
                        }
                    }
                }
                continue;
            }
            for(int r = 0; r < k; r++){
                for(int x = 0; x <= m/2; x++){
                    ll rem = (r - arr[i][j]) % k;
                    if(rem < 0) rem += k;
                    dp[i][j][r][x] = dp[i][j - 1][r][x];
                    if(x >= 1 && dp[i][j - 1][rem][x - 1] >= 0){
                        dp[i][j][r][x] = max(dp[i][j - 1][rem][x - 1] + arr[i][j], dp[i][j][r][x]);
                    }
                }
            }
        }
    }
    ll res = 0;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         for(int r=0; r < k; r++){
    //             for(int x = 0; x <= m/2; x++){
    //                 cout << i << " " << j << " " << r << " " << x << " " << dp[i][j][r][x] << "\n";
    //             }
    //         }
    //     }
    // }
    for(int x = 0; x <= m/2; x++){
        res = max(res, dp[n][m][0][x]);
    }
    cout << res << "\n";
}