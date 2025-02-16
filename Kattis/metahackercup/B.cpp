using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 10000005
#define ALPHABETSIZE 26
#include <cstdio>
ll dp[MAXN];
vector<bool> SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1);
    for(int i = 1; i <= n; i++){
        prime[i] = true;
    }
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}
int main()
{
    freopen("prime_subtractorization_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    vector<bool> prime = SieveOfEratosthenes(10000005);
    dp[4] = 1;
    for(int i = 5; i <= 10000000; i++){
        if(prime[i] && prime[i - 2]){
            dp[i] = dp[i - 1] + 1;
        }
        else{
            dp[i] = dp[i - 1];
        }
    }
    dp[4] = 0;
    for(int j = 1; j <= t; j++)
    {
        ll n; cin >> n;
        cout << "Case #" << j << ": " << dp[n] << "\n";
    }
}