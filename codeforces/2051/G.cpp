using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 20
ll edges[MAXN][MAXN];
ll shrinks[MAXN];
ll large[MAXN];
ll dp[1 << MAXN][MAXN];
int main()
{
    ll n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            edges[i][j] = 1;
        }
    }
    while(q-->0){
        ll num; char c; 
        cin >> num >> c;
        num--;
        if(c == '+'){
            large[num]++;
            ll x  = num;
            for(int y = 0; y < n; y++){
                edges[x][y] = max(edges[x][y], large[x] - shrinks[y] + 1);
            }
        }
        else{
            shrinks[num]++;
            ll y = num;
            for(int x = 0; x < n; x++){
                edges[x][y] = max(edges[x][y], large[x] - shrinks[y] + 1);
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << edges[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 1; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(!(i ^ (1 << j))){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = 1e18;
            if((1 << j) & i){
                for(int j1 = 0; j1 < n; j1++){
                    if(j1 != j){
                        if(i ^ (1 << j1)){
                            dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][j1] + edges[j1][j]);
                        }
                    }
                }
            }
            //cout << i << " " << j << " " << dp[i][j] << "hi\n";
        }
    }
    ll res = 1e9;
    for(int i = 0; i < n; i++){
        res = min(res, dp[(1 << n) - 1][i] + large[i]);
    }
    cout << res << "\n";

}