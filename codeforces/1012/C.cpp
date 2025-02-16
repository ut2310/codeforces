#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ALPHABETSIZE 26
#define ll long long
ll dp[MAXN][MAXN][2];
int main()
{
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dp[1][1][0] = 1e18;
    dp[1][2][0] = 1e18;
    dp[1][2][1] = 1e18;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= (i + 1)/2; j++){
            //check if a[i - 1] is smaller than a[i - 2]
            if(a[i - 1] < a[i - 2]){
                // if(i == 4 && j == 1){
                //     cout << dp[i - 1][j][1] << " " << dp[i - 1][j][0] << "\n";
                // }
                dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j][0]);
                if(i % 2 == 1 && j == (i + 1)/2) dp[i][j][0] = 1e18;
                if(j >= 2){
                    dp[i][j][1] = max(abs(a[i - 1] - a[i - 2]), a[i -2] - a[i - 3]) + 1 + min(dp[i - 2][j - 1][0], dp[i - 2][j - 1][1]);
                }
                else{
                    dp[i][j][1] = abs(a[i - 1] - a[i - 2]) + 1;
                }
            }
            else if(a[i - 1] == a[i - 2]){
                if(i/2 < j){
                    dp[i - 1][j][0] = 1e18;
                    dp[i - 1][j][1] = 1e18;
                }
                dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
                if(i % 2 == 1 && j == (i + 1)/2) dp[i][j][0] = 1e18;
                if(j >= 2){
                    dp[i][j][1] = max(abs(a[i - 1] - a[i - 2]), a[i - 2] - a[i - 3]) + 1 + min(dp[i - 2][j - 1][0], dp[i - 2][j - 1][1]);
                }
                else{
                    dp[i][j][1] = abs(a[i - 1] - a[i - 2]) + 1;
                }
            }
            else{
                // last element is bigger than second to last
                dp[i][j][1] = dp[i - 1][j - 1][0];
                if(i/2 < j){
                    dp[i - 1][j][0] = 1e18;
                    dp[i - 1][j][1] = 1e18;
                }
                dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + abs(a[i - 1] - a[i - 2]) + 1);
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= (i + 1)/2; j++){
    //         cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << "\n";
    //     }
    // }
    for(int i = 1; i <= (n + 1)/2; i++){
        cout << min(dp[n][i][0], dp[n][i][1]) << " ";
    }
    cout << "\n";


}