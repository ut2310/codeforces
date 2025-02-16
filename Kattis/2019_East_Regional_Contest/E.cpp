using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 505
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dp[MAXN][MAXN][11], r, c, n;
bool validate(ll x, ll y, vector<vi> &input)
{
    if(x <= 0 || x >= r + 1 || y <= 0 || y >= c + 1){
        return false;
    }
    if(input[x][y] == -1){
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> r >> c >> n;
    vector<vi> input(r + 1, vi(c + 1));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> input[i][j];
        }
    }
    vector<vi> isPass(r + 1, vi(c + 1));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(i == 5 && j == 3){
                //cerr << "chicken2\n";
            }
            if(validate(i, j - 1, input) && validate(i, j + 1, input) && validate(i - 1, j, input) && validate(i + 1, j, input)){
                if(i == 5 && j == 3){
                    //cerr << "chicken2\n";
                }
                if(input[i + 1][j] > input[i][j] && input[i - 1][j] > input[i][j] && input[i][j + 1] < input[i][j] && input[i][j - 1] < input[i][j]){
                    isPass[i][j] = 1;
                    
                }
            }
            //cerr << i << " " << j << "\n";
        }
       
    }
    //cerr << "chicken\n";
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= r; j++){
            for(int k = 0; k <= n; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    //cerr << "chicken\n";
    for(int i = 1; i <= r; i++){
        dp[1][i][0] = input[i][1]; 
    }
    
    for(int i = 2; i <= c; i++){
        for(int j = 1; j <= r; j++){
            for(int k = 0; k <= n; k++){
                if(isPass[j][i] == 1){
                    if(k == 0){
                        continue;
                    }
                    //look at [j][i - 1], [j + 1][i - 1], [j - 1][i - 1]
                    for(int j1 = -1; j1 <= 1; j1++){
                        if(validate(j + j1, i - 1, input) && dp[i - 1][j + j1][k - 1] != -1){
                            if(dp[i][j][k] == -1){
                                dp[i][j][k] = dp[i - 1][j + j1][k - 1] + input[j][i];
                            }
                            else{
                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + j1][k - 1] + input[j][i]);
                            }
                        }
                    }
                }
                else{
                    for(int j1 = -1; j1 <= 1; j1++){
                        if(validate(j + j1, i - 1, input) && dp[i - 1][j + j1][k] != -1){
                            if(dp[i][j][k] == -1){
                                dp[i][j][k] = dp[i - 1][j + j1][k] + input[j][i];
                            }
                            else{
                                 dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + j1][k] + input[j][i]);
                            }
                        }
                    }
                }
                //cerr << i << " " << j << " " << k << " " << dp[i][j][k] << "\n";
            }
        }
    }
    ll res = 1e18;
    for(int i = 1; i <= r; i++){
        if(dp[c][i][n] != -1){
            res = min(res, dp[c][i][n]);
        }
    }
    if(res == 1e18){
        cout << "impossible\n";
    }
    else{
        cout << res << "\n";
    }
}