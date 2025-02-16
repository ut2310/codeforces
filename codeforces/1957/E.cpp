#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, vector<ll>> pf;
ll M;
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) 
        {
            for (int i = p; i <= n; i += p)
            {
                pf[i].push_back(p);
                if(i != p) prime[i] = false;
            }
        }
    }
}
int main()
{
    M = 1000000007;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    SieveOfEratosthenes(1e6 + 5);
    vector<ll> dp(1e6 + 5);
    vector<ll> dp2(1e6 + 6);
    dp[1] = 0;
    dp[2] = 1;
    dp2[2] = 1;
    for(int i = 3; i <= 1e6; i++)
    {
        dp2[i] = dp2[i - 1];
        for(auto p: pf[i])
        {   
            ll curr = (i - 1)/p;
            if(curr % p != 0) dp2[i]--;
            else dp2[i] += p - 1;
            dp2[i] %= M;
        }
        if(i % 8 == 0) dp2[i] -= 2;
        else if(i % 4 == 0) dp2[i] += 2;
        dp2[i] %= M;
        dp[i] = dp[i - 1] + dp2[i];
        dp[i] %= M;
    }

    while(t-->0)
    {
        ll n; cin >> n;
        if(dp[n] < 0) dp[n] += M;
        cout << dp[n] << "\n";

    }
}