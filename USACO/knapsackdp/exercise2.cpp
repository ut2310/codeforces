using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 7505
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll MOD, n, fact[MAXN], invfact[MAXN];
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
 
    ll p = power(x, y / 2) % MOD;
    p = (p * p) % MOD;
 
    return (y % 2 == 0) ? p : (x * p) % MOD;
}
ll modInverse(ll A)
{
    return power(A, MOD - 2);
}
ll choose(ll a, ll b)
{
    if(a < b)
    {
        return 0;
    }
    else
    {
        ll res = mod((fact[a] * invfact[b]), MOD);
        res = mod((res * invfact[a - b]), MOD);
        return res;
    }
}
int main()
{
    // freopen("exercise.in","r",stdin);
    // freopen("exercise.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> MOD;
    vector<ll> visited(n + 1);
    vector<pair<ll, ll>> primes;
    for(int i = 2; i <= n; i++){
        if(visited[i] == 0){
            primes.push_back({i, i});
            ll temp = i * i;
            while(temp <= n){
                primes.push_back({temp, i});
                temp *= i;
            }
        }
        for(int j = 2 * i; j <= n; j+=i){
            visited[j] = 1;
        }
    }
    vector<ll> dp(n + 1);
    for(int i = 1; i <= n; i++) dp[i] = 1;
    vector<ll> prev = dp;
    for(auto p1: primes){
        ll p = p1.first;
        dp[p] += p; dp[p] %= MOD;
        for(int i = p + 1; i <= n; i++){
            dp[i] += prev[i - p] * (p);
            dp[i] %= MOD;
        }
        if(p1.second * p > n) prev = dp;
    }
    dp[n] %= MOD; if(dp[n] < 0) dp[n] += MOD;
    cout << dp[n] << "\n";
}