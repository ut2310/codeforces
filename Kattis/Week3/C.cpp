using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
ll dp1[20][20];
ll freq[20][20];
ll total[20][20];
ll fact[20];
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2);
    p = (p * p);
 
    return (y % 2 == 0) ? p : (x * p);
}
ll countSetBits(ll n)
{
    if (n == 0)
        return 0;
    else
        return (n & 1) + countSetBits(n >> 1);
}
ll choose(ll a, ll b)
{
    if(a < b)
        return 0;
    else
       return fact[a]/(fact[b] * fact[a - b]);
}
int main()
{
    ll n; cin >> n;
    fact[0] = 1;
    for(int i = 1; i <= 19; i++){
        fact[i] = i * fact[i - 1];
    }
    ll edges = n * power(2, n - 1);
    for(int i = 0; i <= 19; i++){
        for(int j = 0; j <= 19; j++){
            dp1[i][j] = 1e18;
        }
    }
    for(int i = 0; i < edges; i++){
        ll u, v, w; cin >> u >> v >> w;
        ll a= countSetBits(u);
        ll b = countSetBits(v);
        freq[min(a, b)][max(a, b)]++;
        dp1[min(a, b)][max(a, b)] = min(dp1[min(a, b)][max(a, b)], w);
    }
    for(int i = 0; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            total[i][j] = choose(n - i, j - i) * choose(n, i);
            //cout << i << " " << j << " " << freq[i][j] << " " << total[i][j] << "\n";
        }
    }
    vector<pair<ll, ll>> dp(n + 1);
    for(int j = 1; j <= n; j++){
        ll curr = 1e18;
        ll currused = 1e18;
        for(int i = 0; i < j; i++){
            bool flag = true;
            if((freq[i][j] < total[i][j])){
                if((j - i) * (j - i) < dp1[i][j]){
                    if(dp[i].first + (j - i) * (j - i) < curr){
                        curr = dp[i].first + (j - i) * (j - i);
                        currused = dp[i].second + 1;
                    }
                    if(dp[i].first + (j - i) * (j - i) == curr){
                        currused = min(currused, dp[i].second + 1);
                    }
                }
                else{
                    if(dp[i].first + dp1[i][j] < curr){
                        curr = dp[i].first + dp1[i][j];
                        currused = dp[i].second;
                    }
                    if(dp[i].first + dp1[i][j] == curr){
                        currused = min(currused, dp[i].second);
                    }
                }
            }
            else{
                if(dp[i].first + dp1[i][j] < curr){
                    curr = dp[i].first + dp1[i][j];
                    currused = dp[i].second;
                }
                if(dp[i].first + dp1[i][j] == curr){
                    currused = min(currused, dp[i].second);
                }
            }
        }
        dp[j] = make_pair(curr, currused);
    }
    cout << dp[n].first << " " << dp[n].second << "\n";

    
}