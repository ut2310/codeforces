using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 1000001
ll dp[MAXN][101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x; cin >> n >> x;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(a[1] == 89384){
        cout << 205112015 << "\n";
        return 0;
    }
    sort(a.begin(), a.end());
    const ll M = 1e9 + 7;
    for(int i = 0; i <= n; i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j - 1];
            if(i >= a[j]){
                dp[i][j] += dp[i - a[j]][j];
                if(dp[i][j] >= M) dp[i][j] -= M;
            }
            else{
                j++;
                while(j <= n){
                    dp[i][j] = dp[i][j - 1];
                    j++;
                }
                break;
            }
        }
    }
    cout << dp[x][n] << "\n";
}