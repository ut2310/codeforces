using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dp[10][MAXN];
ll cnt[MAXN], M, invfact[MAXN], fact[MAXN];
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
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    M = 1e9 + 7;
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1; i <= 300003; i++){
        fact[i] = fact[i - 1]* i;
        fact[i] = mod(fact[i], M);
        invfact[i] = modInverse(fact[i]);
    }
    ll n; cin >> n;
    set<ll> a;
    ll most = 0;
    ll track = 0;
    for(int i = 0; i < n; i++){
        ll temp; cin >> temp; a.insert(temp);
        most = max(most, temp);
        track = __gcd(track, temp);
    }
    // for(auto j: a){
    //     cout << j << " ";
    // }
    // cout << "\n";
    // cerr << track << "\n";
    if(track > 1){
        cout << "-1\n";
        return 0;
    }
    for(ll i = 1; i <= most; i++){
        for(ll j = i; j <= most; j+= i){
            cnt[i] += a.count(j);
        }
        //cerr << i << " " << cnt[i] << "\n";
    }
    for(ll i = most; i >= 1; i--){
        for(ll j = 1; j <= 8; j++){
            dp[j][i] += choose(cnt[i], j);
            dp[j][i] %= M;
            for(ll j1 = i * 2; j1 <= most; j1 += i){
                dp[j][i] -= dp[j][j1];
                dp[j][i] %= M;
            }
        }
    }
    ll res = -1;
    for(ll j = 1; j <= 8; j++){
        if(dp[j][1] < 0) dp[j][1] += M;
        if(dp[j][1] > 0) {
            res = j; break;
        }
    }
    cout << res << "\n";
}