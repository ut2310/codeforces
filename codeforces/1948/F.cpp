using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000005
ll M;
ll fact[MAXN];
ll invfact[MAXN];
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
    ll n, q; cin >> n >> q;
    M = 998244353;
    fact[0] = 1;
    for(int i = 1; i < 1000005; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= M;
        if(fact[i] < 0) fact[i] += M;
    }
    for(int i = 1; i < 1000005; i++)
    {
        invfact[i] = modInverse(fact[i]);
        invfact[i] %= M;
        if(invfact[i] < 0) invfact[i] += M;
    }
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<ll> goldps(n + 1);
    vector<ll> silverps(n + 1);
    for(int i = 1; i <= n; i++)
    {
        goldps[i] = goldps[i - 1] + a[i - 1];
        silverps[i] = silverps[i - 1] + b[i - 1];
    }
    ll totals = silverps[n];
    ll totalg = goldps[n];
    vector<ll> ps(totals + 1);
    ll inverseMultipler = modInverse(power(2, totals, M));
    for(int i = 0; i <= totals; i++)
    {
        if(i == 0) ps[i] = 1;
        else
        {
            ps[i] = ps[i - 1] + choose(totals, i);
            ps[i] %= M;
            if(ps[i] < 0) ps[i] += M;
        }
        //cout << i << " " << ps[i] << " " << totals << "\n";
    }
    for(int i = 0; i < q; i++)
    {
        ll l, r; cin >> l >> r;
        ll cs = silverps[r] - silverps[l - 1];
        ll cg = goldps[r] - goldps[l - 1];
        ll os = totals - cs;
        ll og = totalg - cg;
        if(cs + cg > og)
        {
            ll k = og - cg + 1;
            ll num = min(totals, cs - k);
            //cout << ps[num] << "\n";
            ll res = ps[num] * inverseMultipler;
            res %= M;
            if(res < 0) res += M;
            cout << res << "\n";

        } 
        else
        {
            cout << "0\n";
        }
    }
}