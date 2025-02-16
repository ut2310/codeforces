using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 205
ll dp[MAXN][MAXN][MAXN];
ll store[MAXN][MAXN];
ll arr[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m, k; cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
            for(int j = 1 ; j <= m; j++){
                cin >> arr[i][j];
                store[i][j] = 1e18;
                for(int k = 0; k < m; k++){
                    dp[i][j][k] = 1e18;
                }
            }
        }
        //base case: row (i, 1)
        for(int i = 1; i <= n; i++){
            for(int b = 0; b < m; b++){
                ll lookAt = (1 + b) % m;
                if(lookAt == 0) lookAt = m;
                dp[i][1][b] = store[i - 1][1] + arr[i][lookAt];
                store[i][1] = min(store[i][1], dp[i][1][b] + b * k);
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 2; j <= m; j++){
                for(int b = 0; b < m; b++){
                    ll lookAt = (j + b) % m;
                    if(lookAt == 0) lookAt = m;
                    if(i == 1){
                        dp[i][j][b] = dp[i][j - 1][b] + arr[i][lookAt];
                        store[i][j] = min(store[i][j], dp[i][j][b] + b * k);
                    }
                    else{
                        dp[i][j][b] = min(dp[i][j - 1][b] + arr[i][lookAt], store[i - 1][j] + arr[i][lookAt]);
                        store[i][j] = min(store[i][j], dp[i][j][b] + b * k);
                    }
                    
                }
            }
        }
        cout << store[n][m] << "\n";
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                //cout << store[i][j] << " ";
                store[i][j] = 0;
                arr[i][j] = 0;
                for(int b = 0; b <= m; b++){
                    dp[i][j][b] = 0;
                }
            }
            //cout << "\n";
        }
    }
}