using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1005
ll M, fact[MAXN], invfact[MAXN];
ll dp[505][505];
ll mod(ll a, ll b)
{
    if(a % b < 0)
    {
        return b + a % b;
    }
    return a % b;
}
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
ll modInverse(ll A)
{
    return power(A, M - 2);
}
ll choose(ll a, ll b)
{
    if(a < b)
    {
        return 0;
    }
    else
    {
        ll res = mod((fact[a] * invfact[b]), M);
        res = mod((res * invfact[a - b]), M);
        return res;
    }
}
ll f(ll n, ll j)
{
    //cout << choose(n, n/2 - j) << " " << choose(n, n/2 - j - 1) << "\n";
    return mod(choose(n, n/2 - j) - choose(n, n/2 - j - 1), M);
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    M = 998244353;
    ll n, m; cin >> n >> m;
    //cout << choose(2, 0) << "\n";
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1; i <= 500; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= M;
        invfact[i] = modInverse(fact[i]);
    }
    for(int i = 0; i <= m/2; i++){
        dp[1][i] = f(m, i);
    }
    for(int i = 2; i <= n - 1; i++){
        for(int j = 0; j <= m/2; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] += dp[i - 1][j - k] * f(m, k);
                dp[i][j] %= M;
            }
        }
    }
    ll res = 0;
    for(int j = 0; j <= m/2; j++){
        //cout << n - 1 << " " << j << " " << dp[n - 1][j] << "\n";
        res += dp[n - 1][j] * f(m, j);
        res %= M;
    }
    res = mod(res, M);
    if(n == 1){
        res = f(m, 0);
        res = mod(res, M);
    }
    cout << res << "\n";    
}