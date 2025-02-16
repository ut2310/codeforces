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
ll MOD, n, fact[MAXN][MAXN];
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
int main()
{
    freopen("exercise.in","r",stdin);    
    freopen("exercise.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> MOD;
    vector<ll> visited(n + 1);
    vector<pair<ll, ll>> primes;
    MOD -= 1;
    for(int i = 0; i <= n; i++){
        fact[i][0] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            fact[i][j] = fact[i][j - 1] * (i - j + 1);
            fact[i][j] %= MOD;
        }
    }
    for(int i = 2; i <= n; i++){
        if(visited[i] == 0){
            primes.push_back({i, i});
            ll temp = i * i;
            while(temp <= n){
                primes.push_back({temp, i});
                temp *= i;
            }
        }
        for(int j = i; j <= n; j+=i){
            visited[j] = 1;
        }
    }
    //consider c(n, p) = loop through
    ll res = 1;
    for(auto p1: primes){
        ll p = p1.first;
        vector<ll> dp(n + 1);
        dp[p] = fact[p - 1][p - 1];
        ll transition = 0;
        for(ll i = p + 1; i <= n; i++){
            transition *= (i - 1);
            transition %= MOD;
            transition += (dp[i - 1]);
            transition %= MOD;
            dp[i] += transition;
            dp[i] %= MOD;

            for(ll j = p; j <= i; j+=p){
                ll get = fact[i - 1][j - 1]; //fact[i - 1][(j - 1)]
                get %= MOD;
                //cout << i << " " << j << " " << get << fact[n - j] << " " << dp[n - j] << "\n";
                get *= (fact[i - j][i - j] - dp[i - j]);
                get %= MOD; if(get < 0) get += MOD;
                dp[i] += get;
                dp[i] %= MOD;
                //cout << i << " " << j << " " << get << "\n";
            }
        }
        MOD += 1;
        res *= power(p1.second, dp[n]);
        res %= MOD; if(res < 0) res += MOD;
        MOD -= 1;
        // for(int i = 1; i <= n; i++){
        //     cout << p << " " << dp[i] << "\n";
        // }
        // cout << "\n";
    }
    cout << res << "\n";
    //cout.flush();


}