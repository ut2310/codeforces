using namespace std;
#include <bits/stdc++.h>
#define ll long long
ll M;
ll modInverse(ll A)
{
    return power(A, M - 2, M);
}
 
// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int M)
{
    if (y == 0)
        return 1;
 
    int p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
 
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
long long calcprob(ll n, ll k, ll i)
{
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll t; cin >> t;
    M = 1000000007;
    while(t-->0)
    {
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

    }
}
