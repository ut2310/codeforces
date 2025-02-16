using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
ll fact[MAXN], invfact[MAXN], M;
ll mod(ll a, ll b)
{
    if(a % b < 0)
    {
        return b + a % b;
    }
    return a % b;
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
int main()
{
    M = 998244353;
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1; i <= 200003; i++){
        fact[i] = fact[i - 1]* i;
        fact[i] = mod(fact[i], M);
        invfact[i] = modInverse(fact[i]);
    }
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> freq(n);
        for(int i = 0; i < n; i++){
            ll temp; cin >> temp;
            freq[temp]++;
        }
        vector<vector<ll>> dp(n);
        vector<vector<ll>> suffix(n);
        for(int i = 0; i < n; i++){
            vector<ll> vv(freq[i] + 1);
            vector<ll> v2(freq[i] + 1);
            dp[i] = v2;
            suffix[i] = vv;
        }
        for(int i = 1; i <= freq[0]; i++){
            dp[0][i] = (choose(freq[0], i));
        }
        ll track = 0;
        for(int i = freq[0]; i >= 1; i--){
            track += dp[0][i];
            track = mod(track, M);
            suffix[0][i] = track;
        }
        for(int i = 1; i < n; i++){
            dp[i].push_back(0);
            track = 0;
            ll s_track = 0;
            for(int j = freq[i]; j >= 1; j--){
                ll first = 0;
                ll second = 0;
                if(j <= freq[i - 1]){
                    first = choose(freq[i], j) * suffix[i - 1][j];
                    first = mod(first, M);
                    second = dp[i - 1][j] * track;
                    second = mod(second, M);
                }
                track += choose(freq[i], j);
                track = mod(track, M);
                dp[i][j] = first + second;
                dp[i][j] %= M;
                s_track += dp[i][j];
                s_track = mod(s_track, M);
                suffix[i][j] = s_track;
            }
        }
        ll res = 0;
        ll s_track = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = 1; j <= freq[i]; j++){
                ll value = dp[i][j] * j;
                value %= M;
                value *= power(2, s_track);
                value %= M;
                res += value;
                res = mod(res, M);
            }
            s_track += freq[i];
        }
        cout << res << "\n";
    }
}