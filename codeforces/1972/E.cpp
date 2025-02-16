using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    M = 998244353;
    fact[0] = 1;
    for(int i = 1; i < 200005; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= M;
        if(fact[i] < 0) fact[i] += M;
    }
    for(int i = 1; i < 200005; i++)
    {
        invfact[i] = modInverse(fact[i]);
        invfact[i] %= M;
        if(invfact[i] < 0) invfact[i] += M;
    }
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, k; cin >> n >> k;
        vector<ll> b(n + 1);
        vector<ll> a(n + 1);
        vector<ll> precompute(35);
        precompute[0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        for(int i = 1; i <= 30; i++)
        {
            ll mult  = (k + i - 1 ) % M;
            precompute[i] = precompute[i - 1] * (mult);
            precompute[i] %= M;
            if(precompute[i] < 0) precompute[i] += M;
            //cout << precompute[i] << "\n";
        }
        ll curr = 1;
        ll increment = 2;
        ll base_choose = 0;
        vector<ll> denom(n + 1);
        while(curr <= n)
        {
            for(int i = curr; i <= n; i += increment)
            {
                if(i % 2 == 1) 
                {
                    denom[i]++;
                    a[i] = b[i];
                }
                else
                {   
                    a[i] = b[i];
                  
                    for(int j = i - (increment/2) + 1; j < i; j++)
                    {
                        ll curr_choose = denom[j]; //1 - (curr - 1)
                        denom[j]++;
                        ll sub = invfact[curr_choose]*precompute[curr_choose];
                        
                        sub %= M;
                        sub *= a[j];
                        sub %= M;
                        
                        if(sub < 0) sub += M;
                        a[i] -= sub; 
                        a[i] %= M;
                        if(a[i] < 0) a[i] += M;
                        //cerr << i << " " << sub << " " << j << "\n";
                    }
                    denom[i]++;
                }
                //cerr << curr << " " << i << "\n";
            }
            curr *= 2;
            increment *= 2;
            base_choose++;
        }
        for(int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}