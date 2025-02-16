using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll M;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n; M = 998244353;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<ll> primes;
    SieveOfEratosthenes(1e3, primes);
    vector<ll> dp(n + 1);
    vector<ll> ps(1e6 + 5);
    vector<ll> temp;
    for(auto j: primes){
        if(a[1] % j == 0){  
            temp.push_back(j);
        }
        while(a[1] % j == 0){
            a[1]/=j;
        }
        if(a[1] == 1) break;
    }
    if(a[1] > 1){
        temp.push_back(a[1]);
    } 
    for(int i = 1; i < (1 << temp.size()); i++){
        ll curr = 1;
        for(int j = 0; j < temp.size(); j++){
            if(i & (1 << j)){
                curr *= temp[j];
            }
        }
        ps[curr]++;
    }
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        temp.clear();
        for(auto j: primes){
            if(a[i] % j == 0){  
                temp.push_back(j);
            }
            while(a[i] % j == 0){
                a[i]/=j;
            }
        }
        if(a[i] > 1){
            temp.push_back(a[i]);
        }
        for(int i1 = 1; i1 < (1 << temp.size()); i1++){
            ll curr = 1;
            ll cnt = 0;
            for(int j = 0; j < temp.size(); j++){
                if(i1 & (1 << j)){
                    curr *= temp[j];
                    cnt++;
                }
            }
            if(cnt % 2 == 0){
                dp[i] -= ps[curr];
                dp[i] %= M;
            } 
            else{
                dp[i] += ps[curr];
                dp[i] %= M;
            } 
        }
        //cout << i << " " << dp[i] << "\n";
        for(int i1 = 1; i1 < (1 << temp.size()); i1++){
            ll curr = 1;
            for(int j = 0; j < temp.size(); j++){
                if(i1 & (1 << j)){
                    curr *= temp[j];
                }
            }
            ps[curr]+=dp[i];
            ps[curr] %= M;
        }
    }
    dp[n] %= M;
    if(dp[n] < 0) dp[n] += M;
    cout << dp[n] << "\n";

}