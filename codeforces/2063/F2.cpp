using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 600005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll M, fact[MAXN], invfact[MAXN], catalan[MAXN];
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
    M = 998244353;
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1; i <= 600000; i++){
        fact[i] = fact[i - 1]* i;
        fact[i] = mod(fact[i], M);
        invfact[i] = modInverse(fact[i]);
        
    }
    for(int i = 2; i <= 600000; i+=2){
        catalan[i] = choose(i, i/2) * modInverse(i/2 + 1);
        catalan[i] %= M;
        //if(i <= 10) cout << catalan[i] << " ";
    }
    cout << "\n";
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> res(n + 1);
        res[0] = catalan[2 * n];
        
        for(int i = 0; i <= n; i++){
            if(res[i] < 0) res[i] += M;
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}