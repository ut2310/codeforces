using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 5005
ll dpa[MAXN][MAXN];
ll dpb[MAXN][MAXN];
ll dp[MAXN][MAXN];
ll dp2[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    ll prev = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            cnt++;
        }
        if(a[i] != 0){
            if(a[i] > 0 && a[i] <= cnt){
                dpa[cnt][a[i]]++;
            }
            if(a[i] < 0 && abs(a[i]) <= cnt){
                dpb[cnt][cnt + a[i]]++;
            }
        }
    }
    // for(int i = 1; i <= m; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << dpa[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= i; j++){
            dpa[i][j] += dpa[i][j - 1];
        }
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = m - 1; j >= 0; j--){
            dpb[i][j] += dpb[i][j + 1];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = dpa[i][j] + dpb[i][j];
        }
    }
    // for(int i = 1; i <= m; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    //cerr << "chicken\n";
    for(int i = 0; i <= 1; i++){
        dp2[1][i] = dp[1][i];
    }
    // for(int i = 1; i <= m; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 2; i <= m; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                //cout << dp2[i - 1][j] << " " << dp[i][j] << "\n";
                dp2[i][j] = dp2[i - 1][j] + dp[i][j];
            }
            else if(j == m){
                dp2[i][j] = dp2[i - 1][j - 1] + dp[i][j];
            }
            else{
                dp2[i][j] = dp[i][j] + max(dp2[i - 1][j], dp2[i - 1][j - 1]);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i <= m; i++){
        res = max(res, dp2[m][i]);
    }
    cout << res << "\n";
    // for(int i = 1; i <= m; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << dp2[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

}