using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 24
#define ALPHABETSIZE 26
ll dp[MAXN][2][2][2];
ll dp2[MAXN][2][2][2];
ll input[3][MAXN];
int main()
{
    ll n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        double a, b; cin >> a >> b;
        //cout << a << " " << b << "\n";
        ll a1 = floor(a);
        ll a2 = floor(b);
        input[a2][a1] = 1;
    }
    if(input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 0){
        dp[0][1][1][1]++;
        dp[0][0][0][1]++;
        dp[0][1][0][0]++;
    }
    else if(input[0][0] == 1 && input[1][0] == 0 && input[2][0] == 0){
        dp[0][0][1][1]++;
        dp[0][0][0][0]++;
    }
    else if(input[0][0] == 0 && input[1][0] == 1 && input[2][0] == 0){
        dp[0][1][0][1]++;
    }
    else if(input[0][0] == 0 && input[1][0] == 0 && input[2][0] == 1){
        dp[0][1][1][0]++;
        dp[0][0][0][0]++;
    }
    else if(input[0][0] == 1 && input[1][0] == 1 && input[2][0] == 0){
        dp[0][0][0][1]++;
    }
    else if(input[0][0] == 1 && input[1][0] == 0 && input[2][0] == 1){
        dp[0][0][1][0]++;
    }
    else if(input[0][0] == 0 && input[1][0] == 1 && input[2][0] == 1){
        dp[0][1][0][0]++;
    }
    else if(input[0][0] == 1 && input[1][0] == 1 && input[2][0] == 1){
        dp[0][0][0][0]++;
    }
    for(int i = 0; i <= 1; i++){
        for(int j =0; j <= 1; j++){
            for(int k = 0; k <= 1; k++){

                for(int i1 = 1; i1 >= 1 - i; i1--){
                    for(int j1 = 1; j1 >= 1 - j; j1--){
                        for(int k1 = 1; k1 >= 1 - k; k1--){
                            dp2[0][i][j][k] += dp[0][i1][j1][k1];
                            
                        }
                    }
                }
                //cout << 0 << " " << i << " " << j << " " << k << " " << dp[0][i][j][k] << " " << dp2[0][i][j][k] << "\n";
            }
        }
    }
    for(int i = 1; i < n; i++){
        if(input[0][i] == 0 && input[1][i] == 0 && input[2][i] == 0){
            for(int i1 = 0; i1 <= 1; i1++){
                for(int i2 = 0; i2 <= 1; i2++){
                    for(int i3 = 0; i3 <= 1; i3++){
                        dp[i][i1][i2][i3] += dp2[i - 1][i1][i2][i3];
                    }
                }
            }
            for(int i1 = 0; i1 <= 1; i1++){
                dp[i][i1][0][0] += dp2[i - 1][i1][1][1];
            }
            for(int i3 = 0; i3 <= 1; i3++){
                dp[i][0][0][i3] += dp2[i - 1][1][1][i3];
            }
        }
        else if(input[0][i] == 1 && input[1][i] == 0 && input[2][i] == 0){
            for(int i2 = 0; i2 <= 1; i2++){
                for(int i3 = 0; i3 <= 1; i3++){
                    dp[i][0][i2][i3] += dp2[i - 1][1][i2][i3];
                }
            }
            dp[i][0][0][0] += dp2[i - 1][1][1][1];
        }
        else if(input[0][i] == 0 && input[1][i] == 1 && input[2][i] == 0){
            for(int i2 = 0; i2 <= 1; i2++){
                for(int i3 = 0; i3 <= 1; i3++){
                    dp[i][i2][0][i3] += dp2[i - 1][i2][1][i3];
                }
            }
        }
        else if(input[0][i] == 0 && input[1][i] == 0 && input[2][i] == 1){
            for(int i2 = 0; i2 <= 1; i2++){
                for(int i3 = 0; i3 <= 1; i3++){
                    dp[i][i2][i3][0] += dp2[i - 1][i2][i3][1];
                }
            }
            dp[i][0][0][0] += dp2[i - 1][1][1][1];
        }
        else if(input[0][i] == 1 && input[1][i] == 1 && input[2][i] == 0){
            for(int i2 = 0; i2 <= 1; i2++){
                 dp[i][0][0][i2] += dp2[i - 1][1][1][i2];
            }
        }
        else if(input[0][i] == 1 && input[1][i] == 0 && input[2][i] == 1){
            for(int i2 = 0; i2 <= 1; i2++){
                 dp[i][0][i2][0] += dp2[i - 1][1][i2][1];
            }
        }
        else if(input[0][i] == 0 && input[1][i] == 1 && input[2][i] == 1){
            for(int i2 = 0; i2 <= 1; i2++){
                 dp[i][i2][0][0] += dp2[i - 1][i2][1][1];
            }
        }
        else if(input[0][i] == 1 && input[1][i] == 1 && input[2][i] == 1){
            dp[i][0][0][0] += dp2[i - 1][1][1][1];
        }
        for(int i0 = 0; i0 <= 1; i0++){
            for(int j =0; j <= 1; j++){
                for(int k = 0; k <= 1; k++){

                    for(int i1 = 1; i1 >= 1 - i0; i1--){
                        for(int j1 = 1; j1 >= 1 - j; j1--){
                            for(int k1 = 1; k1 >= 1 - k; k1--){
                                dp2[i][i0][j][k] += dp[i][i1][j1][k1];
                            }
                        }
                    }
                    //cout << i << " " << i0 << " " << j << " " << k << " " << dp[i][i0][j][k] << " " << dp2[i][i0][j][k] << "\n";

                }
            }
        }
    }
    cout << dp2[n - 1][1][1][1] << "\n";
}