#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ALPHABETSIZE 26
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, d, k; cin >> n >> d >> k;
        vector<ll> start(n + 1);
        vector<ll> end(n + 1);
        ll initial = 0;
        for(int i = 0; i < k; i++){
            ll l, r; cin >> l >> r;
            start[l]++;
            end[r]++;
            if(l <= d) initial++;
        }
        vector<ll> dp(n + 1);
        dp[d] = initial;
        for(int i = d + 1; i <= n; i++){
            dp[i] = dp[i - 1] - end[i - d] + start[i];
        }
        // for(int i = d; i <= n; i++){
        //     cout << dp[i] << " "; 
        // }
        // cout << "\n";
        ll mom = 1e18;
        ll bro = -1;
        ll res1 = -1;
        ll res2 = -1;
        for(int i = d; i <= n; i++){
            if(mom > dp[i]){
                mom = dp[i];
                res2 = i;
            }
            if(dp[i] > bro){
                bro = dp[i];
                res1 = i;
            }
        }
        cout << res1 - d + 1 << " " << res2 - d + 1 << "\n";
    }
}