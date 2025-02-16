using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
vector<ll> SieveOfEratosthenes(int n, vector<ll> &primes)
{
    bool prime[n + 1];
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
    vector<ll> primes;
    SieveOfEratosthenes(1e6, primes);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll product = 1;
    ll ops = 0;
    for(auto p: primes){
        ll count = 0;
        vector<ll> temp;
        for(int i = 0; i < n; i++){
            ll cnt1 = 0;
            while(a[i] %p == 0){
                a[i]/=p;
                count++;
                cnt1++;
            }
            temp.push_back(cnt1);
        }
        ll target = count/n;
        for(int i = 0; i < n; i++){
            if(temp[i] < target){
                ops += target - temp[i];
            }
        }
        product *= pow(p, count/n);
    }
    cout << product << " " << ops << "\n";
}