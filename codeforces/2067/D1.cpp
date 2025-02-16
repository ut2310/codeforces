using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 10005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll fact[MAXN], invfact[MAXN], M;
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
    ll p = power(x, y /2) % M;
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
    for(int i = 1; i <= 10000; i++){
        fact[i] = fact[i - 1]* i;
        fact[i] = mod(fact[i], M);
        invfact[i] = modInverse(fact[i]);
    }
    ll t; cin >> t;
    while(t-->0){
        ll n, c, m; cin >> n >> c >> m;
        for(int i = 0; i < m; i++){
            ll temp; cin >> temp;
        }
        //cout << (m - c) << " " << c * (n - 1) << "\n";
        ll res = choose(c * (n - 1), m - c);
        res %= M;
        cout << res << "\n";
        
    }
}
