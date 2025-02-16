using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
ll M;
ll fact[MAXN];  
ll invfact[MAXN];
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
    for(int i = 1; i <= 100003; i++){
        fact[i] = fact[i - 1]* i;
        fact[i] = mod(fact[i], M);
        invfact[i] = modInverse(fact[i]);
    }
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> ps(n + 1);
    vector<ll> digit(n + 1);
    for(int i = 1; i <= n; i++){
        digit[i] = s[i - 1] - '0';
        ps[i] = ps[i - 1] + digit[i];
    }
    ll res = 0;
    for(int i = 0; i <= n - k - 1; i++){
        ll temp = 0;
        temp += ps[n - i - 1] * choose(n - i - 2, k - 1);
        temp %= M;
        temp += digit[n - i] * choose(n - i - 1, k);
        temp %= M;
        temp *= power(10, i);
        temp %= M;
        res += temp;
        res %= M;
    }
    cout << res << "\n";
}
