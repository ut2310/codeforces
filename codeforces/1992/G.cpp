using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 10005
ll fact[MAXN];
ll invfact[MAXN];
ll M;
ll power(ll x, ll y, ll M)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
ll modInverse(ll A)
{
    return power(A, M - 2, M);
}
ll choose(ll a, ll b)
{
    if(a < b || a < 0 || b < 0) return 0;
    if(a == b || b == 0) return 1;
    ll res = fact[a] * invfact[a - b];
    res %= M;
    res *= invfact[b];
    res %= M;
    if(res < 0) res += M;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll t; cin >> t;
    M = 1000000007;
    fact[0] = 1;
    for(int i = 1; i < 10005; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= M;
        if(fact[i] < 0) fact[i] += M;
    }
    for(int i = 1; i < 10005; i++)
    {
        invfact[i] = modInverse(fact[i]);
        invfact[i] %= M;
        if(invfact[i] < 0) invfact[i] += M;
    }
    //cout << choose(3, 2) << "\n";
    while(t-->0)
    {
        ll n; cin >> n;
        ll res = 1;
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= 2 * i + 1; j++)
            {
                ll choose_from = min(n, j - 1);
                ll leftovers = j - 1 - i;
                ll other = 1;
                if(j < n)
                {
                    ll choose_from_2 = n - j;
                    ll leftover = 2 * i - j + 1;
                    other = choose(choose_from_2, leftover);
                    //cout << i << " " <<  j << " " << choose_from_2 << " " << leftover << "\n";
                }
                
                if(j >= n && leftovers != i) other = 0;
                //cout <<choose_from << " " << leftovers << " " <<  i << " " << j << " " << choose(choose_from, leftovers) << " " << other << "\n";;
                ll total = choose(choose_from, leftovers) * other;
                total %= M;
                res += total * j;
                res = res % M;

            }
        }
        if(res < 0)
        {
            res += M;
        }
        cout << res << "\n";
    }
}