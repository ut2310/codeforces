#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ll long long
ll M;
ll fact[MAXN];
ll invfact[MAXN];
ll choose(ll n, ll r)
{   
    ll res = 1;
    res *= fact[n];
    res *= invfact[r];
    res %= M;
    res *= invfact[n - r];
    res %= M;
    return res;
}
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2) % M;
    p = (p * p) % M;
    return (y % 2 == 0) ? p : (x * p) % M;
}
ll inverse(ll num)
{
    return power(num, M - 2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    fact[0] = 1; invfact[0] = 1;
    M = 998244353;
    for(int i = 1; i <= 1000002; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= M;
        invfact[i] = inverse(fact[i]);
    }
    //cerr << choose(3, 2) << "\n";
    while(t-->0)
    {
        ll l, n; cin >> l >> n;
        ll total = choose(l, 2 * n);
        total %= M;
        //l, l + 1
        ll left = l - 2 * n;
        ll complement = 0;
        for(int i = 0; i <= left; i+=2)
        {
            ll curr = choose(i/2 + n - 1, n - 1) * choose(n + left - i, n);
            curr %= M;
            complement += curr;
            complement %= M;
        }
        total -= complement;
        total *= 2;
        total %= M;
        if(total < 0) total += M;
        cout << total << "\n";

    }   
}