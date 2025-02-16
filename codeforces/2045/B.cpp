using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000005
bool prime[MAXN];
vector<ll> SieveOfEratosthenes(int n, vector<ll> &primes)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
    return primes;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, d, s; cin >> n >> d >> s;
    vector<ll> primes;
    SieveOfEratosthenes(1e6 + 2, primes);
    ll res = s;
    for(auto i: primes){
        ll mult = s * i;
        ll low = 0;
        if(mult > n) break;
        ll high = (n/(s * i));
        while(low < high){
            ll mid = (low + high + 1)/2;
            if(s * (i - 1) * mid <= d){
                low = mid;
            }
            else{
                high = mid - 1;
            }
        }
        res = max(res, low * mult);
        //cout << i << " " << res << "\n";
    }
    //cout << res << "\n";
    ll most_p = min(d/s + 1, n/s);
    res = min(res, most_p * s);
    cout << res << "\n";
}